/***********************************************************************
 * File: Move.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/06/
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#include "Move.h"

Move::Move(string name, int attribute, int type, int power, int accuracy, int pp, bool isCon, int con)
{
    this->name = name;
    this->attribute = attribute;
    this->type = type;
    this->power = power;
    this->accuracy = accuracy;
    this->pp = pp;
    this->isCon = isCon;
    this->con = con;
}

string Move::getName()
{
    return name;
}

string Move::getPP()
{
    return type;
}