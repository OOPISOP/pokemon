/***********************************************************************
 * File: Attack.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/06/
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#pragma once
#include "EnumList.h"
#include <string>
using namespace std;

//Implement damage logic

class Attack
{
private:
    string name;
    Attribute type;
    double power;
    double accuracy;
    int PP;
    double damage;
public:
};
