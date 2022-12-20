// pokemmoBot.cpp : Defines the entry point for the application.
//

#include "pokemmoBot.h"

using namespace std;

int main()
{
	Pokedex pokedex = Pokedex();
	//pokedex.toString();
	PokedexEntry<int, Monster> *root = pokedex.fillPokedex();
	Monster monster2 = pokedex.pokeSearch(pokedex.root, 72);
	monster2.toString();
	Monster monster420 = pokedex.pokeSearch(pokedex.root, 420);
	monster420.toString();
	Monster monster6 = pokedex.pokeSearch(pokedex.root, 6);
	monster6.toString();

	return 0;
}
