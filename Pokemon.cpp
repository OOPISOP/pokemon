/***********************************************************************
 * File: Pokemon.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016, B11115033, B11115013
 * Update Date: 2023/06/01
 * Description: Implement Pokemon
***********************************************************************/
#include "Pokemon.h"

Attribute stringToType(string type)
{
    if(type=="Normal")
    {
        return NORMAL;
    }
    else if(type=="Fire")
    {
        return FIRE;
    }
    else if(type=="Water")
    {
        return WATER;
    }
    else if(type=="Electric")
    {
        return ELECTRIC;
    }
    else if(type=="Grass")
    {
        return GRASS;
    }
    else if(type=="Ice")
    {
        return ICE;
    }
    else if(type=="Fighting")
    {
        return FIGHTING;
    }
    else if(type=="Poison")
    {
        return POISON;
    }
    else if(type=="Ground")
    {
        return GROUND;
    }
    else if(type=="Flying")
    {
        return FLYING;
    }
    else if(type=="Psychic")
    {
        return PSYCHIC;
    }
    else if(type=="Bug")
    {
        return BUG;
    }
    else if(type=="Rock")
    {
        return ROCK;
    }
    else if(type=="Ghost")
    {
        return GHOST;
    }
    else if(type=="Dragon")
    {
        return DRAGON;
    }
    else if(type=="Dark")
    {
        return DARK;
    }
    else if(type=="Steel")
    {
        return STEEL;
    }
    else if(type=="Fairy")
    {
        return FAIRY;
    }
    else
    {
        return NORMAL;
    }
}

//Pokemon Constructor
Pokemon::Pokemon(State state, string name, vector<Attribute> types, double maxHP, double atk, double def, double spAtk, double spDef, double speed)
{
    this->state = state;
    this->name = name;
    this->types = types;
    this->maxHP = maxHP;
    this->hp = maxHP;
    this->atk = atk;
    this->def = def;
    this->spAtk = spAtk;
    this->spDef = spDef;
    this->speed = speed;
}
//Pokemon Destructor
Pokemon::~Pokemon()
{

}

//Getter
/**
 * Intent: Get Pokemon Name
 * Pre: name
 * Pos: return Pokemon Name
 */
string Pokemon::getName()
{
    return this->name;
}
/**
 * Intent: Get Pokemon Type
 * Pre: types
 * Pos: return Pokemon Type
 */
vector<Attribute> Pokemon::getTypes()
{
    return this->types;
}
/**
 * Intent: Get Pokemon State
 * Pre: state
 * Pos: return Pokemon State
 */
State Pokemon::getState()
{
    return this->state;
}
/**
 * Intent: Get Pokemon Hp
 * Pre: hp
 * Pos: return Pokemon Hp
 */
double Pokemon::getHp()
{
    return this->hp;
}
/**
 * Intent: Get Pokemon Max HP
 * Pre: maxHP
 * Pos: return Pokemon Max HP
 */
double Pokemon::getMaxHP()
{
    return this->maxHP;
}
/**
 * Intent: Get Pokemon Attack
 * Pre: atk
 * Pos: return Pokemon Atk
 */
double Pokemon::getAtk()
{
    return this->atk;
}

/**
 * Intent: Get Pokemon Defense
 * Pre: def
 * Pos: return Pokemon Def
 */
double Pokemon::getDef()
{
    return this->def;
}
/**
 * Intent: Get Pokemon Special Attack
 * Pre: spAtk
 * Pos: return Pokemon Special Attack
 */
double Pokemon::getSpAtk()
{
    return this->spAtk;
}
/**
 * Intent: Get Pokemon Special Defense
 * Pre: spDef
 * Pos: return Pokemon Special Defense
 */
double Pokemon::getSpDef()
{
    return this->spDef;
}
/**
 * Intent: Get Pokemon Speed
 * Pre: speed
 * Pos: return Pokemon Speed
 */
double Pokemon::getSpeed()
{
    return this->speed;
}
//Setter
/**
 * Intent: Set Pokemon State
 * Pre: pokemonState
 * Pos: Set Pokemon State
 */
void Pokemon::setState(State state)
{
    this->state = state;
}
/**
 * Intent: Pokemon receive damage so reduce Pokemon Hp
 * Pre: pokemonHp and damage
 * Pos: reduce Pokemon Hp and if Pokemon Hp < 0, Pokemon Hp = 0 and reset Pokemon state
 */
void Pokemon::receiveDamage(double damage)
{
    this->hp -= damage;
    if(this->hp < 0)
    {
        this->hp = 0;
        this->state = FAINTING;
    }
}
/**
 * Intent: Pokemon receive damage so reduce Pokemon Speed
 * Pre: Pokemon Speed
 * Pos: reduce Pokemon Speed
 */
void Pokemon::reduceSpeed(double speed)
{
    this->speed -= speed;
    if(speed < 0)
    {
        this->speed = 0;
    }
}

/**
 * Intent: Pokemon received potion so HP is healed
 * Pre: Pokemon HP
 * Pos: increase the Pokemon HP
 */
void Pokemon::restoreHP(double amount)
{
    hp += amount;
    if (HP > maxHP)
    {
        hp = maxHP;
    }
}
