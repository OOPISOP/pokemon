/***********************************************************************
 * File: Game.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/06/14
 * Description: This C++ program is Pokemon Game Manager
***********************************************************************/
#include "Game.h"


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
        if(command == "Pokemon")
        {

        }
        else if((command == "Battle") || (command == "Bag"))
        {
            string command2;
            cin >> command2;

            battle(command, command2, currentTurn, isTestMode);
        }
        else if(command == "Check")
        {

        }
        else if(command == "Status")
        {

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


// Intent:  To mange one turn of battle process.
// Pre:     None.
// Post:    The function executed a turn.
void Game::battle(string command1, string command2, bool currentTurn, bool testMode)
{
    if (command1 == "bag")
    {
        // First Pokemon being used potion.
        string targetPokemon;
        cin >> targetPokemon;
        usePotion(currentTurn, targetPokemon, command2);

        string OpponentMove;
        cin >> OpponentMove;
        if (OpponentMove == "bag")
        {
            // Second Pokemon being used potion.
            string potionName;
            cin >> potionName;
            cin >> targetPokemon;
            usePotion(!currentTurn, targetPokemon, potionName);
        }
        else
        {
            // Including second Pokemon damage calculation.
            useMove(OpponentMove, !currentTurn, isTestMode);
        }
    }
    else
    {
        // Including first Pokemon damage calculation.
        useMove(command1, currentTurn, isTestMode);

        string OpponentMove;
        cin >> OpponentMove;
        // Including second Pokemon damage calculation.
        useMove(OpponentMove, !currentTurn, isTestMode);
    }


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
void Game::swapPokemon(bool turn, string pokemon1, string pokemon2)
{
    int index1, index2;
    index1 = findPokemon(turn, pokemon1);
    index2 = findPokemon(turn, pokemon2);

    players[turn].currentPokemon = index2;

    if (index1 == -1)
    {
        cout << pokemon1 << " not found." << endl;
    }
    if (index2 == -1)
    {
        cout << pokemon2 << " not found." << endl;
    }
}

// Intent:  To use a potion in bag to a Pokemon.
// Pre:     d
// Post:    d
void Game::usePotion(bool turn, string targetPokemon, string potionName)
{

}

// Intent:  To use a move to the opponent Pokemon.
// Pre:     d
// Post:    d
void Game::useMove(string moveName, bool turn, bool testMode)
{
    Pokemon &attackPokemon = players[turn].pokemons[players[turn].currentPokemon];
    Pokemon &defendPokemon = players[!turn].pokemons[players[!turn].currentPokemon];
    int moveIndex = findMove(attackPokemon, moveName);

    attackPokemon.userMove(defendPokemon, moveIndex);
}

// Intent:  To check Pokemon's faint status.
// Pre:     Player's Pokemons must have been initialised.
// Post:    The function returns true if the Pokemon is fainted.
bool Game::checkFainting(bool turn)
{
    return (players[turn].pokemons[players[turn].currentPokemon].getHp() <= 0);
}
