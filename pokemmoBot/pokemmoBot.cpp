// pokemmoBot.cpp : Defines the entry point for the application.
//

#include "pokemmoBot.h"
#include "temp.h"
using namespace std;

int main()
{
	// Pokedex pokedex = Pokedex();
	// Monster monster = pokedex.pokeSearch(pokedex.root, 1);
	// monster.toString();
	Test defaultTest = Test();
	defaultTest.toString();

	Test test = Test(32, "David The Lizard");
	test.toString();
	Monster monster;
	monster = Monster(1,"2", {"grass", "poison"}, "100", "100", "100", "100", "100", "100", "eggGroup1", "eggGroup2");
	monster.toString();
	return 0;
}
