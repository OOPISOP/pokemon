/***********************************************************************
 * File: DataFormat.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/06/
 * Description: Load Pokemon data from file , Pokemon data , Move data , Game data , Test Case format
***********************************************************************/
#pragma once

#include "Pokemon.h"
#include "Player.h"
#include "Game.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

//Implement Pokemon data、Move data、Game data 、 Test Case format

class DataFormat
{
public:
    //DataFormat Constructor
    DataFormat();
    //DataFormat Destructor
    ~DataFormat();

    /**
     * Intent:Load Pokemon data from file
     * Pre:Pokemon data file name
     * Pos:Print failed if file cannot be opened
     */
    void loadPokemonData(string fileName, Game &game);

    // Intent:  Load move data from file.
    // Pre:     Move data file name.
    // Post:    Print failed if file cannot be opened.
    void loadMoveData(string fileName, Game &game);

    /**
     * Intent:Load Game data from file 
     * Pre:Game data file name
     * Pos:return players
     */
    vector<Player>& loadGameData(string fileName);
};
