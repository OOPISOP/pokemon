/***********************************************************************
 * File: main.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/06/
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
void Game::executeCommand(string command)
{
    //Error Proof
    if(command.empty())
    {
        return false;
    }

    try
    {
        if(action == "Bag")
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
        else if(action == "Test")
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
