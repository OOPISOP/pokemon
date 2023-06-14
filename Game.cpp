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

//Game Constructor

Game::Game()
{
    isTestMode = false;
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
        return true;
    }
    if(moves.empty())
    {
        DataFormat data;
        data.loadMoveData(command,this);
        return true;
    }
    if(players.empty())
    {
        DataFormat data;
        data.loadGameData(command,this);
        return true;
    }
    currentTurn = (players[PLAYER_TURN].pokemons[players[PLAYER_TURN].currentPokemon].getSpeed() >
                   players[OPPONENT_TURN].pokemons[players[OPPONENT_TURN].currentPokemon].getSpeed()) ?
                      PLAYER_TURN : OPPONENT_TURN;
    //Error Proof
    try
    {
        if(command == "Pokemon")
        {
            string command2;

            // Swap Pokemon.
            swapPokemon(currentTurn);

            // Attack from second players.
            cin >> command2;
            battle(command2, !currentTurn, isTestMode);
            // B & P.
            bAndP();

            turnNumber++;
        }
        else if (command == "Bag")
        {
            // Use potion.
            useBag();

            // Attack from second players.
            string command2;
            cin >> command2;
            battle(command2, !currentTurn, isTestMode);
            // B & P.
            bAndP();

            turnNumber++;
        }
        else if(command == "Battle")
        {
            Player *ourPlayer = &players[PLAYER_TURN];
            Player *opponent = &players[OPPONENT_TURN];

            currentTurn = (ourPlayer->pokemons[ourPlayer->currentPokemon].getSpeed()
                           > opponent->pokemons[opponent->currentPokemon].getSpeed()) ? PLAYER_TURN : OPPONENT_TURN;

            string command2, command3;
            cin >> command2;
            cin >> command3;

            // Attack from second players.
            battle(command2, currentTurn, isTestMode);

            // Attack from second players.
            battle(command3, !currentTurn, isTestMode);

            // B & P.
            bAndP();

            turnNumber++;
        }
        else if(command == "Check")
        {
            check(PLAYER_TURN);
        }
        else if(command == "Status")
        {
            status();
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

// Intent:  To swap Pokemon.
// Pre:     None.
// Post:    The function changed currentPokemon value.
void Game::swapPokemon(bool turn)
{
    if (turn == OPPONENT_TURN)
    {
        bool found = false;
        for (int i = 0; i < players[turn].pokemons.size(); i++)
        {
            if (players[turn].pokemons[i].getHp() > 0)
            {
                players[turn].currentPokemon = i;
                found = true;
            }
        }

        if (!found)
        {
            playable = false;
            winOrLose = true;

            string gameResult;
            gameResult = (winOrLose) ? "You win" : "You lose";

           cout << "[Turn " << turnNumber << "] ";
            cout << gameResult << endl;
        }
    }
    else
    {
        bool found = false;
        for (int i = 0; i < players[turn].pokemons.size(); i++)
        {
            if (players[turn].pokemons[i].getHp() > 0)
            {
                found = true;
            }
        }

        if (!found)
        {
            playable = false;
            winOrLose = false;

            string gameResult;
            gameResult = (winOrLose) ? "You win" : "You lose";

           cout << "[Turn " << turnNumber << "] ";
            cout << gameResult << endl;
        }
        else
        {
            string command;
            cin >> command;
            bool found = false;
            for (int i = 0; i < players[turn].pokemons.size(); i++)
            {
                string pokemonTempName = players[turn].pokemons[i].getName();
                if (command == pokemonTempName)
                {
                    if (turn == PLAYER_TURN)
                    {
                        cout << "[Turn " << turnNumber << "] ";
                        cout << players[turn].pokemons[players[turn].currentPokemon].getName() << ", switch out!" << endl;
                        cout << "[Turn " << turnNumber << "] ";
                        cout << "Come back!" << endl;
                        players[turn].currentPokemon = i;
                        cout << "[Turn " << turnNumber << "] ";
                        cout << "Go! " << players[turn].pokemons[i].getName() << "!" << endl;
                    }
                    found = true;

                    break;
                }
            }
        }
    }
}

// Intent:  To use a move to the opponent Pokemon.
// Pre:     Player's pokemons must have been initialised.
// Post:    The function used move.
void Game::useMove(string moveName, bool turn, bool testMode)
{
    Pokemon *attackPokemon = &players[turn].pokemons[players[turn].currentPokemon];

    // Check Fainting
    if (attackPokemon->getHp() <= 0)
    {
        cout << "[Turn " << turnNumber << "] ";
        if (turn == OPPONENT_TURN)
        {
            cout << "The opposing " << attackPokemon->getName() << " fainted!" << endl;
            swapPokemon(OPPONENT_TURN);
        }
        else
        {
            swapPokemon(PLAYER_TURN);
            cout << attackPokemon->getName() << " fainted!" << endl;
        }
    }

    // Unable to attack.
    if (attackPokemon->isParalysis())
    {
       cout << "[Turn " << turnNumber << "] ";
        cout << attackPokemon->getName() << " is paralyzed!\nIt can't move!" << endl;
        return;
    }

    // Attack if able to attack.
    Pokemon *defendPokemon = &players[!turn].pokemons[players[!turn].currentPokemon];
    int moveIndex = findMove(*attackPokemon, moveName);

    cout << "[Turn " << turnNumber << "] ";
    if (turn == OPPONENT_TURN)
    {
        cout << "The opposing ";
    }
    attackPokemon->useMove(*defendPokemon, moveIndex, turnNumber, turn);
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
        attackPokemon->applyNegativeEffect();
        cout << attackPokemon->getName() << " is hurt by its burn!" << endl;
    }
    if (attackPokemon->isPoisoned())
    {
        cout << "[Turn " << turnNumber << "] ";
        attackPokemon->applyNegativeEffect();
        cout << attackPokemon->getName() << " is hurt by its poisoning!" << endl;
    }
    // Check Fainting
    if (attackPokemon->getHp() <= 0)
    {
        cout << "[Turn " << turnNumber << "] ";
        cout << attackPokemon->getName() << " fainted!" << endl;
        swapPokemon(PLAYER_TURN);
    }

    Pokemon *defendPokemon = &players[!currentTurn].pokemons[players[!currentTurn].currentPokemon];
    if (defendPokemon->isBurned())
    {
        cout << "[Turn " << turnNumber << "] ";
        cout << "The opposing ";
        defendPokemon->applyNegativeEffect();
        cout << defendPokemon->getName() << " is hurt by its burn!" << endl;
    }
    if (defendPokemon->isPoisoned())
    {
        cout << "[Turn " << turnNumber << "] ";
        cout << "The opposing ";
        defendPokemon->applyNegativeEffect();
        cout << defendPokemon->getName() << " is hurt by its poisoning!" << endl;
    }
    // Check Fainting
    if (defendPokemon->getHp() <= 0)
    {
        cout << "[Turn " << turnNumber << "] ";
        defendPokemon->applyNegativeEffect();
        cout << "The opposing " << defendPokemon->getName() << " fainted!" << endl;
        swapPokemon(OPPONENT_TURN);
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
    getline(cin, potionInput);
    string healPokemon;
    cin >> healPokemon;

    if (potionInput == "Potion")
    {
        for (int i = 0; i < players[currentTurn].pokemons.size(); i++)
        {
            string tempPokemon = players[currentTurn].pokemons[i].getName();
            if (healPokemon == tempPokemon)
            {
                Potion heal;
                // call the function to used the potion
                heal.update(players[currentTurn].pokemons[i], turnNumber);

                return true;
            }
        }
    }
    else if (potionInput == "Super Potion")
    {
        for (int i = 0; i < players[currentTurn].pokemons.size(); i++)
        {
            string tempPokemon = players[currentTurn].pokemons[i].getName();
            if (healPokemon == tempPokemon)
            {
                SuperPotion heal;
                // call the function to used the potion
                heal.update(players[currentTurn].pokemons[i], turnNumber);

                return true;
            }
        }
    }
    else if (potionInput == "Hyper Potion")
    {
        for (int i = 0; i < players[currentTurn].pokemons.size(); i++)
        {
            string tempPokemon = players[currentTurn].pokemons[i].getName();
            if (healPokemon == tempPokemon)
            {
                HyperPotion heal;
                // call the function to used the potion
                heal.update(players[currentTurn].pokemons[i], turnNumber);

                return true;
            }
        }
    }
    else if (potionInput == "Max Potion")
    {
        for (int i = 0; i < players[currentTurn].pokemons.size(); i++)
        {
            string tempPokemon = players[currentTurn].pokemons[i].getName();
            if (healPokemon == tempPokemon)
            {
                MaxPotion heal;
                // call the function to used the potion
                heal.update(players[currentTurn].pokemons[i], turnNumber);

                return true;
            }
        }
    }

    return false;
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
            "選擇文件",
            QDir::homePath(),
            "文本文件 (*.txt);;所有文件 (*)"
            );

        if (!filePath.isEmpty()) {
            qDebug() << "選擇的文件路徑" << filePath;
        } else {
            qDebug() << "為選擇任何文件";
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
            "選擇文件",
            QDir::homePath(),
            "文本文件 (*.txt);;所有文件 (*)"
            );

        if (!filePath.isEmpty()) {
            std::cout << "選擇的文件路徑" << filePath.toStdString()<<endl;
        } else {
            std::cout << "為選擇任何文件"<<endl;
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
            "選擇文件",
            QDir::homePath(),
            "文本文件 (*.txt);;所有文件 (*)"
            );

        if (!filePath.isEmpty()) {
            std::cout << "選擇的文件路徑" << filePath.toStdString()<<endl;
        } else {
            std::cout << "為選擇任何文件"<<endl;
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
            "選擇文件",
            QDir::homePath(),
            "文本文件 (*.txt);;所有文件 (*)"
            );

        if (!filePath.isEmpty()) {
            qDebug() << "選擇的文件路徑" << filePath;
        } else {
            qDebug() << "為選擇任何文件";
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
void Game::check(bool turn)
{
    Pokemon* pokemon = &players[turn].pokemons[players[turn].currentPokemon];
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
void Game::status()
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
    for(const auto state: pokemonOne->getStateList())
    {
        if(state==true)
        {
            cout<<stateToString(state);
        }
    }
    cout<<" ";

    cout<<pokemonTwo->getName()<<" "<<pokemonTwo->getHp()<<" ";
    for(const auto state: pokemonTwo->getStateList())
    {
        if(state==true)
        {
            cout<<stateToString(state);
        }
    }
    cout<<endl;
}

void Game::tellStory()
{
    cout << "Pokemon are creatures of all shapes and sizes who live in the wild \n"
         << "or alongside their human partners (called “Trainers”).\n"
         << "During their adventures, Pokemon grow and become more experienced \n"
         << "and even, on occasion, evolve into stronger Pokemon.\n"
         << "Hundreds of known Pokemon inhabit the Pokemon universe, \n"
         << "with untold numbers waiting to be discovered!" << endl;
}
