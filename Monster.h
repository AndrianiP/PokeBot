#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sys/stat.h>

class Monster{

    std::string id;
    std::string name;
    bool doesSpriteGIFExist;
    bool doesSpritePNGExist;
    std::string spriteGIF = "http://img.pokemondb.net/sprites/black-white/anim/normal/" + name + "/" + name + ".gif";;
    std::string spritePNG = "http://img.pokemondb.net/sprites/black-white/normal/" + name + "/" + name + ".png";
    //std::vector<std::string> types;
    // std::string hp;
    // std::string atk;
    // std::string def;
    // std::string spatk;
    // std::string spdef;
    // std::string spd;
    // std::string eggGroup1 = NULL;
    // std::string eggGroup2 = NULL;
    
    public:
        //Default Constructor
        Monster() : id("0"), name("none"), spriteGIF(), spritePNG (){}

        //Constructor with all parameters
        Monster(std::string id, std::string name, std::string spriteGIF, std::string spritePNG) : id(id), name(name), spriteGIF(), spritePNG() {};

        //Getters
        std::string getStringID(){
            return this->id;
        }

        int getIntID(){
            std::string temp = this->id;
            return stoi(temp);
        }
        std::string getName(){
            return this->name;
        }
        std::string getSpriteGIF(){
            return this->spriteGIF;
        }
        std::string getSpritePNG(){
            return this->spritePNG;
        }

        bool operator==(const Monster& other) const {
            return this->id == other.id;
        }

        bool operator!=(const Monster& other) const {
            return this->id != other.id;
        }

        bool operator<(const Monster& other) const {
            return this->id < other.id;
        }

        bool operator>(const Monster& other) const {
            return this->id > other.id;
        }

        bool operator<=(const Monster& other) const {
            return this->id <= other.id;
        }

        bool operator>=(const Monster& other) const {
            return this->id >= other.id;
        }

        bool hasSpriteGIF() {
            struct stat buffer;
            const char *c = spriteGIF.c_str();
            if(stat(c, &buffer) == 0) {
                this->doesSpriteGIFExist = true;
                return this->doesSpriteGIFExist;
            }
            else {
                this->doesSpriteGIFExist = false;
                return this->doesSpriteGIFExist;
            }
        }

        bool hasSpritePNG() {
            struct stat buffer;
            const char *c = spritePNG.c_str();
            if(stat(c, &buffer) == 0) {
                this->doesSpritePNGExist = true;
                return doesSpritePNGExist;
            }
            else {
                this->doesSpritePNGExist = false;
                return this->doesSpritePNGExist;
            }
        }

        //TODO Implement setters
        std::string setSpriteGIF(bool hasSpriteGIF){
            if(hasSpriteGIF) {
                //TODO Implement code to display gif
                return this->spriteGIF;
            }
            else {
                return "no sprite found";
            }
        }

        std::string setSpritePNG(bool hasSpritePNG){
            if(hasSpritePNG) {
                //TODO Implement code to display png
                return this->spritePNG;
            }
            else {
                return "No sprite found";
            }
        }


        void toString() {
            std::cout << "ID: " << this->id << "\nName: " << this->name << std::endl;
        }


};
