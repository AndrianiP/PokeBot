#pragma once
#include "json.h"
#include <iostream>
#include <fstream>
#include "Monster.h"
#include "PokedexEntry.h"

using json = nlohmann::json;

struct Pokedex: public PokedexEntry<int, Monster>{
    PokedexEntry *root = NULL;
    json data;
    
    Pokedex() : PokedexEntry<int, Monster>(0, NULL, NULL, Monster("0", "Name", spriteGIF, spritePNG)){}

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
                root = insert(root, monster.getIntID(), monster);
                firstEntry = false;
            }
                insert(root, monster.getIntID(), monster);
        }

        return root;
    }

    Monster pokeSearch(PokedexEntry *root, int key) {
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