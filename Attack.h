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

//normal ~ fairy
const double TYPE_EFFECT[18][18] = {{  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,0.5,  0,  1,  1,0.5,  1},//normal
                                    {  1,0.5,0.5,  1,  2,  2,  1,  1,  1,  1,  1,  2,0.5,  1,0.5,  1,  2,  1},//fire
                                    {  1,  2,0.5,  1,0.5,  1,  1,  1,  2,  1,  1,  1,  2,  1,0.5,  1,  1,  1},//water
                                    {  1,  1,  2,0.5,0.5,  1,  1,  1,  0,  2,  1,  1,  1,  1,0.5,  1,  1,  1},//eleftric
                                    {  1,0.5,  2,  1,0.5,  1,  1,0.5,  2,0.5,  1,0.5,  2,  1,0.5,  1,0.5,  1},//grass
                                    {  1,0.5,0.5,  1,  2,0.5,  1,  1,  2,  2,  1,  1,  1,  1,  2,  1,0.5,  1},//ice
                                    {  2,  1,  1,  1,  1,  2,  1,0.5,  1,0.5,0.5,0.5,  2,  0,  1,  2,  2,0.5},//fighting
                                    {  1,  1,  1,  1,  2,  1,  1,0.5,0.5,  1,  1,  1,0.5,0.5,  1,  1,  0,  2},//poison
                                    {  1,  2,  1,  2,0.5,  1,  1,  2,  1,  0,  1,0.5,  2,  1,  1,  1,  2,  1},//ground
                                    {  1,  1,  1,0.5,  2,  1,  2,  1,  1,  1,  1,  2,0.5,  1,  1,  1,0.5,  1},//flying
                                    {  1,  1,  1,  1,  1,  1,  2,  2,  1,  1,0.5,  1,  1,  1,  1,  0,0.5,  1},//psychic
                                    {  1,0.5,  1,  1,  2,  1,0.5,0.5,  1,0.5,  2,  1,  1,0.5,  1,  2,0.5,0.5},//bug
                                    {  1,  2,  1,  1,  1,  2,0.5,  1,0.5,  2,  1,  2,  1,  1,  1,  1,0.5,  1},//rock
                                    {  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  1,  1,  2,  1,0.5,  1,  1},//ghost
                                    {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  1,0.5,  0},//dragon
                                    {  1,  1,  1,  1,  1,  1,0.5,  1,  1,  1,  2,  1,  1,  2,  1,0.5,  1,0.5},//dark
                                    {  1,0.5,0.5,0.5,  1,  2,  1,  1,  1,  1,  1,  1,  2,  1,  1,  1,0.5,  2},//steel
                                    {  1,0.5,  1,  1,  1,  1,  2,0.5,  1,  1,  1,  1,  1,  1,  2,  2,0.5,  1}//fairy
                                   };

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
