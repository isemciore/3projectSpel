//
// Created by erik on 2015-11-05.
//

#include "game_Master.h"
#include "unit/wumpus.h"

//Map owns only sharedpointer to all tiles
//game_master owns all shared pointer character
//Item is allocated, one pointer to each item exist, owner of the item deletes it
wumpus_game::game_Master::game_Master(std::string &endCondition, wumpus_game::saveAload &loadFile)
    : mapSP(new map)
    , endReason(endCondition)
    , saveFile(loadFile){
    //Fixing enviromental map
    //BIND EVERYTHING ATTACH EVRYTHING ETCETC, make it GAME RDY
    if (saveFile.isSaveFile()){
    }
    else {
        mapSP->set_n_Tiles(25);
        mapSP->bind_SQ_map();

        std::shared_ptr<unit> shP(new wumpus);
        allUnits.push_back(shP);

        //Wumpus
        //Player

        //mapSP->host_Init_ITEM();
    }
}
wumpus_game::game_Master::~game_Master() {

}

