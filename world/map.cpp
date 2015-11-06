//
// Created by erik on 2015-11-05.
//

#include <iostream>
#include "map.h"
#include "ocean_tile.h"
#include "desert_tile.h"
#include "jungle_tile.h"
#include "pit_tile.h"

wumpus_game::map::~map() {

}

void wumpus_game::map::set_n_Tiles(int nTiles){
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




wumpus_game::env_tile* wumpus_game::map::createTile(int tileID) {
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

wumpus_game::map::map(wumpus_game::saveAload saveFile) {

}

void wumpus_game::map::bind_SQ_map() {
    //SQUARE MAP 5*5, SOUTHWEST ID 0, NORTH WEST ID 4
    //assuming square widht is 5, 5 eleents for east/west, +-1 for north or south
        //Elt is a sharedpointer to a tile, each shared pointer has 8 weak pointer to neighbours located in a vector;
        //neightbour pointer is placer CLOCKWISE start from NORTH

    //BINDING NORTH
    for(auto &activeTile:tilePointers){
        auto emptyP = [&activeTile](){std::weak_ptr<env_tile> dummy; activeTile->neighbourPointer.push_back(dummy);};
        auto attachRoom = [&activeTile, this](int roomID){ activeTile->neighbourPointer.push_back((std::weak_ptr<env_tile>) tilePointers[roomID]);};
        int currRoom = activeTile->roomId;
        //std::weak_ptr<env_tile> dummy;
        // room does not have wall to north and the room to north is accessible
        if (((currRoom+1)%5) && tilePointers[currRoom+1]->accessible && activeTile->dirFeasible[0]){
            std::weak_ptr<env_tile> tmpNorthPointer = tilePointers[currRoom+1];
            activeTile->neighbourPointer.push_back(tmpNorthPointer);
            activeTile->dirExist[0] = true;
        }else{emptyP;}//elt->neighbourPointer.push_back(dummy);}
        //connect to NORTHEAST add constant 5 to go east, -5 to check west
        if (((currRoom+1)%5) && (currRoom < 20) && tilePointers[currRoom+1+5]->accessible && activeTile->dirFeasible[1]){
            std::weak_ptr<env_tile> tmpNEP = tilePointers[currRoom+1+5];
            activeTile->neighbourPointer.push_back(tmpNEP);
            activeTile->dirExist[1] = true;
        }else{emptyP;}//elt->neighbourPointer.push_back(dummy);}
        //east connect
        if ((currRoom < 20) && tilePointers[currRoom+5]->accessible && activeTile->dirFeasible[2]){
            activeTile->neighbourPointer.push_back((std::weak_ptr<env_tile>) tilePointers[currRoom+5]);
            activeTile->dirExist[2]=true;
        } else{emptyP;}
        //south east connect
        if ((currRoom%5) && (currRoom< 20) && tilePointers[currRoom+5-1]->accessible && activeTile->dirFeasible[3]){
            attachRoom(currRoom+5-1);
            activeTile->dirExist[3]=true;
        }else{emptyP;}
        //south
        if ((currRoom%5)                   && tilePointers[currRoom-1]->accessible   && activeTile->dirFeasible[4]){
            attachRoom(currRoom-1);
            activeTile->dirExist[4]=true;
        }else{emptyP;}
        //southWest
        if ((currRoom%5) && (currRoom>4)   && tilePointers[currRoom-1-5]->accessible && activeTile->dirFeasible[5]){
            attachRoom(currRoom-1-5);
            activeTile->dirExist[5]=true;
        }else{emptyP;};
        //west
        if ( currRoom > 4                  && tilePointers[currRoom-5]->accessible   && activeTile->dirFeasible[6]){
            attachRoom(currRoom-5);
            activeTile->dirExist[6]=true;
        }else{emptyP;};
        //NorthWest
        if ( currRoom > 4 && (currRoom+1)%5 && tilePointers[currRoom-5+1]->accessible   && activeTile->dirFeasible[7]){
            attachRoom(currRoom-5+1);
            activeTile->dirExist[7]=true;
        }else{emptyP;};

    }



}

