/***********************************************************************
 * File: Pokemon.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016, B11115033, B11115013
 * Update Date: 2023/06/
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
Pokemon::Pokemon()
{
}
Pokemon::Pokemon(string name, vector<Attribute> types, double maxHP, double atk, double def, double spAtk, double spDef, double speed)
{   
    initStateList();
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
//Init State
void Pokemon::initStateList()
{
   for(auto& i : this->stateList)
   {
       i = false;
   }
}

// Assign operator.
Pokemon& Pokemon::operator=(Pokemon &aPokemon)
{
   this->name = aPokemon.name;
   this->types = aPokemon.types;
   this->maxHP = aPokemon.maxHP;
   this->atk = aPokemon.atk;
   this->def = aPokemon.def;
   this->spAtk = aPokemon.spAtk;
   this->spDef = aPokemon.spDef;
   this->speed = aPokemon.speed;
}

//Getter
/**
 * Intent: Get Pokemon Name
 * Pre: name
 * Pos: return Pokemon Name
 */
string Pokemon::getName()const
{
    return this->name;
}
/**
 * Intent: Get Pokemon Type
 * Pre: types
 * Pos: return Pokemon Type
 */
vector<Attribute> Pokemon::getTypes()const
{
    return this->types;
}
/**
 * Intent: Get Pokemon Hp
 * Pre: hp
 * Pos: return Pokemon Hp
 */
double Pokemon::getHp()const
{
    return this->hp;
}
/**
 * Intent: Get Pokemon Max HP
 * Pre: maxHP
 * Pos: return Pokemon Max HP
 */
double Pokemon::getMaxHP()const
{
    return this->maxHP;
}
/**
 * Intent: Get Pokemon Attack
 * Pre: atk
 * Pos: return Pokemon Atk
 */
double Pokemon::getAtk()const
{
    return this->atk;
}

/**
 * Intent: Get Pokemon Defense
 * Pre: def
 * Pos: return Pokemon Def
 */
double Pokemon::getDef()const
{
    return this->def;
}
/**
 * Intent: Get Pokemon Special Attack
 * Pre: spAtk
 * Pos: return Pokemon Special Attack
 */
double Pokemon::getSpAtk()const
{
    return this->spAtk;
}
/**
 * Intent: Get Pokemon Special Defense
 * Pre: spDef
 * Pos: return Pokemon Special Defense
 */
double Pokemon::getSpDef()const
{
    return this->spDef;
}
/**
 * Intent: Get Pokemon Speed
 * Pre: speed
 * Pos: return Pokemon Speed
 */
double Pokemon::getSpeed()const
{
    return this->speed;
}
//Setter
//set Pokemon poisoned
void Pokemon::bePoisoned()
{
    this->stateList[State::POISON_STATE] = true;
    cout<<"<"<<this->name<<"> was poisoned!"<<endl;
}
//set Pokemon paralysis
void Pokemon::beParalysis()
{
    this->stateList[State::PARALYSIS_STATE] = true;
     cout<<"<"<<this->name<<"> is paralyzed, so it may be unable to move!"<<endl;
    
}
//set Pokemon burned
void Pokemon::beBurned()
{
    this->stateList[State::BURN_STATE] = true;
    cout<<"<"<<this->name<<"> was burned!"<<endl;
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
        this->stateList[State::FAINTING_STATE] = true;
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
    if (hp > maxHP)
    {
        hp = maxHP;
    }
}
/**
 * Intent:check Pokemon Status Poisoned
 * Pre:
 * Pos:return POISON_STATE
*/
bool Pokemon::isPoisoned()
{
    return stateList[State::POISON_STATE];
}
/**
 * Intent:check Pokemon Status Paralysis
 * Pre:
 * Pos:return PARALYSIS_STATE
*/
bool Pokemon::isParalysis()
{
    return stateList[State::PARALYSIS_STATE];
}

/**
 * Intent:check Pokemon Status burn
 * Pre:
 * Pos:return BURN_STATE
*/
bool Pokemon::isBurned()
{
    return stateList[State::BURN_STATE];
}

void Pokemon::setMoves(vector<Move>& moves)
{
    this->moves = moves;
}

/**
 * Intent:poison attack
 * Pre:target pokemon
 * Pos:target be poison
*/
void Pokemon::poisonAttack(Pokemon& target)
{
    target.bePoisoned();
}
/**
 * Intent:paralysis attack
 * Pre:target pokemon
 * Pos:target be paralysis
*/
void Pokemon::paralysisAttack(Pokemon& target)
{   
    target.beParalysis();
}
/**
 * Intent:burn attack
 * Pre:target pokemon
 * Pos:target be burned
*/
void Pokemon::burnAttack(Pokemon& target)
{
    target.beBurned();
}
/**
 * Intent:effect Damage
 * Pre:
 * Pos:return hp/16
*/
double Pokemon::effectDamage()
{
    return  getMaxHP() * (1/16);
}

/**
 * Intent:apply Burn or Poison
 * Pre:
 * Pos:recieve Damage by burn or poison
*/
void Pokemon::applyNegativeEffect()
{
    if(isPoisoned())
    {
        cout<<"<"<<this->name<<"> is hurt by its poisoning!"<<endl;
        receiveDamage(effectDamage());
    }
    else if(isBurned())
    {
        cout<<"<"<<this->name<<"> is hurt by its burn!"<<endl;
        receiveDamage(effectDamage());
    }
}
/**
 * @brief Pokemon::userMove
 * @param target
 * @param moveIndex
 */
bool Pokemon::userMove(Pokemon& target,int moveIndex)
{
    if(moves[moveIndex].getPP() <= 0)return false;
    if(moves[moveIndex].getCon() > 0)
    {
        int con = moves[moveIndex].getCon();
        if(con == POISON_STATE)
        {
            target.bePoisoned();
        }
        else if(con == BURN_STATE)
        {
            target.beBurned();
        }
        else if(con == PARALYSIS_STATE)
        {
            target.beParalysis();
        }
    }
    int damage = moves[moveIndex].calcDamage(*this,target);
    target.receiveDamage(damage);
    moves[moveIndex].reducePP();
    cout<<"<"<<this->name<<"> used <"<<moves[moveIndex].getName()<<">!"<<endl;
    return true;
}


