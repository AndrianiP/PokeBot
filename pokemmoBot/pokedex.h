#pragma once
#include <string>
#include "json.h"
#include <fstream>
#include "MonsterFactory.h"

using json = nlohmann::json;

class Pokedex: public MonsterFactory{
    public:

    void fillPokedex() {
        for (auto& element : data) {
            Monster monster = createMonster(element[NAME][english], element[TYPE], element[BASE][HP], element[BASE][ATK], element[BASE][DEF], element[BASE][SPATK], element[BASE][SPDEF], element[BASE][SPD], "eggGroup1", "eggGroup2");
            pokedex.push_back(monster);
        }
    }

    

    private:
        json data = json::parse(std::ifstream(POKEDEX_DIR));
        std::vector<Monster> pokedex;

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