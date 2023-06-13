/***********************************************************************
 * File: Game.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/05/29
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
        if(command == "Bag")
        {
            cout << "Please choose potion to used: Potion, Super Potion, Hyper Potion, Max Potion." << endl;

        }
        else if(command == "Pokemon")
        {

        }
        else if(command == "Battle")
        {

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

bool Game::useBag()
{
    string potionInput;
    cin >> potionInput;

    Pokemon& currPokemon = players[0].getPokemon();

    if (potionInput == "Potion")
    {
        cout << "Choose pokemon to used the potion : ";

        Player& currentPlayer = this->players[0];
        for (int i = 0; i < currentPlayer.pokemons.size(); i++)
        {
            cout << currentPlayer.pokemons[i].getName() << " ";
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
            for (int i = 0; i < currentPlayer.pokemons.size(); i++)
            {
                string tempPokemon = currentPlayer.pokemons[i].getName();
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
                    heal.update(currentPlayer.pokemons[i]);
                }
            }
        }
    }
    else if (potionInput == "Super Potion")
    {
        cout << "Choose pokemon to used the potion : ";

        Player& currentPlayer = this->players[0];
        for (int i = 0; i < currentPlayer.pokemons.size(); i++)
        {
            cout << currentPlayer.pokemons[i].getName() << " ";
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
            for (int i = 0; i < currentPlayer.pokemons.size(); i++)
            {
                string tempPokemon = currentPlayer.pokemons[i].getName();
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
                    heal.update(currentPlayer.pokemons[i]);
                }
            }
        }
    }

    else if (potionInput == "Hyper Potion")
    {
        cout << "Choose pokemon to used the potion : ";

        Player& currentPlayer = this->players[0];
        for (int i = 0; i < currentPlayer.pokemons.size(); i++)
        {
            cout << currentPlayer.pokemons[i].getName() << " ";
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
            for (int i = 0; i < currentPlayer.pokemons.size(); i++)
            {
                string tempPokemon = currentPlayer.pokemons[i].getName();
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
                    heal.update(currentPlayer.pokemons[i]);
                }
            }
        }
    }

    else if (potionInput == "Max Potion")
    {

        cout << "Choose pokemon to used the potion : ";

        Player& currentPlayer = this->players[0];
        for (int i = 0; i < currentPlayer.pokemons.size(); i++)
        {
            cout << currentPlayer.pokemons[i].getName() << " ";
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
            for (int i = 0; i < currentPlayer.pokemons.size(); i++)
            {
                string tempPokemon = currentPlayer.pokemons[i].getName();
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
                    heal.update(currentPlayer.pokemons[i]);
                }
            }
        }
    }
    else
    {
        cout << "No such " << potionInput << "in the bag." << endl;
    }
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
}

/**
 * @brief Game::check
 */
void Game::check()
{
    Pokemon* pokemonOne,*pokemonTwo;
    if(players.size()<2||players[PLAYER_TURN].pokemons.size()==0||players[PLAYER_TURN].pokemons.size()==0)
    {
        cout<<"error size"<<endl;
        return;
    }
    pokemonOne = &players[PLAYER_TURN].pokemons[players[PLAYER_TURN].currentPokemon];
    pokemonTwo = &players[OPPONENT_TURN].pokemons[players[OPPONENT_TURN].currentPokemon];
    cout<<pokemonOne->getName()<<" "<<pokemonOne->getHp()<<" ";
    for(const auto state: pokemonOne->getStateList())
    {
        if(state==true)
        {
            cout<<stateToString(state);
        }
    }
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
/**
 * @brief Game::status
 */
void Game::status(int currentTurn)
{
    Pokemon* pokemon = &players[currentTurn].pokemons[players[currentTurn].currentPokemon];
    for(const auto& move : pokemon->getMoves())
    {
        cout<<move.getName()<<" "<<move.getPP()<<" ";
    }
    cout<<endl;
}
