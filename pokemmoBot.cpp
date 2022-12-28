// pokemmoBot.cpp : Defines the entry point for the application.
//
#include "StateTraining.h"
#include "pokemmoBot.h"

int main()
{
	// Pokedex pokedex = Pokedex();
	// PokedexEntry<int, Monster> *root = pokedex.fillPokedex();
	

	// Monster monster2 = pokedex.pokeSearch(72);
	// monster2.toString();
	// Monster monster420 = pokedex.pokeSearch(420);
	// monster420.toString();
	// Monster monster6 = pokedex.pokeSearch(6);
	// monster6.toString();
	// Monster monster1 = pokedex.pokeSearch(10118);
	// monster1.toString();
	// pokedex.pokeSearch(2).toString();

    // TODO take photos and save to folder
    StateTraining infoGrab = StateTraining();
    HWND hwnd = GetDesktopWindow();
    Mat src = infoGrab.takeScreenshot(hwnd);
    int counter = 0;
    imshow("test", src);
    infoGrab.saveImage(src, "./TrainingImages/" + std::to_string(counter) + ".png");
    while(true){
        if (waitKey(0) == 32) {
            Mat src = infoGrab.takeScreenshot(hwnd);
            imshow("test", src);
            counter++;
            infoGrab.saveImage(src, "./TrainingImages/" + std::to_string(counter) + ".png");
        }
        if (waitKey(0) == 27) {
            destroyAllWindows();
        }
    }

	return 0;
}