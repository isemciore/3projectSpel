//
// Created by erik on 2015-11-05.
//

#include "game_Master.h"
#include <sstream>
#include <iterator>

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
    mapofMFP.insert(std::make_pair("travel",&game_map::travel));
    /*mapofMFP.insert(std::make_pair("attack",&game_map::attack));
    mapofMFP.insert(std::make_pair("cast",&game_map::cast));
    mapofMFP.insert(std::make_pair("shoot",&game_map::shoot));
    mapofMFP.insert(std::make_pair("pick",&game_map::pick));
    mapofMFP.insert(std::make_pair("drop",&game_map::drop));*/



    //std::map<std::string, MFP>::iterator itp = mapofMFP.find("cast");
    //MFP memPointer = itp->second;
    //bool res = ((*playerPtr).*memPointer)("Test output string");
    //bool res = ((*playerPtr).*((mapofMFP.find("cast"))->second))("Test output string");
    //std::cout << res << "\n";

}
//Run, for each char perform action, when return false
//check event if char and turtle in same slot
//false battle, make batlte checks here
void wumpus_game::game_Master::begin_Game() {
    int turnNumber = 0;
    bool endTurn = false;
    std::string keyw;
    std::string memFunCmd;
    while(turnNumber < 4){
        std::cout << "current turn number "<<turnNumber <<"\n";
        //check all tiles and see if wumpus is with player
        //
        for(auto &characterSP: allUnits){
            if (characterSP.second == playerPtr){
                //Check what is in same tile as player //eventual message
                //then list possible action
                while(!endTurn){
                    std::cin >> keyw;
                    getline(std::cin,memFunCmd);

                    std::stringstream ss(memFunCmd);
                    std::istream_iterator<std::string> begin(ss);
                    std::istream_iterator<std::string> end;
                    std::vector<std::string> vstrings(begin, end);


                    std::map<std::string, MFP>::iterator iTP = mapofMFP.find(keyw);
                    if (iTP != mapofMFP.end()){
                        MFP memPointer = iTP->second;
                        std::shared_ptr<unit> uSP = characterSP.second;
                        std::pair<bool,std::string> res = ((*mapSP).*memPointer)(uSP,vstrings);
                        endTurn = res.first;
                        //READ END FOR EXTRA INFOOMRATION FROM STR
                    }else{
                        std::cout << "First word not keyword \n";
                    }
                }
                endTurn = false;
                //CHeck if walked into wumpus //IF break
                //check if wumpus is still left
            } else{
                characterSP.second->performAction();
                //Check if walked into user room, then message //if wumpus, break
            }
        }


        turnNumber++;
    }
}

wumpus_game::game_Master::~game_Master() {

}


//or if player, then analyze command here


//Handle item transfer here
