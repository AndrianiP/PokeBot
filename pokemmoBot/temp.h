
#include <iostream>
#include <string>


class Test {
	int lizard;
    std::string name;
    public:
    Test() : lizard(0), name("none"){}

    Test(int lizard, std::string name) : lizard(lizard), name(name) {}

    void toString(){
        std::cout << "lizard: " << lizard << " name: " << name << std::endl;
    }
};
