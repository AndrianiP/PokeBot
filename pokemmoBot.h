// pokemmoBot.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include "pokedex.h"
#include "StateDetection.h"

class pokeBot
{
public:
	pokeBot();
	~pokeBot();

private:
	int encounter;
	int pokemon;


	void setEncounter(int encounters) {
		this->encounter = encounter;
	}
	void setHuntingPokemon(int pokemon) {
		//TODO look through pokedex for pokemon using binary search tree
	}

};

pokeBot::pokeBot()
{
}

pokeBot::~pokeBot()
{
}

