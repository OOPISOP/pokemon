/***********************************************************************
 * File: DataFormat.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016, B11115013
 * Update Date: 2023/06/14
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#pragma once

#include "Pokemon.h"
using namespace std;

class Potion 
{
protected:
	int healingAmount;

public:

	//constructor.
	Potion();

	//get heal amount.
	int getHealAmount();

	//Redefinied function.
	virtual void update(Pokemon& pokemon);
};


class SuperPotion : public Potion
{
private:

public:
	//constructor.
	SuperPotion();
	
	//get heal amount.
	int getHealAmount();

	//Redefinied function.
	void update(Pokemon& pokemon) override;
};

class HyperPotion : public Potion
{
private:

public:
	//constructor.
	HyperPotion();

	//get heal amount.
	int getHealAmount();

	//Redefinied function.
	void update(Pokemon& pokemon) override;
};

class MaxPotion : public Potion
{
private:

public:
	//constructor.
	MaxPotion();

	//get heal amount.
	int getHealAmount();

	//Redefinied function.
	void update(Pokemon& pokemon) override;
};
