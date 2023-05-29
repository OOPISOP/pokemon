/***********************************************************************
 * File: StatusEffect.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/05/29
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#pragma once

#include "Pokemon.h"

//abstract class，Manage Burn、Poison

class StatusEffect
{
protected:
    State state;
    double damage;
public:
    //StatusEffect constructor
    StatusEffect(State state);
    //init effect 
    virtual void applyEffect(Pokemon& pokemon) = 0;
    //calculate damage
    virtual void calculateDamage(Pokemon& pokemon) = 0;
};
