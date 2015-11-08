//
// Created by erik on 2015-11-05.
//

#include <iostream>
#include "game_map.h"
#include "ocean_tile.h"
#include "desert_tile.h"
#include "jungle_tile.h"
#include "pit_tile.h"
#include "../unit/paladin.h"
#include "../unit/wumpus.h"
#include "../unit/turtle.h"
#include "../stuff/container.h"

wumpus_game::game_map::~game_map() {

}

void wumpus_game::game_map::set_n_Tiles(int nTiles){
    max_n_tiles = nTiles;
    nActivTiles=0;

    for(int i = 0; i<max_n_tiles;++i){
        if(i==12){//Pittile
            std::shared_ptr<env_tile> tSP(createTile(-1));
            tilePointers.push_back(tSP);
        }
        else{
            int tileType = rand()%3;
            std::shared_ptr<env_tile> tSP(createTile(tileType));
            tilePointers.push_back(tSP);
        }

        nActivTiles++;
    }


}




wumpus_game::env_tile* wumpus_game::game_map::createTile(int tileID) {
    env_tile* tileAns;
    if (tileID==0){
        tileAns = new ocean_tile(nActivTiles);
    } else if(tileID==1){
        tileAns = new ocean_tile(nActivTiles);
    } else if (tileID==2){
        tileAns = new ocean_tile(nActivTiles);
    } else if (tileID==-1){
        tileAns = new pit_tile(nActivTiles);
    }
    return tileAns;
}

wumpus_game::game_map::game_map(wumpus_game::saveAload saveFile) {

}

void wumpus_game::game_map::bind_SQ_map() {
    //SQUARE MAP 5*5, SOUTHWEST ID 0, NORTH WEST ID 4
    //assuming square widht is 5, 5 eleents for east/west, +-1 for north or south
        //Elt is a sharedpointer to a tile, each shared pointer has 8 weak pointer to neighbours located in a vector;
        //neightbour pointer is placer CLOCKWISE start from NORTH

    //BINDING NORTH
    for(auto &activeTile:tilePointers){
        auto attachRoom = [&activeTile, this](int roomID,std::string dir){
            std::shared_ptr<env_tile> wpTile = tilePointers[roomID];
            activeTile->neighbourPointer.insert(std::make_pair(dir, wpTile));};
        int currRoom = activeTile->roomId;
        //std::shared_ptr<env_tile> dummy;
        // room does not have wall to north and the room to north is accessible
        if (((currRoom+1)%5) && tilePointers[currRoom+1]->accessible && activeTile->dirFeasible[0]){
            attachRoom(currRoom+1,"NORTH");
        }
        //connect to NORTHEAST add constant 5 to go east, -5 to check west
        if (((currRoom+1)%5) && (currRoom < 20) && tilePointers[currRoom+1+5]->accessible && activeTile->dirFeasible[1]){
            attachRoom(currRoom+1+5,"NORTHEAST");
        }
        //east connect
        if ((currRoom < 20) && tilePointers[currRoom+5]->accessible && activeTile->dirFeasible[2]){
            attachRoom(currRoom+5,"EAST");
        }
        //south east connect
        if ((currRoom%5) && (currRoom< 20) && tilePointers[currRoom+5-1]->accessible && activeTile->dirFeasible[3]){
            attachRoom(currRoom+5-1,"SOUTHEAST");
        }
        //south
        if ((currRoom%5)                   && tilePointers[currRoom-1]->accessible   && activeTile->dirFeasible[4]){
            attachRoom(currRoom-1,"SOUTH");
        }
        //southWest
        if ((currRoom%5) && (currRoom>4)   && tilePointers[currRoom-1-5]->accessible && activeTile->dirFeasible[5]){
            attachRoom(currRoom-1-5,"SOUTHWEST");
        }
        //west
        if ( currRoom > 4                  && tilePointers[currRoom-5]->accessible   && activeTile->dirFeasible[6]){
            attachRoom(currRoom-5,"WEST");
        }
        //NorthWest
        if ( currRoom > 4 && (currRoom+1)%5 && tilePointers[currRoom-5+1]->accessible   && activeTile->dirFeasible[7]){
            attachRoom(currRoom-5+1,"NORTHWEST");
        }

    }



}

void wumpus_game::game_map::defInitUnits() {
    //Player name Meep
    //def paladin
    std::shared_ptr<unit> spUnit;
    spUnit.reset(new() paladin);
    spUnit->setName("Meep");
    addUnitToMap(spUnit,0);
    spUnit.reset(new() wumpus);
    spUnit->setName("Wumpus");
    addUnitToMap(spUnit,10);
    int turt_loc[] = {4, 16, 24};
    for(int elt: turt_loc){
        spUnit.reset(new() turtle);
        spUnit->setName("Turtle"+std::to_string(unitCreatorID++));
        addUnitToMap(spUnit,elt);
    }

}

bool wumpus_game::game_map::addUnitToMap(std::shared_ptr<unit> spUnit, int locId) {
    std::shared_ptr<unit> wpUnit = spUnit;


    bool success = tilePointers[locId]->enter(wpUnit);
    if (success){
        unitMap.insert(std::make_pair(spUnit->getName(),spUnit));
        return true;
    }
    return false;
}

bool wumpus_game::game_map::deleteUnit(std::string name) {
    return false;
}

void wumpus_game::game_map::defInitItems() {
    item* staff = new item(1,0.1,"staff");
    item* bow = new item(1,0.1,"bow");
    item* backpack = new container(10,0.5,"Normal Backpack");
    addItemToMap(backpack,0);
    addItemToMap(staff,1);
    addItemToMap(bow,1);
}

bool wumpus_game::game_map::addItemToMap(wumpus_game::item *itemPointer, int locId) {
    tilePointers[locId]->add_Item(itemPointer);
    return true;
}
