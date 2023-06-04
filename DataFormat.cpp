/***********************************************************************
 * File: DataFormat.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/06/
 * Description:  Load Pokemon data from file , Pokemon data , Move data , Game data , Test Case format
***********************************************************************/
#include "DataFormat.h"

//DataFormat Constructor
DataFormat::DataFormat()
{
   
}
//DataFormat Destructor
DataFormat::~DataFormat()
{

}

/**
 * Intent:Load Pokemon data from file
 * Pre:Pokemon data file name
 * Pos:return pokemons
 */
void DataFormat::loadPokemonData(string fileName, Game &game)
{
    ifstream pokemonData(fileName);

    //Error Proof
    if(!pokemonData.is_open())
    {
        cout<<fileName<<" Can't Open"<<endl;
        return;
    }

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
        game.pokemons.push_back(pokemon);
    }
}

// Intent:  Load move data from file.
// Pre:     Move data file name.
// Post:    Return bool.
void DataFormat::loadMoveData(string fileName, Game &game)
{
    ifstream moveDataStream(fileName);

    //Error Proof
    if(!moveDataStream.is_open())
    {
        cout<<fileName<<" Cannot be opened"<<endl;
        return;
    }

    string line;
    while(getline(moveDataStream,line))
    {
        vector<string>lines;//data lines
        string firstLine = line;//record first line
        getline(moveDataStream,line);
        string secondLine = line;
        getline(moveDataStream,line);
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
        game.pokemons.push_back(pokemon);
    }
}

/**
 * Intent:Load Game data from file 
 * Pre:Game data file name
 * Pos:return players
 */
vector<Player>& DataFormat::loadGameData(string fileName)
{   
    vector<Player> players;
    Player player;
    players.push_back(player);
    return players;
}
