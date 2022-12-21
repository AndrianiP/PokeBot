# CMakeList.txt : CMake project for pokemmoBot, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("pokemmoBot")
set(OpenCV_DIR "C:/vcpkg/packages/opencv4_x86-windows/share/opencv4")
find_package(OpenCV REQUIRED)
add_definitions("-DPATH_TO_JSON=\"${CMAKE_INSTALL_PREFIX}/JSON/pokemon.json\")")

# Add source to this project's executable.
add_executable (pokemmoBot "pokemmoBot.cpp" "pokemmoBot.h" "pokedex.h" "json.h" "Monster.h" "PokedexEntry.h" "StateDetection.h" "WindowInfo.h")
target_link_libraries(pokemmoBot ${OpenCV_LIBS})

# TODO: Add tests and install targets if needed.
