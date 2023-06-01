/***********************************************************************
 * File: DataFormat.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016, B1115013
 * Update Date: 2023/06/01
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#pragma once
#include "Potion.h"
using namespace std;

//Potion constructor
Potion::Potion()
{
	this->healingAmount = 20;
}

/**
 * intent: get heal amount of potion.
 * Pre: healing amount
 * Pos: return healing amount.
 */
int Potion::getHealAmount()
{
	return healingAmount;
}

/**
 * intent: to update the pokemon HP
 * Pre: the 'Pokemon' passed in the parameter must be a valid 'Pokemon' with valid HP values.
 * Pos: Pokemon's HP restored and message is displayed.
 */
void Potion::update(Pokemon& pokemon) // later write as virtual void update (Pokemon& pokemon);
{
	cout << "You used a Potion!" << endl;
	cout << pokemon.getName() << " had its HP restored." << endl;
	pokemon.restoreHP(healingAmount);
}

/*********************************************************************************************************/

//Super Potion constructor
SuperPotion::SuperPotion()
{
	healingAmount = 60;
}

/**
 * intent: get heal amount of Super Potion.
 * Pre: healing amount
 * Pos: return healing amount.
 */
int SuperPotion::getHealAmount()
{
	return healingAmount;
}

/**
 * intent: to update the Pokemon HP
 * Pre: the 'Pokemon' passed in the parameter must be a valid 'Pokemon' with valid HP values.
 * Pos: Pokemon's HP restored and message is displayed.
 */
void SuperPotion::update(Pokemon& pokemon) // later write as virtual void update (Pokemon& pokemon);
{
	cout << "You used a Super Potion!" << endl;
	cout << pokemon.getName() << " had its HP restored." << endl;
	pokemon.restoreHP(healingAmount);
}

/*********************************************************************************************************************/

//Hyper Potion constructor
HyperPotion::HyperPotion()
{
	healingAmount = 120;
}

/**
 * intent: get heal amount of Hyper Potion.
 * Pre: healing amount
 * Pos: return healing amount.
 */
int HyperPotion::getHealAmount()
{
	return healingAmount;
}

/**
 * intent: to update the Pokemon HP
 * Pre: the 'Pokemon' passed in the parameter must be a valid 'Pokemon' with valid HP values.
 * Pos: Pokemon's HP restored and message is displayed.
 */
void HyperPotion::update(Pokemon& pokemon) // later write as virtual void update (Pokemon& pokemon);
{
	cout << "You used a Hyper Potion!" << endl;
	cout << pokemon.getName() << " had its HP restored." << endl;
	pokemon.restoreHP(healingAmount);
}

/*********************************************************************************************************************/

//Max Potion constructor
MaxPotion::MaxPotion()
{
	Pokemon pokemon;
	healingAmount = pokemon.getMaxHP();
}

/**
 * intent: get heal amount of Max Potion.
 * Pre: healing amount
 * Pos: return healing amount.
 */
int MaxPotion::getHealAmount()
{
	return healingAmount;
}

/**
 * intent: to update the Pokemon HP
 * Pre: the 'Pokemon' passed in the parameter must be a valid 'Pokemon' with valid HP values.
 * Pos: Pokemon's HP restored and message is displayed.
 */
void MaxPotion::update(Pokemon& pokemon) // later write as virtual void update (Pokemon& pokemon);
{
	cout << "You used a Max Potion!" << endl;
	cout << pokemon.getName() << " had its HP restored." << endl;
	pokemon.restoreHP(healingAmount);
}
