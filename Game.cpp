/***********************************************************************
 * File: Game.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/06/14
 * Description: This C++ program is Pokemon Game Manager
***********************************************************************/
#include "Game.h"
#include "DataFormat.h"
#include "Potion.h"
#include <QApplication>
#include <QFileDialog>
#include <fstream>
#include <QTemporaryFile>
#include <filesystem>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSoundEffect>
#include <random>

//Game Constructor

Game::Game()
{
    isTestMode = false;
    this->effect.setVolume(1.f);
    effect.setSource(QUrl::fromLocalFile(loadSound));
    effect.setLoopCount(QSoundEffect::Infinite);
    effect.play();
    turnNumber = 1;
    playable = true;
}
//Game Destructor
Game::~Game()
{

}
/**
 * Intent: Execute command for QString
 * Pre:
 * Pos:return true or false
 */
bool Game::executeCommand(QString command)
{
    isRand = true;
    string stdString = command.toStdString();
    if(executeCommand(stdString))
    {
        return true;
    }
    std::cout<<"failed"<<endl;
    return false;
}

/**
 * Intent: Execute command
 * Pre:
 * Pos:return true or false
 */
bool Game::executeCommand(string command)
{
    cout<<command<<endl;
    if(command == "TestCase")
    {
        stringstream commandStream(command);
        string fileName;
        commandStream>>fileName;
        loadTestCase(fileName);
        return true;
    }
    if(command.empty())
    {
        return false;
    }
    if(pokemons.empty())
    {
        DataFormat data;
        data.loadPokemonData(command,this);
        if(pokemons.empty())cout<<"Load Faild PokemonData"<<endl;
        return true;
    }
    if(moves.empty())
    {
        DataFormat data;
        data.loadMoveData(command,this);
        if(moves.empty())cout<<"Load Faild MoveData"<<endl;
        return true;
    }
    if(players.empty())
    {
        DataFormat data;
        data.loadGameData(command,this);
        if(players.empty())cout<<"Load Faild GameData"<<endl;
            currentTurn = (players[PLAYER_TURN].pokemons[players[PLAYER_TURN].currentPokemon].getSpeed() >
                           players[OPPONENT_TURN].pokemons[players[OPPONENT_TURN].currentPokemon].getSpeed()) ?
                              PLAYER_TURN : OPPONENT_TURN;
            if(currentTurn == OPPONENT_TURN&&isRand )randomMove();
        return true;
    }
    currentTurn = (players[PLAYER_TURN].pokemons[players[PLAYER_TURN].currentPokemon].getSpeed() >
                   players[OPPONENT_TURN].pokemons[players[OPPONENT_TURN].currentPokemon].getSpeed()) ?
                      PLAYER_TURN : OPPONENT_TURN;
    //Error Proof
    try
    {
        if(command == "Pokemon"||pokemonTimes)
        {
            // Swap Pokemon.
            if(!pokemonTimes)
            {
                swapPokemon(currentTurn,"");
            }
            else if(pokemonTimes == 1)
            {
                swapPokemon(currentTurn,command);
            }
            else if(pokemonTimes == 2)
            {
                if(!useMove(command, !currentTurn, isTestMode))
                {
                    return false;
                }
            }
            // Attack from second players.
            pokemonTimes++;
            if(flag)
            {
                flag = false;
                pokemonTimes = 0;
            }
            if(pokemonTimes==3)
            {
                pokemonTimes = 0;
                emit updatePokemonInfo();
                turnNumber++;
            }
        }
        else if (command == "Bag" || bagTimes)
        {
            // Use potion.
            useBag();

            // Attack from second players.
            string command2;
            cin >> command2;
            if(useMove(command2, !currentTurn, isTestMode))
            {
                return false;
            }

            turnNumber++;
        }
        else if(command == "Battle" || battleTimes)
        {
            if(battleTimes == 1)
            {
                if(!useMove(command, currentTurn, isTestMode))
                {
                    return false;
                }
            }
            else if(battleTimes == 2)
            {
                if(!useMove(command, !currentTurn, isTestMode))
                {
                    return false;
                }
            }
            battleTimes++;
            if(battleTimes==2&&currentTurn!=OPPONENT_TURN&&isRand)
            {
                randomMove();
            }
            emit updatePokemonInfo();
            if(battleTimes == 3)
            {
                // B & P.
                bAndP();
                emit updatePokemonInfo();
                battleTimes=0;
                turnNumber++;
            }
        }
        else if(command == "Check")
        {
            check();
        }
        else if(command == "Status")
        {
            status(currentTurn);
        }
        else if(command == "Run")
        {
            playable = false;
        }
        else if(command == "Test")
        {
            isTestMode = true;
        }
    }
    catch(int failed)
    {
        cout << "Failed" << endl;
        return false;
    }

    return true;
}

