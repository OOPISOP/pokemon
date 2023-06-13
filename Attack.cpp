/***********************************************************************
 * File: Attack.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,
 * Update Date: 2023/06/
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#include "Attack.h"

// constructor to initialize the attack member variable
Attack::Attack()
{
	this->fixDmg = 0.44;
	this->resDmg = 0;
	this->found = false;
}

const float tableTypeEffectiveness[TYPESIZE][TYPESIZE] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0, 1, 1, 0.5, 1},
	{1, 0.5, 0.5, 1, 2, 2, 1, 1, 1, 1, 1, 2, 0.5, 1, 0.5, 1, 2, 1},
	{1, 2, 0.5, 1, 0.5, 1, 1, 1, 2, 1, 1, 1, 2, 1, 0.5, 1, 1, 1},
	{1, 1, 2, 0.5, 0.5, 1, 1, 1, 0, 2, 1, 1, 1, 1, 0.5, 1, 1, 1},
	{1, 0.5, 2, 1, 0.5, 1, 1, 1, 0.5, 2, 0.5, 1, 0.5, 2, 1, 0.5, 1, 0.5, 1},
	{1, 0.5, 0.5, 1, 2, 0.5, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, 0.5, 1},
	{2, 1, 1, 1, 1, 2, 1, 0.5, 1, 0.5, 0.5, 0.5, 2, 0, 1, 2, 2, 0.5},
	{1, 1, 1, 1, 2, 1, 1, 0.5, 0.5, 1, 1, 1, 0.5, 0.5, 1, 1, 0, 2},
	{1, 2, 1, 2, 0.5, 1, 1, 2, 1, 0, 1, 0.5, 2, 1, 1, 1, 2, 1},
	{1, 1, 1, 0.5, 2, 1, 2, 1, 1, 1, 1, 2, 0.5, 1, 1, 1, 0.5, 1},
	{1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 0.5, 1, 1, 1, 1, 0, 0.5, 1},
	{1, 0.5, 1, 1, 2, 1, 0.5, 0.5, 1, 0.5, 2, 1, 1, 0.5, 1, 2, 0.5, 0.5},
	{1, 2, 1, 1, 1, 2, 0.5, 1, 0.5, 2, 1, 2, 1, 1, 1, 1, 0.5, 1},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 0.5, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 0.5, 0},
	{1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 2, 1, 1, 2, 1, 0.5, 1, 0.5},
	{1, 0.5, 0.5, 0.5, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0.5, 2},
	{1, 0.5, 1, 1, 1, 1, 2, 0.5, 1, 1, 1, 1, 1, 1, 2, 2, 0.5, 1},
};

double Attack::getAtk()
{

}

double Attack::getPower()
{

}

//double getEffectiveness(string& defense, string& attack) // water grass
//{
//	typeAmount = tableTypeEffectiveness[defense][attack]; // tableTypeEffectiveness[2][4] = 2
//	return typeAmount;
//}

double Attack::calculateDmg(string& moveNames, int currentTurn)
{
	name1 = moveNames; // VineWhip (venusaur used VineWhip) /*process before: the current pokemon will cin the skill it want to take, 
	/*then after cin, it will call the calculatedmg func with current turn to obtain its power, type of each player and opponent turn*/

	//int defense = 0;

	// 1. get the attribute, type, power, accuracy, pp from the MOVE cin by user ->(vineWhip) 
	for (const auto& m : moves)
	{
		string currentName = m.name; 
		if (currentName == name1) // name1 = venusaur skills -> VineWhip
		{
			found = true;
			if (found)
			{
				attributeatk = m.attribute; // Grass
				type = m.type; // physical
				power = m.power; // 45
				accuracy = m.accuracy; // 100
				pp = m.pp; // 25
				// stores all of this in vector/array with index currentTurn, so if it's player turn, it will store the data in index 0, if opponent turn stored index 1

			}
		}
	}
	
	// 1. attack -> currentTurn, def -> !curTurn
	this->atk = Game.player[currentTurn].pokemons[currentPokemon].getAtk(); // venusaur atk amount
	this->def = Game.player[!currentTurn].pokemons[currentPokemon].getDef(); // blastoise atk amount
	//this->attatk = Game.player[currentTurn].pokemons[currentPokemon].getTypes(); // get the attribute attack -> grass
	this->attdef = Game.player[!currentTurn].pokemon[currentPokemon].getTypes(); // get the attribute def -> water

	typeAmount = tableTypeEffectiveness[attdef][attributeatk]; // tableTypeEffectiveness[2][4] = 2 // [(pokemon's defense turn) att][move atk att]


	// formula 
	//resDmg = (fixDmg * power * A / D + 2) * critical * STAB * type;
	resDmg = (fixDmg * power * atk / def + 2) * * *typeAmount;

}

