#include <string>
#include <iostream>
#include <vector>

class Monster{

    int id;
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
    
    public:
        //Default Constructor
        Monster() : id(0), name("none"), types({"none", "none"}), hp("0"), atk("0"), def("0"), spatk("0"), spdef("0"), spd("0"), eggGroup1("none"), eggGroup2("none") {}

        //Constructor with all parameters
        Monster(int id, std::string name, std::vector<std::string> types, std::string hp, std::string atk, std::string def, std::string spatk, std::string spdef, std::string spd, std::string eggGroup1, std::string eggGroup2) 
                : id(id), name(name), types(types), hp(hp), atk(atk), def(def), spatk(spatk), spdef(spdef), spd(spd), eggGroup1(eggGroup1), eggGroup2(eggGroup2){};
            
        std::string setEggGroup1(std::string eggGroup1){
            this->eggGroup1 = eggGroup1;
        }
        std::string setEggGroup2(std::string eggGroup2){
            this->eggGroup2 = eggGroup2;
        }

        //Getters
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

        void toString() {
            std::cout << "ID: " << this->id << "\nName: " << this->name << "\nTypes: " << this->types[0] << " " << this->types[1] << "\nHP: " << this->hp << "\nAtk: " << this->atk << "\nDef: " << this->def << "\nSpatk: " << this->spatk << "\nSpdef: " << this->spdef << "\nSpd: " << this->spd << "\nEggGroup1: " << this->eggGroup1 << "\nEggGroup2: " << this->eggGroup2 << std::endl;
        }


};

// Monster::Monster(int id, std::string name, std::vector<std::string> types,  std::string hp, std::string atk, std::string def, std::string spatk, std::string spdef, std::string spd, std::string eggGroup1, std::string eggGroup2){
//     this->id = id;
//     this->name = name;
//     this->types = types;
//     this->hp = hp;
//     this->atk = atk;
//     this->def = def;
//     this->spatk = spatk;
//     this->spdef = spdef;
//     this->spd = spd;
//     this->eggGroup1 = eggGroup1;
//     this->eggGroup2 = eggGroup2;
// }
