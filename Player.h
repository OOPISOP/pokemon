/***********************************************************************
 * File: Player.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,
 * Update Date: 2023/05/29
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#pragma once

#include "Pokemon.h"
#include <vector>

using namespace std;

//current Pokemon 、 swap Pokemon 、print all Pokemon status、  check...

class Player
{
private:
public:
    vector<Pokemon> pokemons;
    int currentPokemon;
};
