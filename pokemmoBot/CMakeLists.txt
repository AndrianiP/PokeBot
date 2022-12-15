# CMakeList.txt : CMake project for pokemmoBot, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("pokemmoBot")

# Add source to this project's executable.
add_executable (pokemmoBot "pokemmoBot.cpp" "pokemmoBot.h"  "pokedex.h" "json.h" "DataConstants.h" "Monster.h" "MonsterFactory.h" "DataLoader.cpp" "DataLoader.h" "DataWriter.cpp")

# TODO: Add tests and install targets if needed.
