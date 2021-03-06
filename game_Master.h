//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_GAME_MASTER_H
#define INC_3PROJECTSPEL_GAME_MASTER_H

#include "unit/unit.h"
#include "stuff/item.h"
#include <memory>
#include "saveAload.h"
#include "game_map.h"
//Have unique id for TILE, UNIT. handle output save and item and create world unit...
// Handle creating new item / character
// after every turn, it reads through publishing style.
namespace wumpus_game {
    class game_Master {
        typedef std::pair<bool,std::string> (game_map::* MFP)(std::shared_ptr<unit> src, std::vector<std::string> argsCmd);

    private:
        const int DEFAULT_MAP_SIZE = 25;
        std::shared_ptr<game_map> mapSP;                     //
        std::map<std::string,std::shared_ptr<unit>> allUnits;    // All items is handled via new and delete
        std::string& endReason;
        saveAload& saveFile;
        std::shared_ptr<player_ctrl> playerPtr;
        std::map<std::string, MFP> mapofMFP;

    public:
        game_Master() = delete;
        game_Master(const game_Master&) = delete;
        game_Master(std::string & endCondition, saveAload& loadFile);
        ~game_Master();


        void begin_Game();

        //Char input, if return false, then exit game, look if it is due to save game or load game
        //if load game report back to main and restart

        //Game master iniates default, or with savefile

    };

}


#endif //INC_3PROJECTSPEL_GAME_MASTER_H
