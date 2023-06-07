/***********************************************************************
 * File: Attack.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016, B11115033, B11115013
 * Update Date: 2023/06/
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#pragma once
#include "EnumList.h"
#include "move.h"
#include "Game.h"
#include <string>
#include <vector>
#define TYPESIZE 18;
using namespace std;

//Implement damage logic

class Attack
{
private:
    string name1;
    Attribute attribute;
    int type;
    int atk;
    int def;
    double power;
    double accuracy;
    int PP;
    double damage;
    double fixDmg;
    double resDmg;
    bool found;
    string attatk;
    string attdef;
    string attributeatk;
    double typeAmount;

public:
    Attack();
	double tableTypeEffectiveness[TYPESIZE][TYPESIZE];
    double getPower();
    double getAtk();
    double calculateDmg(string& moveNames);
    
};