// Intent:  To mange one turn of battle process.
// Pre:     None.
// Post:    The function executed a turn.
void Game::battle(string command, bool currentTurn, bool testMode)
{
    // Including first Pokemon damage calculation.
    useMove(command, currentTurn, isTestMode);
}

// Intent:  To find input Pokemon's index.
// Pre:     Player's pokemons must have been initialised.
// Post:    The function returns index if found, otherwise returns -1.
int Game::findPokemon(bool turn, string pokemonName)
{
    for (int i = 0; i < players[turn].pokemons.size(); i++)
    {
        if (players[turn].pokemons[i].getName() == pokemonName)
        {
            return i;
        }
    }

    return -1;
}

// Intent:  To find input Pokemon's move index.
// Pre:     aPokemon's move must have been initialised.
// Post:    The function returns index if found, otherwise returns -1.
int Game::findMove(Pokemon &aPokemon, string moveName)
{
    for (int i = 0; i < aPokemon.getMoves().size(); i++)
    {
        if (aPokemon.getMoves()[i].getName() == moveName)
        {
            return i;
        }
    }

    return -1;
}
vector<string> Game::findAvailablePokemon(int turn)
{
    vector<string> pokemons;
    for (int i = 0; i < players[turn].pokemons.size(); i++)
    {
        if (players[turn].pokemons[i].getHp() > 0)
        {
            pokemons.push_back(players[turn].pokemons[i].getName());
        }
    }
    return pokemons;
}

// Intent:  To swap Pokemon.
// Pre:     None.
// Post:    The function changed currentPokemon value.
void Game::swapPokemon(bool turn,string command)
{
    if (turn == OPPONENT_TURN&&command.size()==0)
    {
        bool found = false;
//        for (int i = 0; i < players[turn].pokemons.size(); i++)
//        {
//            if (players[turn].pokemons[i].getHp() > 0)
//            {
//                players[turn].currentPokemon = i;
//                found = true;
//            }
//        }
        if(findAvailablePokemon(turn).size()>0)found = true;

        if (!found)
        {
            playable = false;
            winOrLose = true;

            string gameResult;
            gameResult = (winOrLose) ? "You win" : "You lose";

           cout << "[Turn " << turnNumber << "] ";
            cout << gameResult << endl;
        }
        emit stringList(getStringList(findAvailablePokemon(turn)));
        return;
    }
    else if(turn == PLAYER_TURN&&command.size()==0)
    {
        bool found = false;
//        for (int i = 0; i < players[turn].pokemons.size(); i++)
//        {
//            if (players[turn].pokemons[i].getHp() > 0)
//            {
//                found = true;
//            }
//        }

        if(findAvailablePokemon(turn).size()>0)found = true;

        if (!found)
        {
            playable = false;
            winOrLose = true;

            string gameResult;
            gameResult = (winOrLose) ? "You win" : "You lose";

            cout << "[Turn " << turnNumber << "] ";
            cout << gameResult << endl;
        }
        else
        {
            // Output the pokemon available
            cout << "Available Pokemon(s):" << endl;
            for (int i = 0; i < players[turn].pokemons.size(); i++)
            {
                if (players[turn].pokemons[i].getHp() > 0)
                {
                    cout << players[turn].pokemons[i].getName() << " ";
                }
            }
            cout << endl;
            emit stringList(getStringList(findAvailablePokemon(turn)));
            cout << "Type \"exit\" to teminate swap." << endl;
        }
        return;
    }
    else
    {

            if (command == "exit")
            {
                // go back to the main menu
                return;
            }
            else
            {
                bool found = false;
                for (int i = 0; i < players[turn].pokemons.size(); i++)
                {
                    string pokemonTempName = players[turn].pokemons[i].getName();
                    if (command == pokemonTempName)
                    {
                        players[turn].currentPokemon = i;
                        if (turn == PLAYER_TURN)
                        {
                           cout << "[Turn " << turnNumber << "] ";
                            cout << pokemonTempName << ", switch out!" << endl;                            
                           cout << "[Turn " << turnNumber << "] ";
                            cout << "Come back!" << endl;
                           cout << "[Turn " << turnNumber << "] ";
                            cout << "Go! " << players[turn].pokemons[i].getName() << "!" << endl;
                        }
                        found = true;

                        break;
                    }
                }

                if(!found)
                {
                    cout << "Invalid input pokemon to swap." << endl;
                    swapPokemon(turn,"");
                }
            }
    }
}

