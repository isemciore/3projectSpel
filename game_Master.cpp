//
// Created by erik on 2015-11-05.
//

#include "game_Master.h"
#include "unit/wumpus.h"
#include "unit/turtle.h"

//Map owns only sharedpointer to all tiles
//game_master owns all shared pointer character
//Item is allocated, one pointer to each item exist, owner of the item deletes it
wumpus_game::game_Master::game_Master(std::string &endCondition, wumpus_game::saveAload &loadFile)
    : mapSP(new map)
    , endReason(endCondition)
    , saveFile(loadFile){
    //member function pointer to add character
    //Ugh
    //void (*addCharPtr)( std::weak_ptr<unit>,int) = mapSP->add_char;
    //auto addCharPtr = [this](std::weak_ptr<unit> weakPtr, int target){mapSP->add_char(weakPtr,target);};

    //Fixing enviromental map
    //BIND EVERYTHING ATTACH EVRYTHING ETCETC, make it GAME RDY
    if (saveFile.isSaveFile()){
    }
    else {
        mapSP->set_n_Tiles(25);
        mapSP->bind_SQ_map();
        std::shared_ptr<unit> shP(new wumpus);
        std::weak_ptr<unit> weakWump = shP;
        allUnits.push_back(shP);
        mapSP->add_char(weakWump,10);
        //Can "fail" ignoring it, just means not adding bat
        add_char_Bat(24);
        add_char_Bat(15);
        add_char_Bat(4);


        //Wumpus
        //Player

        //mapSP->host_Init_ITEM();
    }
}
wumpus_game::game_Master::~game_Master() {

}

bool wumpus_game::game_Master::add_char_Bat(int posi) {
    std::shared_ptr<unit> sharedPtrBat(new turtle);
    std::weak_ptr<unit> weakPtr=sharedPtrBat;
    bool success_add = mapSP->add_char(sharedPtrBat,posi);
    if (success_add) {
        allUnits.push_back(sharedPtrBat);
        return true;
    }
    return false;
}
