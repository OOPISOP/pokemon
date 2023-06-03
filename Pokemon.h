/***********************************************************************
 * File: Pokemon.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033, B11115013
 * Update Date: 2023/06/01
 * Description: Define Pokemon
***********************************************************************/
#pragma once
#include "Attack.h"
#include "EnumList.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
//record Pokemon basic data、status、attack、add hp、reduce hp、Potion、Paralysis...


Attribute stringToType(string type);

class Pokemon
{
private:
    bool stateList[5];//Pokemon State List 
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
    Pokemon(string name, vector<Attribute> types, double maxHP, double atk, double def, double spAtk, double spDef, double speed);
    //Pokemon Destructor
    ~Pokemon();

    //Init State
    void initStateList();

    //Getter
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
    //set Pokemon poisoned
    void bePoisoned();
    //set Pokemon paralysis
    void beParalysis();
    //set Pokemon burned
    void beBurned();
    
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

};
