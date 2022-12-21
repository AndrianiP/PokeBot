// pokemmoBot.cpp : Defines the entry point for the application.
//

#include "pokemmoBot.h"
#include <opencv2/opencv.hpp>

int main()
{
	Pokedex pokedex = Pokedex();
	PokedexEntry<int, Monster> *root = pokedex.fillPokedex();
	

	Monster monster2 = pokedex.pokeSearch(72);
	monster2.toString();
	Monster monster420 = pokedex.pokeSearch(420);
	monster420.toString();
	Monster monster6 = pokedex.pokeSearch(6);
	monster6.toString();
	Monster monster1 = pokedex.pokeSearch(10118);
	monster1.toString();
	pokedex.pokeSearch(2).toString();

	//Test .exe
	int x;
	std::cin >> x;

	return 0;
}
