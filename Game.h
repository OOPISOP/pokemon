/***********************************************************************
 * File: Game.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/05/29
 * Description: This C++ program is Pokemon Game Manager
***********************************************************************/
#pragma once

#include "Player.h"
#include "EnumList.h"
<<<<<<< Updated upstream
#include "DataFormat.h"
=======
#include "Move.h"
>>>>>>> Stashed changes
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Game
{
private:
    vector<Player> players;
    vector<Pokemon> pokemons;
<<<<<<< Updated upstream
public:
=======
    vector<Move> moves;//Pokemon Move
    bool isTestMode;

>>>>>>> Stashed changes
    //Game Constructor
    Game();
    //Game Destructor
    ~Game();

    /**
     * Intent: Execute command
     * Pre:
     * Pos:return true or false 
     */
<<<<<<< Updated upstream
    bool executeCommand(string command);  
=======
    bool executeCommand(string command);
>>>>>>> Stashed changes
};
