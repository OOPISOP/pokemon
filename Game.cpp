/***********************************************************************
 * File: main.h
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
    stringstream commandStream(command);
    string action;
    try
    {
        if(action == "PokemonData")
        {

        }
        else if(action == "MoveData")
        {

        }
        else if(action == "GameData")
        {

        }
        else if(action == "Bag")
        {

        }
        else if(action == "Pokemon")
        {

        }
        else if(action == "Battle")
        {

        }
        else if(action == "Check")
        {

        }
        else if(action == "Status")
        {

        }
        else if(action == "Run")
        {

        }
    }
    catch(int failed)
    {
        cout << "Failed" << endl;
		return false;
    }
    
    
    return true;
}
