/***********************************************************************
 * File: EnumList.h
 * Author: B11115033
 * Create Date: 2023/05/29
 * Editor: B11115033, B11115016
 * Update Date: 2023/06/
 * Description: This C++ program is to store enum values.
***********************************************************************/
#pragma once

//Pokemon State,Normal,Poison,Burn,Paralysis,Fainting
enum State
{
    NORMAL_STATE,
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

// Move's type.
enum MoveType
{
    PHYSICAL,
    SPECIAL,
    STATUS
};
