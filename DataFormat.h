/***********************************************************************
 * File: DataFormat.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/05/29
 * Description: Load Pokemon data from file , Pokemon data , Move data , Game data , Test Case format
***********************************************************************/
#pragma once

#include "Game.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

//Implement Pokemon data、Move data、Game data 、 Test Case format
class DataFormat
{
public:
    /**
     * Intent:Load Pokemon data from file
     * Pre:Pokemon data file name
     * Pos:return pokemons
     */
    bool loadPokemonData(string fileName, Game *game);

    // Intent:  Load move data from file.
    // Pre:     Move data file name.
    // Post:    Print failed if file cannot be opened.
    bool loadMoveData(string fileName, Game *game);

    // Intent:  Load Game data from file.
    // Pre:     Game data file name.
    // Post:    Print failed if file cannot be opened.
    bool loadGameData(string fileName, Game *game);
};
