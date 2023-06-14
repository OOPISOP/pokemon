/***********************************************************************
 * File: Pokemon.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033, B11115013
 * Update Date: 2023/06/14
 * Description: Define Pokemon
***********************************************************************/
#pragma once

#include "EnumList.h"
#include "Move.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Attribute stringToType(string type);
string stateToString(int state);

//record Pokemon basic data、status、attack、add hp、reduce hp、Potion、Paralysis...
class Pokemon
{
private:
    vector<bool> stateList;//Pokemon State List
    string name;//Pokemon Name
    vector<Attribute> types;//Pokemon Type
    vector<Move> moves;//Pokemon Attack
    double maxHP;//Pokemon Max HP
    double hp;//Pokemon HP
    double atk;//Pokemon Attack
    double def;//Pokemon Defense
    double spAtk;//Pokemon Special Attack
    double spDef;//Pokemon Special Defense
    double speed;//Pokemon Speed

public:
    // For Effevive message.
    float effectiveness;
    //Pokemon Constructor
    Pokemon();
    Pokemon(string name, vector<Attribute> types, double maxHP, double atk, double def, double spAtk, double spDef, double speed);
    //Pokemon Destructor
    ~Pokemon();

    // Assign operator.
    Pokemon& operator=(Pokemon &aPokemon);

    //Init State
    void initStateList();

    //Getter
    //get Pokemon Name
    string getName()const;
    //get Pokemon Types
    vector<Attribute> getTypes()const;
    //get Pokemon HP
    double getHp()const;
    //get Pokemon Max HP
    double getMaxHP()const;
    //get Pokemon Attack
    double getAtk()const;
    //get Pokemon Defense
    double getDef()const;
    //get Pokemon Special Attack
    double getSpAtk()const;
    //get Pokemon Special Defense
    double getSpDef()const;
    //get Pokemon Speed
    double getSpeed()const;
    // Get Pokemon Moves
    vector<Move> getMoves()const;
    vector<bool> getStateList()const;
    //Setter
    //set Pokemon poisoned
    void bePoisoned(bool turn, int turnNumber);
    //set Pokemon paralysis
    void beParalysis(bool turn, int turnNumber);
    //set Pokemon burned
    void beBurned(bool turn, int turnNumber);

    void setMoves(vector<Move>& moves);
    
    //Pokemon receive damage
    void receiveDamage(double damage);
    //Pokemon reduce speed
    void reduceSpeed(double speed);
    //restoring Pokemon HP
    void restoreHP(double amount);

    //check Pokemon Status Poisoned
    bool isPoisoned();
    //check Pokemon Status Paralysis
    bool isParalysis();
    //check Pokemon Status Burned
    bool isBurned();

    //poison attack 
    void poisonAttack(Pokemon& target);
    //paralysis attack 
    void paralysisAttack(Pokemon& target);
    //burn attack 
    void burnAttack(Pokemon& target);

    double effectDamage();

    //apply burn or poison effect
    void applyNegativeEffect();

    //use move
    bool useMove(Pokemon& target, int moveIndex, int turnNumber, bool turn, bool testMode);
};
