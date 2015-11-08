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
        allUnits = mapSP->getUnitMap();
        mapSP->defInitItems();
        playerPtr = mapSP->getPlayerPtr();
        //mapSP->host_Init_ITEM();
    }
    /*
    typedef bool (player_ctrl::*MFP)(...);
    std::map<std::string, MFP> mpFunctionP;
    mpFunctionP.insert(std::make_pair("cast", &player_ctrl::castSpell));
*/
    //Insert all player member function here
    mapofMFP.insert(std::make_pair("cast",&player_ctrl::castSpell));


    std::map<std::string, MFP>::iterator itp = mapofMFP.find("cast");
    MFP memPointer = itp->second;
    bool res = ((*playerPtr).*memPointer)("Test output string");


    std::cout << res << "\n";

}
//Run, for each char perform action, when return false
//check event if char and turtle in same slot
//false battle, make batlte checks here
void wumpus_game::game_Master::begin_Game() {
    int turnNumber = 0;
    while(turnNumber < 20){

        turnNumber++;
    }
}

wumpus_game::game_Master::~game_Master() {

}


//or if player, then analyze command here


//Handle item transfer here
