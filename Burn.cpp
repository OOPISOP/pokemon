/***********************************************************************
 * File: Burn.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/05/29
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#include "Burn.h"

//Burn constructor
Burn::Burn(State state) : StatusEffect(state)
{
   
}

void Burn::applyEffect(Pokemon& pokemon)
{
   this->damage = pokemon.getMaxHP() * (1/16);
}

void Burn::calculateDamage(Pokemon& pokemon)
{
     pokemon.receiveDamage(this->damage);
}