// Intent:  To use a move to the opponent Pokemon.
// Pre:     Player's pokemons must have been initialised.
// Post:    The function used move.
bool Game::useMove(string moveName, bool turn, bool testMode)
{
    Pokemon *attackPokemon = &players[turn].pokemons[players[turn].currentPokemon];

    // Unable to attack.
    if (attackPokemon->isParalysis())
    {
       cout << "[Turn " << turnNumber << "] ";
        cout << "<" << attackPokemon->getName() << ">";
        cout << " is paralyzed!\nIt can't move!" << endl;
        return false;
    }

    // Attack if able to attack.
    Pokemon *defendPokemon = &players[!turn].pokemons[players[!turn].currentPokemon];
    int moveIndex = findMove(*attackPokemon, moveName);
    if(moveIndex<0)
    {
        cout<<"No move"<<endl;
        return false;
    }
    attackPokemon->useMove(*defendPokemon, moveIndex, turnNumber);

    // Output messege.
    if (defendPokemon->isBurned())
    {
       cout << "[Turn " << turnNumber << "] ";
        cout << "<" << defendPokemon->getName() << ">";
        cout << " was burned!" << endl;
    }
    if (defendPokemon->isParalysis())
    {
       cout << "[Turn " << turnNumber << "] ";
        cout << "<" << defendPokemon->getName() << ">";
        cout << " is paralyzed, so it may be unable to move!" << endl;
    }
    if (defendPokemon->isPoisoned())
    {
       cout << "[Turn " << turnNumber << "] ";
        cout << "<" << defendPokemon->getName() << ">";
        cout << " was poisoned!" << endl;
    }

    // Check Fainting
    if (defendPokemon->getHp() <= 0)
    {
       cout << "[Turn " << turnNumber << "] ";
        if (turn == OPPONENT_TURN)
        {
            cout << "The opposing " << defendPokemon->getName() << " fainted!" << endl;
            swapPokemon(OPPONENT_TURN,"");
            pokemonTimes = 1;
            flag = true;
        }
        else
        {
            swapPokemon(PLAYER_TURN,"");
            pokemonTimes = 1;
            flag = true;
            cout << defendPokemon->getName() << " fainted!" << endl;
        }
    }
    return true;
}

// Intent:  To check B & P.
// Pre:     Player's pokemons must have been initialised.
// Post:    The function computed B&P.
void Game::bAndP()
{
    Pokemon *attackPokemon = &players[currentTurn].pokemons[players[currentTurn].currentPokemon];
    if (attackPokemon->isBurned())
    {
       cout << "[Turn " << turnNumber << "] ";
        cout << "<" << attackPokemon->getName() << ">";
        cout << " is hurt by its burn!" << endl;
    }
    if (attackPokemon->isPoisoned())
    {
       cout << "[Turn " << turnNumber << "] ";
        cout << "<" << attackPokemon->getName() << ">";
        cout << " is hurt by its poisoning!" << endl;
    }
    // Check Fainting
    if (attackPokemon->getHp() <= 0)
    {
       cout << "[Turn " << turnNumber << "] ";
        if (currentTurn == OPPONENT_TURN)
        {
            cout << "The opposing " << attackPokemon->getName() << " fainted!" << endl;
            swapPokemon(OPPONENT_TURN,"");
            pokemonTimes = 1;
            flag = true;
        }
        else
        {
            swapPokemon(PLAYER_TURN,"");
            pokemonTimes = 1;
            flag = true;
            cout << attackPokemon->getName() << " fainted!" << endl;
        }
    }
    Pokemon *defendPokemon = &players[!currentTurn].pokemons[players[!currentTurn].currentPokemon];
    if (defendPokemon->isBurned())
    {
       cout << "[Turn " << turnNumber << "] ";
        cout << "<" << defendPokemon->getName() << ">";
        cout << " is hurt by its burn!" << endl;
    }
    if (defendPokemon->isPoisoned())
    {
       cout << "[Turn " << turnNumber << "] ";
        cout << "<" << defendPokemon->getName() << ">";
        cout << " is hurt by its poisoning!" << endl;
    }
    // Check Fainting
    if (defendPokemon->getHp() <= 0)
    {
       cout << "[Turn " << turnNumber << "] ";
        if (currentTurn == OPPONENT_TURN)
        {
            cout << "The opposing " << defendPokemon->getName() << " fainted!" << endl;
            swapPokemon(OPPONENT_TURN,"");
            pokemonTimes = 1;
            flag = true;
        }
        else
        {
            swapPokemon(PLAYER_TURN,"");
            pokemonTimes = 1;
            flag = true;
            cout << defendPokemon->getName() << " fainted!" << endl;
        }
    }
}

