/***********************************************************************
 * File: Game.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/05/29
 * Description: This C++ program is Pokemon Game Manager
***********************************************************************/
#include "Game.h"
#include "DataFormat.h"
#include <QApplication>
#include <QFileDialog>
#include <fstream>
#include <QTemporaryFile>
#include <filesystem>

//Game Constructor

Game::Game()
{
    isTestMode = false;
    Player player;
    Player opponent;
    players.push_back(player);
    players.push_back(opponent);
}
//Game Destructor
Game::~Game()
{

}
/**
 * Intent: Execute command for QString
 * Pre:
 * Pos:return true or false
 */
bool Game::executeCommand(QString command)
{
    string stdString = command.toStdString();
    if(executeCommand(stdString))
    {
        return true;
    }
    return false;
}

/**
 * Intent: Execute command
 * Pre:
 * Pos:return true or false 
 */
bool Game::executeCommand(string command)
{
    if(command == "Load TestCase")
    {
        try
        {
            QString filePath = QFileDialog::getOpenFileName(
                nullptr,  // 父窗口，如果没有父窗口可以传入nullptr
                "选择文件",  // 对话框标题
                QDir::homePath(),  // 默认打开的目录
                "文本文件 (*.txt);;所有文件 (*)"  // 文件过滤器
                );

            if (!filePath.isEmpty()) {
                qDebug() << "选择的文件路径：" << filePath;
            } else {
                qDebug() << "未选择任何文件";
            }
            ifstream file(filePath.toStdString());
            string line;
            while(getline(file,line))
            {
                executeCommand(line);
            }
        }
        catch (const int error_code)
        {
            cout<<error_code<<endl;
        }

        return true;
    }
    if(command.empty())
    {
        return false;
    }
    if(pokemons.empty())
    {
        DataFormat data;
        data.loadPokemonData(command,this);
        return true;
    }
    if(moves.empty())
    {
        DataFormat data;
        data.loadMoveData(command,this);
        return true;
    }
    if(players.empty())
    {
        DataFormat data;
        data.loadGameData(command,this);
        return true;
    }

    //Error Proof
    try
    {
        if(command == "Bag")
        {
            cout<<"Bag"<<endl;
        }
        else if(command == "Pokemon")
        {

        }
        else if(command == "Battle")
        {

        }
        else if(command == "Check")
        {

        }
        else if(command == "Status")
        {

        }
        else if(command == "Run")
        {

        }
        else if(command == "Test")
        {
            isTestMode = true;
        }
    }
    catch(int failed)
    {
        cout << "Failed" << endl;
        return false;
    }
    
    return true;
}
