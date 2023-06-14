/***********************************************************************
 * File: DataFormat.cpp
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/06/14
 * Description:  Load Pokemon data from file , Pokemon data , Move data , Game data , Test Case format
***********************************************************************/
#include "DataFormat.h"
#include <sstream>

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
    while(getline(pokemonData,line)) // venusaur
    {
        // reading inputs:
        vector<string>lines;//data lines

        string firstLine = line;//record first line
        
        getline(pokemonData,line); // 2 grass poison
        string secondLine = line;// record second line

        getline(pokemonData, line); // 187 147 148 167 167 145
        string thirdLine = line;// record third line
        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        
        // stored:

        string part;
        vector<string> parts;
        int typeN;//type N
        vector<Attribute> pokemonTypes;

        stringstream second(secondLine);
        stringstream third(thirdLine);

        while(getline(second,part,' '))//get all parts of second line
        {
            parts.push_back(part); // 2 grass poin
        }

        typeN = parts.size();//get type N // 3

        for(int i=0;i<typeN;i++)//set type
        {
            pokemonTypes.push_back(stringToType(parts[i]));
        }
        parts.clear();
        while(getline(third,part,' '))//get all parts of second line
        {
            parts.push_back(part); // 
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
    string name,line,attributeString,typeString;
    int attribute,type,power,accuracy,pp,isCon;
    int con = -1;
    string buffer;
    while(getline(moveDataFile,line))
    {
        stringstream commandLine(line);
        if(!(commandLine>>name>>attributeString>>typeString>>power>>accuracy>>pp))
        {
            cout<<"command not complete"<<endl;
            return false;
        }
        if(commandLine>>buffer)
        {
            isCon = true;
            if(buffer == "PAR")
            {
                con = PARALYSIS_STATE;
            }
            else if(buffer == "BRN")
            {
                con = BURN_STATE;
            }
            else if(buffer == "PSN")
            {
                con = POISON_STATE;
            }
            else
            {
                isCon = false;
                cout<<"unknown command"<<endl;
            }
        }
        attribute = stringToType(attributeString);
        type = stringToType(typeString);
        // Add a move to the library.
        Move aMove(name, attribute, type, power, accuracy, pp, isCon, con);
        game->moves.push_back(aMove);
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
        if(!(gameDataFile >> pokemonNumber))
        {
            cout<<"No pokemon"<<endl;
            return false;
        }
        gameDataFile.ignore();
        // Initialise Pokemon.
        for (int j = 0; j < pokemonNumber; j++)
        {
            Pokemon* aPokemon;
            string pokemonName;
            int moveNumber;
            string moveName;
            if(!(gameDataFile >> pokemonName >> moveNumber))
            {
                cout<<"command no complete"<<endl;
                return false;
            }
            gameDataFile.ignore();

            // Find Pokemon in library.
            for (int l = 0; l < game->pokemons.size(); l++)
            {
                if (game->pokemons[l].getName() == pokemonName)
                {
                    aPokemon = &game->pokemons[l];
                    break;
                }
            }
            vector<Move> moves;
            // Add Moves.
            for (int k = 0; k < moveNumber; k++)
            {
                if(!( gameDataFile >> moveName))
                {
                     cout<<"command no complete"<<endl;
                    return false;
                }
                // Find Move in library.
                for (int m = 0; m < game->moves.size(); m++)
                {
                    if (game->moves[m].getName() == moveName)
                    {
                        moves.push_back(game->moves[m]);
                        break;
                    }
                }
            }
            aPokemon->setMoves(moves);
            aPlayer.pokemons.push_back((*aPokemon));
            gameDataFile.ignore();
        }
        // Add Player.
        game->players.push_back(aPlayer);
    }
    return true;
}
