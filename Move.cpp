/***********************************************************************
 * File: Move.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016, B11115033
 * Update Date: 2023/06/14
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#include "Move.h"
#include "Pokemon.h"

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

/**
 * Intent:get move name
 * Pos:return move name
 */
string Move::getName()const
{
    return this->name;
}
/**
 * @brief Move::getCon
 * @return this->con
 */
int Move::getCon()const
{
    return this->con;
}
/**
 * @brief Move::getPP
 * @return
 */
int Move::getPP()const
{
    return this->pp;
}
/**
 * @brief Move::reducePP
 */
void Move::reducePP()
{
    this->pp--;
}

/**
 * @brief Move::calcDamage
 * @param user
 * @param target
 * @return move damage
 */
int Move::calcDamage(Pokemon& user,const Pokemon& target, int moveType)
{
    float stab = 1;
    float typeTime = 1;
    for(const auto& userType : user.getTypes())//if user type equal to move type stab = 1.5,otherwise = 1
    {
        if(type == userType)
        {
            stab = 1.5;
            break;
        }
    }
    for(const auto&  time : target.getTypes())//type times calc
    {
        typeTime *= TYPE_EFFECT[type][time];
    }

    user.effectiveness = typeTime;
    cout << type << endl;
    cout << time << endl;
    cout << user.effectiveness << endl;


    int damage;
    if (moveType == PHYSICAL)
    {
        damage = (int)(0.44*power*(user.getAtk()/target.getDef())+2)*critical*stab*typeTime;//damage calc
    }
    else if (moveType == SPECIAL)
    {
        damage = (int)(0.44*power*(user.getSpAtk()/target.getSpDef())+2)*critical*stab*typeTime;//damage calc
    }

    return damage;
}

