/***********************************************************************
 * File: Player.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,
 * Update Date: 2023/06/
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#pragma once

#include "EnumList.h"
#include <string>

using namespace std;

class Move
{
public:
    string name;
    int attribute;
    int type;
    int power;
    int accuracy;
    int pp;
    bool isCon;
    int con;

    Move(string name, int attribute, int type, int power, int accuracy, int pp, bool isCon, int con);
    string getName();
    string getPP();

};
