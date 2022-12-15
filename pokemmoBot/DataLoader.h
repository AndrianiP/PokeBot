#include <string>
#include <vector>
#include <fstream>
#include "json.h"

using json = nlohmann::json;

class DataLoader{
    public:
        json data = json::parse(std::ifstream(POKEDEX_DIR));
        
        std::vector<std::string> getNames() {
            std::vector<std::string> names;
            for (auto& element : data) {
                names.push_back(element[NAME][english]);
            }
            return names;
        }
        
        std::vector<std::string> getTypes() {
            std::vector<std::string> types;
            for (auto& element : data) {
                types.push_back(element[TYPE1]);
                types.push_back(element[TYPE2]);
            }
            return types;
        }
        

    private:


    protected:
        const std::string POKEDEX_DIR = "pokedex.json";
        const std::string ID = "id";
        const std::string NAME = "name";
        const std::string english = "english";
        const std::string TYPE1 = "type1";
        const std::string TYPE2 = "type2";
        const std::string BASE = "base";
        const std::string HP = "HP";
        const std::string ATK = "Attack";
        const std::string DEF = "Defense";
        const std::string SPATK = "Sp. Attack";
        const std::string SPDEF = "Sp. Defense";
        const std::string SPD = "Speed";
        //const std::string EGG_GROUP1 = "eggGroup";
};