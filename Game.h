/***********************************************************************
 * File: Game.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/06/
 * Description: This C++ program is Pokemon Game Manager
***********************************************************************/
#pragma once
#include "Player.h"
#include "EnumList.h"
#include "Move.h"
#include <QObject>
#include <string>
#include <vector>
#include <sstream>
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
    vector<Player> players;
    vector<Pokemon> pokemons;
    vector<Move> moves;//Pokemon Move
    bool isTestMode;
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

    /**
     * Intent: Execute command for QString
     * Pre:
     * Pos:return true or false
     */
    Q_INVOKABLE bool executeCommand(QString command);

};
