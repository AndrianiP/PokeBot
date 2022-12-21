#pragma once
#include <windows.h>
#include <iostream>

struct WindowInfo{
    int height, width, x, y;
    HWND hwnd;
    RECT rect;
    DWORD pid;
    //Gets the window's device context (drawing context)
    HDC hdc;

    WindowInfo(){
        height = 0;
        width = 0;
        x = 0;
        y = 0;
        hwnd = NULL;
        rect = {0, 0, 0, 0};
        hdc = NULL;
    }

    WindowInfo(HWND hwnd){
        this->hwnd = hwnd;
        GetWindowRect(hwnd, &rect);
        height = rect.bottom - rect.top;
        width = rect.right - rect.left;
        x = rect.left;
        y = rect.top;
        hdc = GetDC(hwnd);
    }

    void setHwnd(HWND hwnd){
        this->hwnd = hwnd;
    }

    HWND getHwnd(){
        return hwnd;
    }

    HWND searchWindows(LPCSTR windowName){
        HWND hwnd = FindWindow(NULL, windowName);
        if(hwnd == NULL){
            std::cout << "Window not found" << std::endl;
        }
        else{
            std::cout << "Window found" << std::endl;
            return hwnd;
        }
    }

    HWND findAllWindows(){
        HWND hwnd = NULL;
        do{
            hwnd = FindWindowEx(NULL, hwnd, NULL, NULL);
            if(hwnd != NULL){
                GetWindowRect(hwnd, &rect);
                height = rect.bottom - rect.top;
                width = rect.right - rect.left;
                if(width -16 == 958 && height -39 == 1008){
                    DWORD pid = GetWindowThreadProcessId(hwnd, &pid);
                    std::cout<<"FOUND WINDOW WITH HWND BELOW: " << hwnd << "and PID of: "<< pid << std::endl;
                    std::cout << "Height: " << height  << "  Width: " << width << std::endl;
                    return hwnd;
                }
            }
        }while(hwnd != NULL);
    }


    void printWindowInfo(){
        std::cout << "HWND: " << this->hwnd << std::endl;
        DWORD pid = GetWindowThreadProcessId(hwnd, &pid);
        std::cout << "PID: "<< pid << std::endl;
        std::cout << "Height: " << this->height << std::endl;
        std::cout << "Width: " << this->width << std::endl;
        std::cout << "X: " << this->x << std::endl;
        std::cout << "Y: " << this->y << std::endl;
        std::cout << "HDC: " << this->hdc << std::endl;
    }
};