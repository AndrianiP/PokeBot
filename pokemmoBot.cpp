// pokemmoBot.cpp : Defines the entry point for the application.
//
#include "TESTING.h"
#include "pokemmoBot.h"
#include <opencv2/opencv.hpp>

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
    while(true){
        imshow("test", src);
        infoGrab.saveImage(src, "./TrainingImages/"+std::to_string(counter)+".png");

        waitKey(32);
    }

	return 0;
}

 void saveImage(Mat src, std::string filename){
        std::vector<uchar> buf;
        imencode(".png", src, buf);
        imwrite(filename, src);
        buf.clear();
    }