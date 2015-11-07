//
// Created by erik on 2015-11-05.
//

#include "game_Master.h"

//Map owns only sharedpointer to all tiles
//game_master owns all shared pointer character
//Item is allocated, one pointer to each item exist, owner of the item deletes it
wumpus_game::game_Master::game_Master(std::string &endCondition, wumpus_game::saveAload &loadFile)
    : endReason(endCondition)
    , saveFile(loadFile){
    //Fixing enviromental game_map
    //BIND EVERYTHING ATTACH EVRYTHING ETCETC, make it GAME RDY
    if (saveFile.isSaveFile()){
        mapSP.reset(new() game_map(saveFile));
    }
    else {
        //ASK STANDARD QUESTION AS PLAYER NAME AND WHAT IT PLAYS

        mapSP.reset(new() game_map);
        mapSP->set_n_Tiles(25);
        mapSP->bind_SQ_map();
        mapSP->defInitUnits();
        mapSP->defInitItems();

        //mapSP->host_Init_ITEM();
    }
}
wumpus_game::game_Master::~game_Master() {

}

//Run, for each char perform action, when return false
//check event if char and turtle in same slot
//false battle, make batlte checks here
//or if player, then analyze command here


//Handle item transfer here