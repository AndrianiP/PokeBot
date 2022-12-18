#pragma once
#include <string>
#include "json.h"
#include <fstream>
#include "MonsterFactory.h"
#include "Monster.h"
#include "PokedexEntry.h"

using json = nlohmann::json;

class Pokedex: public Monster{
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
            Monster monster = Monster(element[ID], element[NAME][english], element[TYPE], element[BASE][HP], element[BASE][ATK], element[BASE][DEF], element[BASE][SPATK], element[BASE][SPDEF], element[BASE][SPD], "eggGroup1", "eggGroup2");
            if (firstEntry) {
                root = newPokedexEntry(monster.getID(), monster);
                firstEntry = false;
            }
                insert(root, monster.getID(), monster);
        }
 
        return root;
    }

    // Monster pokeSearch(struct node* node, int key) {
    //     Monster monster = search(node, key);
    //     return monster;
    // }

    std::string toString(Monster monster){
        monster.toString();
        
    }

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