// Intent:  To check Pokemon's faint status.
// Pre:     Player's Pokemons must have been initialised.
// Post:    The function returns true if the Pokemon is fainted.
bool Game::checkFainting(bool turn)
{
    return (players[turn].pokemons[players[turn].currentPokemon].getHp() <= 0);
}

bool Game::useBag()
{
    string potionInput;
    cin >> potionInput;

    Pokemon& currPokemon = players[0].getPokemon();

    if (potionInput == "Potion")
    {
        cout << "Choose pokemon to used the potion : ";

        for (int i = 0; i < players[currentTurn].pokemons.size(); i++)
        {
            cout << players[currentTurn].pokemons[i].getName() << " ";
        }
        cout << endl;

        string healPokemon;
        cin >> healPokemon;

        if (healPokemon == "Exit")
        {
            // go back to the main menu
            return false;
        }
        else
        {
            bool found = false;
            int targetIdx = -1;
            for (int i = 0; i < players[currentTurn].pokemons.size(); i++)
            {
                string tempPokemon = players[currentTurn].pokemons[i].getName();
                if (healPokemon == tempPokemon)
                {
                    targetIdx = i;
                    found = true;
                    continue;
                }

                if (!found)
                {
                    cout << "Invalid Pokemon to heal" << endl;
                }

                else
                {
                    // call the function to used the potion
                    Potion heal;
                    heal.update(players[currentTurn].pokemons[i]);
                }
            }
        }
    }
    else if (potionInput == "Super Potion")
    {
        cout << "Choose pokemon to used the potion : ";

        for (int i = 0; i < players[0].pokemons.size(); i++)
        {
            cout << players[0].pokemons[i].getName() << " ";
        }
        cout << endl;

        string healPokemon;
        cin >> healPokemon;

        if (healPokemon == "Exit")
        {
            // go back to the main menu
            return false;
        }
        else
        {
            bool found = false;
            int targetIdx = -1;
            for (int i = 0; i < players[0].pokemons.size(); i++)
            {
                string tempPokemon = players[0].pokemons[i].getName();
                if (healPokemon == tempPokemon)
                {
                    targetIdx = i;
                    found = true;
                    continue;
                }

                if (!found)
                {
                    cout << "Invalid Pokemon to heal" << endl;
                }

                else
                {
                    // call the function to used the potion
                    SuperPotion heal;
                    heal.update(players[0].pokemons[i]);
                }
            }
        }
    }

    else if (potionInput == "Hyper Potion")
    {
        cout << "Choose pokemon to used the potion : ";

        for (int i = 0; i < players[currentTurn].pokemons.size(); i++)
        {
            cout << players[currentTurn].pokemons[i].getName() << " ";
        }
        cout << endl;

        string healPokemon;
        cin >> healPokemon;

        if (healPokemon == "Exit")
        {
            // go back to the main menu
            return false;
        }

        else
        {
            bool found = false;
            int targetIdx = -1;
            for (int i = 0; i < players[currentTurn].pokemons.size(); i++)
            {
                string tempPokemon = players[currentTurn].pokemons[i].getName();
                if (healPokemon == tempPokemon)
                {
                    targetIdx = i;
                    found = true;
                    continue;
                }

                if (!found)
                {
                    cout << "Invalid Pokemon to heal" << endl;
                }

                else
                {
                    // call the function to used the potion
                    HyperPotion heal;
                    heal.update(players[currentTurn].pokemons[i]);
                }
            }
        }
    }

    else if (potionInput == "Max Potion")
    {

        cout << "Choose pokemon to used the potion : ";

        for (int i = 0; i < players[currentTurn].pokemons.size(); i++)
        {
            cout << players[currentTurn].pokemons[i].getName() << " ";
        }
        cout << endl;

        string healPokemon;
        cin >> healPokemon;

        if (healPokemon == "Exit")
        {
            // go back to the main menu
            return false;
        }
        else
        {
            bool found = false;
            int targetIdx = -1;
            for (int i = 0; i < players[currentTurn].pokemons.size(); i++)
            {
                string tempPokemon = players[currentTurn].pokemons[i].getName();
                if (healPokemon == tempPokemon)
                {
                    targetIdx = i;
                    found = true;
                    continue;
                }

                if (!found)
                {
                    cout << "Invalid Pokemon to heal" << endl;
                }
                else
                {
                    // call the function to used the potion
                    MaxPotion heal;
                    heal.update(players[currentTurn].pokemons[i]);
                }
            }
        }
    }
    else
    {
        cout << "No such " << potionInput << "in the bag." << endl;
    }
    return true;
}
/**
 * @brief Game::loadTestCase
 * @param fileName
 * @return
 */
