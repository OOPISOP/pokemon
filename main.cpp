/***********************************************************************
 * File: main.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/06/
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#include "main.h"
/**
 * Intent: Run CLI
 * Pre: Start Program
 * Post: End Program
*/
void runCommandLine()
{
    // Variables.
    Game game;
    DataFormat dataFormat;
    string fileName;
    string commandLine;

    // Initialise pokemon library.
    cin >> fileName;
    dataFormat.loadPokemonData(fileName, game);

    if(action == "MoveData")
    {

    }
    if(action == "GameData")
    {

    }

    while(getline(cin,commandLine))
    {
        game.executeCommand(commandLine);
    }
}
/**
 * Intent: Run GUI
 * Pre: Start Program
 * Post: End Program
*/
int runGUI()
{
    return 0;
}

int main(int argc, char** argv)
{
    runCommandLine();
    return 0;
}
