//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_WORLD_H
#define INC_3PROJECTSPEL_WORLD_H

#include "world/env_tile.h"
#include "../saveAload.h"
#include "../unit/player_ctrl.h"
#include <vector>
#include <map>
#include <memory>
namespace wumpus_game{
    class game_map {

    typedef typename std::map<std::string, std::shared_ptr<env_tile>> typeTileMap;
    private:
        std::vector<std::shared_ptr<env_tile>> tilePointers;
        std::map<std::string,std::shared_ptr<unit>> unitMap;
        std::map<std::string,int> unitToLocMap;
        std::shared_ptr<player_ctrl> playerP;
        int nActivTiles;
        int max_n_tiles;
        int unitCreatorID = 0;
    public:
        game_map(){};
        game_map(saveAload saveFile);
        ~game_map();
        game_map(const game_map & srcMap) = delete;

        void set_n_Tiles(int nTiles);
        void bind_SQ_map();//bind tiles to each other
        void defInitUnits();
        bool addUnitToMap(std::shared_ptr<unit> SPunit, int locId);
        bool deleteUnit(std::string name);
        void defInitItems();
        bool addItemToMap(item* itemPointer,int locId);
        std::map<std::string,std::shared_ptr<unit>>& getUnitMap() { return unitMap; }

        std::shared_ptr<player_ctrl> getPlayerPtr(){ return playerP;};

        void inspectArea(std::shared_ptr<unit> src);//write out everything in local area

        std::pair<bool,std::string> travel(std::shared_ptr<unit> src, std::vector<std::string> commandArgs);
        std::pair<bool,std::string> attack(std::shared_ptr<unit> src, std::vector<std::string> commandArgs);
        std::pair<bool,std::string> cast(std::shared_ptr<unit> src, std::vector<std::string> commandArgs);//{return std::make_pair(true,"something");}
        std::pair<bool,std::string> shoot(std::shared_ptr<unit> src, std::vector<std::string> commandArgs);//{ return std::make_pair(true,"something");}
        std::pair<bool,std::string> pick(std::shared_ptr<unit> src, std::vector<std::string> commandArgs);
        std::pair<bool,std::string> drop(std::shared_ptr<unit> src, std::vector<std::string> commandArgs);
        std::pair<bool,std::string> moveItem(std::shared_ptr<unit> src, std::vector<std::string> commandArgs);
        /*bool attack(std::shared_ptr<unit> src, std::string commandArgs){ return true;}
        bool cast(std::shared_ptr<unit> src, std::string commandsArgs){ return true;}
        bool shoot(std::shared_ptr<unit> src, std::string commandsArgs){ return true;}
        bool pick(std::shared_ptr<unit> src, std::string commandsArgs){ return true;}
        bool drop(std::shared_ptr<unit> src, std::string commandsArgs){ return true;}*/


    private:
        env_tile* createTile(int tileID);
        std::pair<bool,std::string> distAtkHelp(std::shared_ptr<unit> plPtr, std::vector<std::string> commandArgs);
    };

}
#endif //INC_3PROJECTSPEL_WORLD_H