bool Game::loadTestCase(string fileName)
{
    ifstream file(fileName);
    string line;
    while(getline(file,line))
    {
        executeCommand(line);
    }

    return true;
}
/**
 * @brief Game::loadTestCase
 * @return
 */
bool Game::loadTestCase()
{
    try
    {
        QString filePath = QFileDialog::getOpenFileName(
            nullptr,
            "Chose Data",
            QDir::homePath(),
            "文本文件 (*.txt);;所有文件 (*)"
            );

        if (!filePath.isEmpty()) {
            qDebug() << "Chose Data Path" << filePath;
        } else {
            qDebug() << "no chose any data";
        }
        loadTestCase(filePath.toStdString());
    }
    catch (const int error_code)
    {
        cout<<error_code<<endl;
    }

    return true;
}

/**
 * @brief Game::loadTestCase
 * @param fileName
 * @return
 */
bool Game::loadPokemonData()
{
    try
    {
        QString filePath = QFileDialog::getOpenFileName(
            nullptr,
            "Chose Data",
            QDir::homePath(),
            "文本文件 (*.txt);;所有文件 (*)"
            );

        if (!filePath.isEmpty()) {
            std::cout << "Chose Data Path" << filePath.toStdString()<<endl;
        } else {
            std::cout << "no chose any data"<<endl;
        }
        DataFormat data;
        data.loadPokemonData(filePath.toStdString(),this);
    }
    catch (const int error_code)
    {
        cout<<error_code<<endl;
    }
    return true;
}
/**
 * @brief Game::loadTestCase
 * @param fileName
 * @return
 */
bool Game::loadMoveData()
{
    try
    {
        QString filePath = QFileDialog::getOpenFileName(
            nullptr,
            "Chose Data",
            QDir::homePath(),
            "文本文件 (*.txt);;所有文件 (*)"
            );

        if (!filePath.isEmpty()) {
            std::cout << "Chose Data Path" << filePath.toStdString()<<endl;
        } else {
            std::cout << "no chose any data"<<endl;
        }
        DataFormat data;
        data.loadMoveData(filePath.toStdString(),this);
    }
    catch (const int error_code)
    {
        cout<<error_code<<endl;
    }
    return true;
}
/**
 * @brief Game::loadTestCase
 * @param fileName
 * @return
 */
bool Game::loadGameData()
{
    try
    {
        QString filePath = QFileDialog::getOpenFileName(
            nullptr,
            "Chose Data",
            QDir::homePath(),
            "文本文件 (*.txt);;所有文件 (*)"
            );

        if (!filePath.isEmpty()) {
            qDebug() << "Chose Data Path" << filePath;
        } else {
            qDebug() << "no chose any data";
        }
        DataFormat data;
        data.loadGameData(filePath.toStdString(),this);
    }
    catch (const int error_code)
    {
        cout<<error_code<<endl;
    }
    return true;
}

