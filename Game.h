/***********************************************************************
 * File: Game.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/06/14
 * Description: This C++ program is Pokemon Game Manager
***********************************************************************/
#pragma once

#include "Player.h"
#include "Move.h"
#include <QObject>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include<QObject>
#include<QApplication>
#include<QString>
#include<QDebug>

using namespace std;

class Game : public QObject
{
 Q_OBJECT
public:
    bool currentTurn;
    bool isTestMode;
    int turnNumber;
    bool playable;
    bool winOrLose;
    vector<Player> players;
    vector<Pokemon> pokemons;   // Library of Pokemons
    vector<Move> moves;         // Library of Pokemon Move
    string outputFileName;      // For output.txt
    fstream outputFile;         // For output.txt
    stringstream output;        // For output stream
    //Game Constructor
    Game();
    //Game Destructor
    ~Game();

    /**
     * Intent: Execute command
     * Pre:
     * Pos:return true or false
     */
    bool executeCommand(string command);
    bool useBag();
    Q_INVOKABLE bool loadTestCase();
    bool loadTestCase(string fileName);
    Q_INVOKABLE bool loadPokemonData();
    Q_INVOKABLE bool loadMoveData();
    Q_INVOKABLE bool loadGameData();
    void check(bool turn);
    void status();

    /**
     * Intent: Execute command for QString
     * Pre:
     * Pos:return true or false
     */
    Q_INVOKABLE bool executeCommand(QString command);


    // Mange one turn of battle process.
    void battle(string command, bool currentTurn, bool testMode);
    // Find input Pokemon's index.
    int findPokemon(bool turn, string pokemonName);
    // Check whether move exists and find index.
    int findMove(Pokemon &aPokemon, string moveName);
    // Swap Pokemon.
    void swapPokemon(bool turn);
    // Use a potion in bag to a Pokemon.
    void usePotion(bool turn, string targetPokemon, string potionName);
    // Use a move to the opponent Pokemon.
    void useMove(string moveName, bool turn, bool testMode);
    // Check Pokemon's faint status.
    bool checkFainting(bool turn);
    // To check B & P.
    void bAndP();

    // Tell user about Pokemon's story.
    void tellStory();
};



