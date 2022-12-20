#pragma once
#include "json.h"
#include <iostream>
#include <fstream>
#include "Monster.h"
#include "PokedexEntry.h"

using json = nlohmann::json;

struct Pokedex: public PokedexEntry<int, Monster>{
    PokedexEntry<int, Monster> *root = nullptr;
    json data;
    
    Pokedex() : PokedexEntry<int, Monster>(){}

    void printJSON() {
        std::cout << data << std::endl;
    }

    PokedexEntry<int, Monster> *fillPokedex() {
        std::ifstream f(POKEDEX_DIR);
        data = json::parse(f);
        //data = data.dump();
        f.close();
        bool firstEntry = true;
        for (auto& element : data) {
            Monster monster = Monster(element[ID], element[NAME], spriteGIF, spritePNG);
            if (firstEntry) {
                root = insert(monster.getIntID(), monster);
                firstEntry = false;
            }
                insert(monster.getIntID(), monster);
        }

        return root;
    }

    Monster pokeSearch(int key) {
        if (root == NULL) {
            return Monster("0", "Name", "No GIF", "No PNG");
        }
        else {
            PokedexEntry *current = root;
            while (current->key != key) {
                if (key < current->key) {
                    current = current->left;
                }
                else {
                    current = current->right;
                }
                if (current == NULL) {
                    return Monster("0", "Name", "No GIF", "No PNG");
                }
            }
            return current->monster;
        }
    }
    
    void toString() {
        std::cout << "Pokedex: " << std::endl;
        std::cout << "Root: " << root << std::endl;
        std::cout << "Data: " << data << std::endl;
    }

    protected: 
        const std::string POKEDEX_DIR = "./JSON/pokemon.json";
        const std::string ID = "id";
        const std::string NAME = "name";

        const std::string spriteGIF = "animated";
        const std::string spritePNG = "static";
        
};