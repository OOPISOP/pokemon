/***********************************************************************
 * File: main.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/06/
 * Description: This C++ program is to Test Pokemons' battle ability.
***********************************************************************/
#include "main.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


/**
 * Intent: Run CLI
 * Pre: Start Program
 * Post: End Program
*/
void runCommandLine()
{
    // Variables.
    Game game;
    DataFormat dataFormat;
    string fileName;
    fstream testCaseFile;
    string commandLine;

    // Initialise testcase.
    std::cin >> fileName;
    testCaseFile.open(fileName);
    //Error Proof
    if(!testCaseFile.is_open())
    {
        cout<< "The input testcase: \"" << fileName << "\" cannot be opened." << endl;
        return;
    }

    // Initialise pokemon library.
    testCaseFile >> fileName;
    dataFormat.loadPokemonData(fileName, &game);

    // Initialise move library.
    testCaseFile >> fileName;
    dataFormat.loadMoveData(fileName, &game);

    // Initialise game data.
    testCaseFile >> fileName;
    dataFormat.loadGameData(fileName, &game);

//    // Read commands.
//    while(getline(testCaseFile,commandLine))
//    {
//        game.executeCommand(commandLine);
//    }

    testCaseFile.close();
}
/**
 * Intent: Run GUI
 * Pre: Start Program
 * Post: End Program
*/
int runGUI(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // 註冊C++ class
    qmlRegisterType<Game>("com.game", 1, 0, "Game");

    // Load QML
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}

int main(int argc, char** argv)
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