/**
 * @brief Game::check
 */
void Game::check()
{
    Pokemon* pokemon = &players[currentTurn].pokemons[players[currentTurn].currentPokemon];
   cout << "[Turn " << turnNumber << "] ";
    for(const auto& move : pokemon->getMoves())
    {
        cout<<move.getName()<<" "<<move.getPP()<<" ";
    }
    cout<<endl;
}
/**
 * @brief Game::status
 */
void Game::status(int currentTurn)
{
    Pokemon* pokemonOne,*pokemonTwo;
    if(players.size()<2||players[PLAYER_TURN].pokemons.size()==0||players[PLAYER_TURN].pokemons.size()==0)
    {
        cout<<"error size"<<endl;
        return;
    }
    pokemonOne = &players[PLAYER_TURN].pokemons[players[PLAYER_TURN].currentPokemon];
    pokemonTwo = &players[OPPONENT_TURN].pokemons[players[OPPONENT_TURN].currentPokemon];
   cout << "[Turn " << turnNumber << "] ";
    cout<<pokemonOne->getName()<<" "<<pokemonOne->getHp()<<" ";
   for(int i=0;i<pokemonOne->getStateList().size();i++)
    {
        if(pokemonOne->getStateList()[i]==true)
        {
            cout<<stateToString(i);
        }
    }
    cout<<" ";
    cout<<pokemonTwo->getName()<<" "<<pokemonTwo->getHp()<<" ";
    for(int i=0;i<pokemonTwo->getStateList().size();i++)
    {
        if(pokemonTwo->getStateList()[i]==true)
        {
            cout<<stateToString(i);
        }
    }
    cout<<endl;
}

void Game::tellStory()
{
//    cout << "寶可夢是充滿著許多秘密的神祕生物。\n"
//         << "一些寶可夢跟人類一起生活，一些是生活在野外草地\n"
//         << "或是洞穴、或是海洋中，但很多關於他們的生態依舊是未知。\n"
//         << "他們主要的特徵之一是一個精靈球收服他們，\n"
//         << "這也讓他們能夠被隨身攜帶。" << endl;
}

bool Game::checkAllDataLoaded()
{
    if(!pokemons.empty()&&!moves.empty()&&!players.empty())
    {
        return true;
    }
    QDialog dialog;
    QVBoxLayout layout(&dialog);
    QLabel label(QString::fromStdString("please load data"),&dialog);
    dialog.setFixedSize(100,100);
    dialog.exec();
    return false;
}

QString Game::getMoveName(int index)
{
    if(players.empty()||moves.empty()||pokemons.empty())return "No Data";
    Pokemon* pokemon = &players[0].pokemons[players[0].currentPokemon];
    cout<<pokemon->getMoves()[index].getName()<<endl;
    return QString::fromStdString(pokemon->getMoves()[index].getName());
}

QString Game::getCurrentStatus(int index)
{
    if(players.empty()||moves.empty()||pokemons.empty())return "No Pokemon";
     Pokemon* pokemon = &players[index].pokemons[players[index].currentPokemon];
    string s = pokemon->getName();
    s+=" " + to_string(pokemon->getHp())+"/"+ to_string(pokemon->getMaxHP());
    for(const auto& state: pokemon->getStateList())
    {
        if(state==true)
        {
            s+=" " + stateToString(state);
        }
    }
    QString info = QString::fromStdString(s);
    return info;
}

void Game::randomMove()
{
     if(players.empty()||moves.empty()||pokemons.empty())
    {
        cout<<"No Pokemon"<<endl;
        return ;
    }
     srand(time(nullptr));

     Pokemon* pokemon = &players[OPPONENT_TURN].pokemons[players[OPPONENT_TURN].currentPokemon];
     int radom_variable = rand()%pokemon->getMoves().size();
     if(currentTurn == OPPONENT_TURN)
     {
        string command = "Battle";
        executeCommand(command);
        return;
     }
     executeCommand(pokemon->getMoves()[radom_variable].getName());
}

QStringList Game::getStringList(vector<string> v)
{
     QStringList qStringList;
     for (const std::string& str : v)
     {
        qStringList.append(QString::fromStdString(str));
     }

     return qStringList;
}
