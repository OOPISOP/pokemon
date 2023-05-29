/***********************************************************************
 * File: Burn.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/05/29
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#pragma once

#include "StatusEffect.h"
#include "Pokemon.h"

//Inherit StatusEffect

class Burn : public StatusEffect
{
public:
    //Burn constructor
    Burn(State state);
    //init effect
    virtual void applyEffect(Pokemon& pokemon) override ;
    //calculate damage
    virtual void calculateDamage(Pokemon& pokemon) override;
};
