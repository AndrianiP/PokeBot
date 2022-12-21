#include "WindowInfo.h"


int main(){
    HWND hwnd = WindowInfo().searchWindows("Java(TM) Platform SE binary");
    WindowInfo window(hwnd);
    window.printWindowInfo();

    // window.setHwnd(window.searchWindows("PokeMMO"));
    // window.pid = GetWindowThreadProcessId(window.getHwnd(), &window.pid);
    // std::cout << window.pid << std::endl;
    // window.printWindowInfo();
    return 0;
}