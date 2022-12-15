#pragma once
#include <string>
#include <vector>

struct Monster{
        Monster() = default;

        Monster(const int id, std::string name, std::vector<std::string> types,  std::string hp, std::string atk, std::string def, std::string spatk, std::string spdef, std::string spd, std::string eggGroup1, std::string eggGroup2);
        // std::string getName();
        // std::string getType1();
        // std::string getType2();
        // std::string getHP();
        // std::string getAtk();
        // std::string getDef();
        // std::string getSpatk();
        // std::string getSpdef();
        // std::string getSpd();
        // std::string getEggGroup1();
        // std::string getEggGroup2();

        std::string setEggGroup1(std::string eggGroup1){
            this->eggGroup1 = eggGroup1;
        }
        std::string setEggGroup2(std::string eggGroup2){
            this->eggGroup2 = eggGroup2;
        }

        int getID(){
            return this->id;
        }
        std::string getName(){
            return this->name;
        }
        std::string getHP(){
            return this->hp;
        }
        std::string getAtk(){
            return this->atk;
        }
        std::string getDef(){
            return this->def;
        }
        std::string getSpatk(){
            return this->spatk;
        }
        std::string getSpdef(){
            return this->spdef;
        }
        std::string getSpd(){
            return this->spd;
        }
        std::string getEggGroup1(){
            return this->eggGroup1;
        }
        std::string getEggGroup2(){
            return this->eggGroup2;
        }
        std::string getType1(){
            return this->types[0];
        }
        std::string getType2(){
            return this->types[1];
        }

        std::string toString(){
            return this->name + "\n" + this->types[0] + "\n" + this->types[1] + "\n" + this->hp + "\n" + this->atk + "\n" + this->def + "\n" + this->spatk + "\n" + this->spdef + "\n" + this->spd + "\n" + this->eggGroup1 + "\n" + this->eggGroup2;
        }

        const int id;
        std::string name;
        std::vector<std::string> types;
        std::string hp;
        std::string atk;
        std::string def;
        std::string spatk;
        std::string spdef;
        std::string spd;
        std::string eggGroup1 = NULL;
        std::string eggGroup2 = NULL;
};