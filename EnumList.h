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

// Move's type.
enum MoveType
{
    PHYSICAL,
    SPECIAL,
    STATUS
};
