/***********************************************************************
 * File: Game.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033,B11115013
 * Update Date: 2023/06/14
 * Description: This C++ program is Pokemon Game Manager
***********************************************************************/
#include "Game.h"
#include "Pokemon.h"
#include "Player.h"
#include "Potion.h"


//Game Constructor

Game::Game()
{
    isTestMode = false;
    Player player;
    Player opponent;
    players.push_back(player);
    players.push_back(opponent);
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
    //Error Proof
    if(command.empty())
    {
        return false;
    }

//    currentTurn = (players[PLAYER_TURN].pokemons[players[PLAYER_TURN].currentPokemon].getSpeed() >
//                        players[OPPONENT_TURN].pokemons[players[OPPONENT_TURN].currentPokemon].getSpeed()) ?
//                           PLAYER_TURN : OPPONENT_TURN;
    try
    {
        if (command == "Bag")
        {
            cout << "Please choose potion to used: Potion, Super Potion, Hyper Potion, Max Potion." << endl;

            string potionInput;
            cin >> potionInput;

            Pokemon& currPokemon = players[0].getPokemon();

            if (potionInput == "Potion")
            {
                cout << "Choose pokemon to used the potion : ";

                Player& currentPlayer = game->players[0];
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
                    return;
                }

                else
                {
                    bool found = false;
                    int targetIdx = -1;
                    for (int i = 0; i < currentPlayer.pokemons.size(); i++)
                    {
                        string tempPokemon = cucurrentPlayer.pokemons[i].getName();
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

                Player& currentPlayer = game->players[0];
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
                    return;
                }

                else
                {
                    bool found = false;
                    int targetIdx = -1;
                    for (int i = 0; i < currentPlayer.pokemons.size(); i++)
                    {
                        string tempPokemon = cucurrentPlayer.pokemons[i].getName();
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

                Player& currentPlayer = game->players[0];
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
                    return;
                }

                else
                {
                    bool found = false;
                    int targetIdx = -1;
                    for (int i = 0; i < currentPlayer.pokemons.size(); i++)
                    {
                        string tempPokemon = cucurrentPlayer.pokemons[i].getName();
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

                Player& currentPlayer = game->players[0];
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
                    return;
                }

                else
                {
                    bool found = false;
                    int targetIdx = -1;
                    for (int i = 0; i < currentPlayer.pokemons.size(); i++)
                    {
                        string tempPokemon = cucurrentPlayer.pokemons[i].getName();
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
                            MaxPotion.heal;
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

        else if(command == "Pokemon")
        {
            // output the pokemon available

            Player& currentPlayer = game->players[0];
            for (int i = 0; i < currentPlayer.pokemons.size(); i++)
            {
                cout << currentPlayer.pokemons[i].getName() << endl;
            }
            
            cout << "Type exit or swap the pokemon" << endl;
            // chance for swapping
            string swapPokemon;
            cin >> swapPokemon;

            if (swapPokemon == "exit")
            {
                // go back to the main menu
                return;
            }

            else
            {
                bool found = false;
                for (int i = 0; i < currentPlayer.pokemons.size(); i++)
                {
                    string pokemonTempName = currentPlayer.pokemons.getName();
                    if (swapPokemon == pokemonTempName)
                    {
                        currentPlayer.currentPokemon = i;
                        cout << pokemonTempName << ", switch out!" << endl;
                        cout << "Come back!" << endl;
                        cout << "Go! " << curretPlayer.pokemons[i].getName() << "!" << endl;
                        found = true;

                        break;
                    }
                }

                if(!found)
                {
                    cout << "Invalid input pokemon to swap." << endl;
                }  

                else
                {
                    // save and store the swapped pokemon
                    game->players[0] = currentPlayer;
                }
            }
        }

        else if(command == "Battle")
        {
           // 1. print out the available moves for pokemon


        }


        else if(command == "Check")
        {
            // print out the moves & PP of current player's pokemon.
            // movelib.txt
            Player& currentPlayer = game->players[0];
            Pokemon& currentPokemon = currentPlayer.pokemons[currentPlayer.currentPokemon];

            for (const Move& move : currentPokemon.moves)
            {
                cout << move.getName() << move.pp();
            }
            cout << endl;
        }


        else if(command == "Status")
        {

        }
        else if(command == "Run")
        {
            exit(0);
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
