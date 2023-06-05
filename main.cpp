/***********************************************************************
 * File: main.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/05/29
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
    fstream testCaseFile;
    string commandLine;

    // Initialise testcase.
    std::cin >> fileName;
    testCaseFile.open(fileName);
    //Error Proof
    if(!testCaseFile.is_open())
    {
        cout<< "The input testcase: \"" << fileName << "\" cannot be opened." << endl;
        return;
    }

    // Initialise pokemon library.
    testCaseFile >> fileName;
    dataFormat.loadPokemonData(fileName, &game);

    // Initialise move library.
    testCaseFile >> fileName;
    dataFormat.loadMoveData(fileName, &game);

    // Initialise game data.
    testCaseFile >> fileName;
    dataFormat.loadGameData(fileName, &game);

//    // Read commands.
//    while(getline(testCaseFile,commandLine))
//    {
//        game.executeCommand(commandLine);
//    }

    testCaseFile.close();
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
