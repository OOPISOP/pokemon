/***********************************************************************
 * File: Game.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/06/
 * Description: This C++ program is Pokemon Game Manager
***********************************************************************/
#pragma once

#include "Player.h"
#include "EnumList.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

class Game
{
public:
    // Variables.
    bool currentTurn;
    vector<Player> players;
    vector<Pokemon> pokemons;


    //Game Constructor
    Game();
    //Game Destructor
    ~Game();
    /**
     * Intent: Execute command
     * Pre:
     * Pos:return true or false 
     */
    void executeCommand(string command);
};
