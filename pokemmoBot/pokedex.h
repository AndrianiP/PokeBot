#pragma once
#include <string>
#include "json.h"
#include <fstream>
#include "Monster.h"
#include "PokedexEntry.h"

using json = nlohmann::json;

class Pokedex{
    public:
    struct node *left;
    struct node *right;
    struct node *root = NULL;

    Pokedex() {
        struct node *root = fillPokedex();
    }

    node* fillPokedex() {
        bool firstEntry = true;
        for (auto& element : data) {
           // Monster monster = Monster(int(element[ID]), std::string(element[NAME][english]), {"noType", "noType"}, std::string(element[BASE][HP]), std::string(element[BASE][ATK]), std::string(element[BASE][DEF]), std::string(element[BASE][SPATK]), std::string(element[BASE][SPDEF]), std::string(element[BASE][SPD]), "noEggGroup", "noEggGroup");
            if (firstEntry) {
               // root = newPokedexEntry(monster.getID(), monster);
                firstEntry = false;
            }
                //insert(root, monster.getID(), monster);
        }
 
        return root;
    }

    // Monster pokeSearch(struct node* node, int key) {
    //     Monster monster = search(node, key);
    //     return monster;
    // }

    private:
        json data = json::parse(std::ifstream(POKEDEX_DIR));
        

    protected:
        const std::string POKEDEX_DIR = "pokedex.json";
        const std::string ID = "id";
        const std::string NAME = "name";
        const std::string english = "english";
        const std::string TYPE = "type";
        const std::string BASE = "base";
        const std::string HP = "HP";
        const std::string ATK = "Attack";
        const std::string DEF = "Defense";
        const std::string SPATK = "Sp. Attack";
        const std::string SPDEF = "Sp. Defense";
        const std::string SPD = "Speed";
};