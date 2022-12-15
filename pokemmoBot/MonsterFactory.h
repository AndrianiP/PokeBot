#pragma once
#include "Monster.h"
#include <string>

struct MonsterFactory: public Monster{
    MonsterFactory() : Monster(0, "", {}, "", "", "", "", "", "", "", "") {}
    
    Monster createMonster(const int id, std::string name, vector<std::string> types,std::string hp, std::string atk, std::string def, std::string spatk, std::string spdef, std::string spd, std::string eggGroup1, std::string eggGroup2){
        Monster monster(id, name, types, hp, atk, def, spatk, spdef, spd, eggGroup1, eggGroup2);
        return monster;
    }
    
};