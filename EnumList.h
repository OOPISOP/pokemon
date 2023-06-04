/***********************************************************************
 * File: EnumList.h
 * Author: B11115016
 * Create Date: 2023/06/04
 * Editor: B11115016,
 * Update Date: 2023/06/
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#pragma once

//Pokemon State,Normal,Poison,Burn,Paralysis,Fainting
enum State
{
    POISON_STATE,
    BURN_STATE,
    PARALYSIS_STATE,
    FAINTING_STATE
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

// Turn management.
enum Turn
{
    PLAYER_TURN,
    OPPONENT_TURN
};
