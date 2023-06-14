/***********************************************************************
 * File: main.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016, B11115033
 * Update Date: 2023/06/14
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#include "main.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTemporaryFile>

/**
 * Intent: Run CLI
 * Pre: Start Program
 * Post: End Program
*/
void runCommandLine()
{
    srand(time(NULL));

    Game game;
    string commandLine;

    // Tell a short background story about Pokemon.
   // game.tellStory();
    // Read commands.
    while(getline(cin,commandLine))
    {
        game.executeCommand(commandLine);
        if (game.playable == false)
        {
            break;
        }
    }

}
/**
 * Intent: Run GUI
 * Pre: Start Program
 * Post: End Program
*/
int runGUI(int argc, char** argv)
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    // 註冊C++ class
    qmlRegisterType<Game>("com.game", 1, 0, "Game");

    // Load QML
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}

int main(int argc, char* argv[])
{

    if(argc == 1)
    {
       return runGUI(argc,argv);
    }
    else if (string(argv[1]) == string("CommandInput") && argc == 2)
    {
        //執行指令輸入模式
        runCommandLine();
    }
	return 0;
}
