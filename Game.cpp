/***********************************************************************
 * File: Game.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/05/29
 * Description: This C++ program is Pokemon Game Manager
***********************************************************************/
#include "Game.h"
//Game Constructor
Game::Game()
{
<<<<<<< Updated upstream

=======
    isTestMode = false;
    Player player;
    Player opponent;
    players.push_back(player);
    players.push_back(opponent);
>>>>>>> Stashed changes
}
//Game Destructor
Game::~Game()
{

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
<<<<<<< Updated upstream
    stringstream commandStream(command);
    string action;
    commandStream >> action;
    try
    {
        if(action == "PokemonData")
        {
            string fileName;
            commandStream >> fileName;//get fileName
            DataFormat dataFormat;
            dataFormat.loadPokemonData(fileName);
            pokemons = dataFormat.pokemons;
        }
        else if(action == "MoveData")
        {

        }
        else if(action == "GameData")
        {

        }
        else if(action == "Bag")
=======

    currentTurn = (players[PLAYER_TURN].pokemons[players[PLAYER_TURN].currentPokemon].getSpeed() >
                        players[OPPONENT_TURN].pokemons[players[OPPONENT_TURN].currentPokemon].getSpeed()) ?
                           PLAYER_TURN : OPPONENT_TURN;

    try
    {
        if(command == "Bag")
>>>>>>> Stashed changes
        {

        }
        else if(command == "Pokemon")
        {

        }
        else if(command == "Battle")
        {

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
