#pragma once
#include <opencv2/opencv.hpp>
#include "WindowInfo.h"

using namespace cv;

struct StateDetection {
    //TODO: Add more states

    //TODO Screenshot image and pass it to the function


    //TODO Turn image to grayscale

    //TODO Load in cascade file

    //TODO Detect state

    //TODO Return state

    struct State{
        bool isActive;
        bool isWalking;
        bool isRunning;
        bool isBiking;
        bool isBattling;
        bool isFishing;
        bool isEvolving;
        bool isEggHatching;
        bool isCaptcha;

        State(){
            isActive = false;
            isWalking = false;
            isRunning = false;
            isBiking = false;
            isBattling = false;
            isFishing = false;
            isEvolving = false;
            isEggHatching = false;
            isCaptcha = false;
        }

        bool setIsActive(bool isActive){
            this->isActive = isActive;
        }
        bool setWalking(bool isWalking){
            this->isWalking = isWalking;
        }
        bool setRunning(bool isRunning){
            this->isRunning = isRunning;
        }
        bool setBiking(bool isBiking){
            this->isBiking = isBiking;
        }
        bool setBattling(bool isBattling){
            this->isBattling = isBattling;
        }
        bool setFishing(bool isFishing){
            this->isFishing = isFishing;
        }
        bool setEvolving(bool isEvolving){
            this->isEvolving = isEvolving;
        }
        bool setEggHatching(bool isEggHatching){
            this->isEggHatching = isEggHatching;
        }
        bool setCaptcha(bool isCaptcha){
            this->isCaptcha = isCaptcha;
        }

        bool getIsActive(){
            return isActive;
        }
        bool getWalking(){
            return isWalking;
        }
        bool getRunning(){
            return isRunning;
        }
        bool getBiking(){
            return isBiking;
        }
        bool getBattling(){
            return isBattling;
        }
        bool getFishing(){
            return isFishing;
        }
        bool getEvolving(){
            return isEvolving;
        }
        bool getEggHatching(){
            return isEggHatching;
        }
        bool getCaptcha(){
            return isCaptcha;
        }

    };
};