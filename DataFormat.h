/***********************************************************************
 * File: DataFormat.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/05/29
 * Description: Load Pokemon data from file , Pokemon data , Move data , Game data , Test Case format
***********************************************************************/
#pragma once

#include "Pokemon.h"
#include "Attack.h"
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
     * Pos:return pokemons
     */
    vector<Pokemon>& loadPokemonData(string fileName);
    /**
     * Intent:Load Game data from file 
     * Pre:Game data file name
     * Pos:return players
     */
    vector<Player>& loadGameData(string fileName);
};
