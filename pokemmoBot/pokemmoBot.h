// pokemmoBot.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include "pokedex.h"

class pokeBot
{
public:
	pokeBot();
	~pokeBot();
	bool getEncounter(){
		return this->encounter;
	}
	bool getIsActive(){
		return this->isActive;
	}
	bool getIsWalking(){
		return this->isWalking;
	}
	bool getIsRunning(){
		return this->isRunning;
	}
	bool getIsBiking(){
		return this->isBiking;
	}
	bool getIsBattling(){
		return this->isBattling;
	}	
	bool getIsFishing(){
		return this->isFishing;
	}
	bool getIsEvolving(){
		return this->isEvolving;
	}
	bool getIsEggHatching(){
		return this->isEggHatching;
	}
	bool getIsCaptcha(){
		return this->isCaptcha;
	}

private:
	int encounter;
	int pokemon;
	bool isActive;
	bool isWalking;
	bool isRunning;
	bool isBiking;
	bool isBattling;
	bool isFishing;
	bool isEvolving;
	bool isEggHatching;
	bool isCaptcha;

	void setEncounter(int encounters) {
		this->encounter = encounter;
	}
	void setHuntingPokemon(int pokemon) {
		//TODO look through pokedex for pokemon using binary search tree
	}
	void setIsActive(bool active) {
		this->isActive = active;
	}
	void setIsWalking(bool walking) {
		this->isWalking = walking;
	}
	void setIsRunning(bool running) {
		this->isRunning = running;
	}
	void setIsBiking(bool biking) {
		this->isBiking = biking;
	}
	void setIsFishing(bool fishing)	{
		this->isFishing = fishing;
	}
	void setIsBattling(bool battling) {
		this->isBattling = battling;
	}
	void setIsEvovling(bool evolving) {
		this->isEvolving = evolving;
	}
	void setIsEggHatching(bool hatching) {
		this->isEggHatching = hatching;
	}
	void setIsCaptcha(bool captcha)	{
		this->isCaptcha = captcha;
	}

};

pokeBot::pokeBot()
{
}

pokeBot::~pokeBot()
{
}

