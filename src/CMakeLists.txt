cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SFML_DIR "/usr/lib/x86_64-linux-gnu/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS system graphics audio REQUIRED)
project(AOM VERSION 1.0)
add_executable(ex main.cpp classes/BoutonAction.cpp classes/InfoGame.cpp classes/Invoker.cpp classes/Command.hpp classes/DemonstrationCommand.cpp classes/Win.hpp classes/Menu.cpp classes/Hex.cpp classes/Grid.cpp classes/Region.cpp classes/CommandRegistry.hpp classes/ActionManager.cpp classes/MoveCommand.cpp classes/DestroyCommand classes/BuildPoliceStationCommand classes/BuildZADCommand)
target_include_directories(ex PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ex PRIVATE sfml-graphics sfml-system sfml-audio)

