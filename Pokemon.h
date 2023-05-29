/***********************************************************************
 * File: Pokemon.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/05/29
 * Description: Define Pokemon
***********************************************************************/
#pragma once

#include "DataFormat.h"
#include "StatusEffect.h"
#include "Attack.h"
#include "Poison.h"
#include "Burn.h"
#include "Potion.h"
#include <string>
#include <vector>
using namespace std;
//record Pokemon basic data、status、attack、add hp、reduce hp、Potion、Paralysis...

//Pokemon State,Normal,Poison,Burn,Paralysis,Fainting
enum State
{
    NORMAL,
    POISON,
    BURN,
    PARALYSIS,
    FAINTING
};
//attribute
enum Attribute
{
    NORMAL,
    FIRE,
    WATER,
    ELECTRIC,
    GRASS,
    ICE,
    FIGHTING,
    POISON,
    GROUND,
    FLYING,
    PSYCHIC,
    BUG,
    ROCK,
    GHOST,
    DRAGON,
    DARK,
    STEEL,
    FAIRY
};

Attribute stringToType(string type);

class Pokemon
{
private:
    State state;//Pokemon State
    string name;//Pokemon Name
    vector<Attribute> types;//Pokemon Type
    vector<Attack> attacks;//Pokemon Attack
    double maxHP;//Pokemon Max HP
    double hp;//Pokemon HP
    double atk;//Pokemon Attack
    double def;//Pokemon Defense
    double spAtk;//Pokemon Special Attack
    double spDef;//Pokemon Special Defense
    double speed;//Pokemon Speed
public:
    //Pokemon Constructor
    Pokemon(State state, string name, vector<Attribute> types, double maxHP, double atk, double def, double spAtk, double spDef, double speed);
    //Pokemon Destructor
    ~Pokemon();
    //Getter
    //get Pokemon State
    State getState();
    //get Pokemon Name
    string getName();
    //get Pokemon Types
    vector<Attribute> getTypes();
    //get Pokemon HP
    double getHp();
    //get Pokemon Max HP
    double getMaxHP();
    //get Pokemon Attack
    double getAtk();
    //get Pokemon Defense
    double getDef();
    //get Pokemon Special Attack
    double getSpAtk();
    //get Pokemon Special Defense
    double getSpDef();
    //get Pokemon Speed
    double getSpeed();
    //Setter
    //set Pokemon State
    void setState(State state);
    //Pokemon receive damage
    void receiveDamage(double damage);
    //Pokemon reduce speed
    void reduceSpeed(double speed);
};
