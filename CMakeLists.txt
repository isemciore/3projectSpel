cmake_minimum_required(VERSION 3.3)
project(3projectSpel)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include_directories(unit)

set(SOURCE_FILES main.cpp game_map.cpp game_map.h world/env_tile.cpp world/env_tile.h unit/unit.cpp
        unit/unit.h stuff/item.cpp stuff/item.h stuff/container.cpp stuff/container.h world/pit_tile.cpp
        world/pit_tile.h game_Master.cpp game_Master.h unit/player_ctrl.cpp unit/player_ctrl.h unit/npc.cpp
        unit/npc.h saveAload.cpp saveAload.h world/end_Gtile.cpp world/end_Gtile.h world/ocean_tile.cpp
        world/ocean_tile.h unit/mage.cpp unit/mage.h unit/paladin.cpp unit/paladin.h
        unit/turtle.cpp unit/turtle.h unit/wumpus.cpp unit/wumpus.h stuff/consumable.cpp stuff/consumable.h)
add_executable(3projectSpel ${SOURCE_FILES})

