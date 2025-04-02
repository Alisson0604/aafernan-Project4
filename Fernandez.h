//
// Created by Alisson Fernandez on 1/25/2025.
//

#ifndef FERNANDEZ_H
#define FERNANDEZ_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout, std::endl, std::ifstream, std::string;

class Fernandez
{
    private:
        int pokemonId, attack, defense, speed;
        std::string name, primaryType, secondaryType, firstAppearance, generation;
    public:
    //constructors
        Fernandez() {
           name = "pikachu";
           primaryType = "electric";
           secondaryType = "none";
           firstAppearance = "red/blue";
           generation = "gen 1";
           pokemonId = 25;
           attack = 55;
           defense = 40;
           speed = 90;
            }

        Fernandez(const string &name, const string &primaryType, const string &secondaryType, const string &firstAppearance, const string &generation,
                  int pokemonId, int attack, int defense, int speed) {

           this->name = name;
           this->primaryType = primaryType;
           this->secondaryType = secondaryType;
           this->firstAppearance = firstAppearance;
           this->generation = generation;
           this->pokemonId = pokemonId;
           this->attack = attack;
           this->defense = defense;
           this->speed = speed;
            }

    //getters
        string getName() const{
           return name;
            }
        string getPrimaryType() const{
           return primaryType;
            }
        string getSecondaryType() const{
           return secondaryType;
            }
        string getFirstAppearance() const{
           return firstAppearance;
            }
        string getGeneration() const{
           return generation;
            }
        int getPokemonId() const{
           return pokemonId;
            }
        int getAttack() const{
           return attack;
            }
        int getDefense() const{
           return defense;
            }
        int getSpeed() const{
           return speed;
            }

    //setters
        void setName(string name){
           this->name = name;
            }
        void setPrimaryType(string primaryType){
           this->primaryType = primaryType;
            }
        void setSecondaryType(string secondaryType){
           this->secondaryType = secondaryType;
            }
        void setFirstAppearance(string firstAppearance){
           this->firstAppearance = firstAppearance;
            }
        void setGeneration(string generation){
           this->generation = generation;
            }
        void setPokemonId(int pokemonId){
           this->pokemonId = pokemonId;
            }
        void setAttack (int attack){
           this->attack = attack;
            }
        void setDefense (int defense){
           this->defense = defense;
            }
        void setSpeed (int speed){
           this->speed = speed;
            }

    friend std::ostream& operator << (std::ostream& outs, const Fernandez& poke){
       outs << std::left << std::setw(6) << poke.pokemonId;
       outs << std::left << std::setw(15) << poke.name;
       outs << std::left << std::setw(12) << poke.primaryType;
       outs << std::left << std::setw(12) << poke.secondaryType;
       outs << std::left << std::setw(15) << poke.firstAppearance;
       outs << std::left << std::setw(12) << poke.generation;
       outs << std::left << std::setw(10) << poke.attack;
       outs << std::left << std::setw(10) << poke.defense;
       outs << std::left << std::setw(10) << poke.speed;
       return outs;
        }

    // Overload == operator
    friend bool operator == (const Fernandez& poke1, const Fernandez& poke2){
       return poke1.attack == poke2.attack;
        }

    // Overload != operator
    friend bool operator != (const Fernandez& poke1, const Fernandez& poke2){
       return !(poke1.attack == poke2.attack);
        }

    // Overload < operator
    friend bool operator < (const Fernandez& poke1, const Fernandez& poke2){
       return poke1.attack < poke2.attack;
        }

    // Overload > operator
    friend bool operator > (const Fernandez& poke1, const Fernandez& poke2){
       return poke1.attack > poke2.attack;
        }

    // Overload <= operator
    friend bool operator <= (const Fernandez& poke1, const Fernandez& poke2){
       return !(poke1.attack > poke2.attack);
        }

    // Overload >= operator
    friend bool operator >= (const Fernandez& poke1, const Fernandez& poke2){
       return !(poke1.attack < poke2.attack);
        }
};

// This function takes two arguments given on main, the file name and the pokemons vector
// It opens the csv file and loads the data into the vector
// There is a message that tells if the file its being successfully open or if there is an error

bool loadFromFile(std::string file, std::vector<Fernandez>& pokemons) {
    std::ifstream fileIn;
    fileIn.open(file);

    if (fileIn) {
        cout << "File opened successfully!" << endl;

        // Print file header
        string header;
        getline(fileIn, header);

        // Variable declaration (set to default)
        string name = "pikachu", primaryType = "electric", secondaryType = "none", firstAppearance = "red/blue", generation = "gen 1";
        int pokemonId = 25, attack = 55, defense = 40, speed = 90;
        char comma;

        // read the data in the file
        // while the file is good and hasn't reached the end of it
        while (fileIn && fileIn.peek() != EOF) {
            // read in Pokémon ID
            fileIn >> pokemonId;
            fileIn.ignore(1, ',');
            //cout << pokemonId << endl;

            // read in name
            getline(fileIn, name,',');
            //cout << name << endl;

            // read in primary type
            getline(fileIn, primaryType,',');
            //cout << primaryType << endl;

            // read in secondary type
            // check if there is a secondary type
            getline(fileIn, secondaryType,',');
            if (!fileIn)
            {
                secondaryType = "none";
                fileIn.clear();
            }
            //cout << secondaryType << endl;

            // read in first appearance
            getline(fileIn, firstAppearance,',');
            // if the pokemon does not have a secondary type
            if (secondaryType.empty())
            {
                secondaryType = "none";
            }
            //cout << firstAppearance << endl;

            // read in generation
            getline(fileIn, generation,',');
            //cout << generation << endl;

            // read in attack
            fileIn >> attack;
            fileIn.ignore(1, ',');
            //cout << attack << endl;

            // read in defense
            fileIn >> defense;
            fileIn.ignore(1, ',');
            //cout << defense << endl;

            // read in speed
            fileIn >> speed;
            fileIn.ignore(1, '\n');
            //cout << speed << endl;

            // Stores the data into the vector
            pokemons.push_back(Fernandez(name, primaryType, secondaryType, firstAppearance, generation, pokemonId, attack,
                                  defense, speed));
        }
    }
    else {
        // print message if there is an error opening the file
        cout << "Error opening file!" << endl;
        return false;
    }
    // close file
    fileIn.close();
    return true;
};
#endif //FERNANDEZ_H