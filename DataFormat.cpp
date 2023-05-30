/***********************************************************************
 * File: DataFormat.h
 * Author: B11115016
 * Create Date: 2023/05/29
 * Editor: B11115016,B11115033
 * Update Date: 2023/05/29
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
vector<Pokemon>& DataFormat::loadPokemonData(string fileName)
{
    vector<Pokemon> pokemons;
    ifstream pokemonData(fileName);
    //Error Proof
    if(!pokemonData.is_open())
    {
        return ;
    }
    string line;
    while(getline(pokemonData,line))
    {   
        vector<string>lines;//data lines
        lines.push_back(line);
        for(int i=0;getline(pokemonData,line),i<2;i++)//get firstline to thirdline
        {
            lines.push_back(line);
        }
        string firstLine = lines[0];//record first line
        string secondLine = lines[1];//record second line
        string thirdLine = lines[2];//record third line
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
        while(getline(third,part,' '))//get all parts of second line
        {
            parts.push_back(part);
        }
        //Create Pokemon
        Pokemon pokemon(State::NORMAL,firstLine,pokemonTypes,stod(parts[0]),stod(parts[1]),stod(parts[2]),stod(parts[3]),stod(parts[4]),stod(parts[5]));
        //Add Pokemon
        pokemons.push_back(pokemon);
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
