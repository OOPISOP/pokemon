/***********************************************************************
 * File: DataFormat.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/05/29
 * Description:  Load Pokemon data from file , Pokemon data , Move data , Game data , Test Case format
***********************************************************************/
#include "DataFormat.h"


/**
 * Intent:Load Pokemon data from file
 * Pre:Pokemon data file name
 * Pos:return pokemons
 */
bool DataFormat::loadPokemonData(string fileName, Game *game)
{
    ifstream pokemonData(fileName);
    //Error Proof
     if(!pokemonData.is_open())
     {
        cout<<fileName<<" Can't Open"<<endl;
        return false;
     }
     game->pokemons.clear();
    string line;
    while(getline(pokemonData,line))
    {
        vector<string>lines;//data lines
        string firstLine = line;//record first line
        getline(pokemonData,line);
        string secondLine = line;
        getline(pokemonData,line);
        string thirdLine = line;
        string part;
        vector<string> parts;
        int typeN;//type N
        vector<Attribute> pokemonTypes;
        stringstream second(secondLine);
        stringstream third(thirdLine);
        while(getline(second,part,' '))//get all parts of second line
        {
            parts.push_back(part);
        }
        typeN = parts.size();//get type N
        for(int i=0;i<typeN;i++)//set type
        {
            pokemonTypes.push_back(stringToType(parts[i]));
        }
        parts.clear();
        while(getline(third,part,' '))//get all parts of second line
        {
            parts.push_back(part);
        }
        //Create Pokemon
        Pokemon pokemon(firstLine,pokemonTypes,stod(parts[0]),stod(parts[1]),stod(parts[2]),stod(parts[3]),stod(parts[4]),stod(parts[5]));
        //Add Pokemon
        game->pokemons.push_back(pokemon);
    }
    return true;
}

// Intent:  Load move data from file.
// Pre:     Move data file name.
// Post:    Print failed if file cannot be opened.
bool DataFormat::loadMoveData(string fileName, Game *game)
{
    ifstream moveDataFile(fileName);

    //Error Proof
    if(!moveDataFile.is_open())
    {
        cout<<fileName<<" Cannot be opened"<<endl;
        return false;
    }
    game->moves.clear();
    string name;
    while(moveDataFile >> name)
    {
        int attribute;
        int type;
        int power;
        int accuracy;
        int pp;
        bool isCon;
        int con = -1;
        string buffer;

        moveDataFile >> attribute;
        moveDataFile >> type;
        moveDataFile >> power;
        moveDataFile >> accuracy;
        moveDataFile >> pp;
        moveDataFile >> buffer;

        if (buffer != "\n")
        {
            isCon = true;
            if (buffer == "PAR")
            {
                con = PARALYSIS_STATE;
            }
            else if (buffer == "BRN")
            {
                con = BURN_STATE;
            }
            else if (buffer == "PSN")
            {
                con = POISON_STATE;
            }
        }
        else
        {
            isCon = false;
        }

        // Add a move to the library.
        Move aMove(name, attribute, type, power, accuracy, pp, isCon, con);
        game->moves.push_back(aMove);

        // Next line.
        moveDataFile.ignore();
    }
    return true;
}

// Intent:  Load Game data from file.
// Pre:     Game data file name.
// Post:    Print failed if file cannot be opened.
bool DataFormat::loadGameData(string fileName, Game *game)
{
    ifstream gameDataFile(fileName);

    //Error Proof
    if(!gameDataFile.is_open())
    {
        cout<<fileName<<" Cannot be opened"<<endl;
        return false;
    }
    game->players.clear();
    // Initialise Players in the game.
    for (int i = 0; i < 2; i++)
    {
        Player aPlayer;
        aPlayer.currentPokemon = 0;

        int pokemonNumber;
        gameDataFile >> pokemonNumber;
        gameDataFile.ignore();

        // Initialise Pokemon.
        for (int j = 0; j < pokemonNumber; j++)
        {
            Pokemon aPokemon;
            string pokemonName;
            int moveNumber;
            string moveName;

            gameDataFile >> pokemonName >> moveNumber;
            gameDataFile.ignore();

            // Find Pokemon in library.
            for (int l = 0; l < game->pokemons.size(); l++)
            {
                if (game->pokemons[l].getName() == pokemonName)
                {
                    aPokemon = game->pokemons[l];
                    break;
                }
            }
            vector<Move> moves;
            // Add Moves.
            for (int k = 0; k < moveNumber; k++)
            {
                gameDataFile >> moveName;

                // Find Move in library.
                for (int m = 0; m < game->moves.size(); m++)
                {
                    if (game->moves[m].getName() == moveName)
                    {
                        moves.push_back(game->moves[m]);
                    }
                }
            }
            aPokemon.setMoves(moves);
            gameDataFile.ignore();
        }

        // Add Player.
        game->players.push_back(aPlayer);

        // Skip to next line and read new Player.
        gameDataFile.ignore();
    }
    return true;
}
