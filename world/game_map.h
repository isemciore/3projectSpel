//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_WORLD_H
#define INC_3PROJECTSPEL_WORLD_H

#include "env_tile.h"
#include "../saveAload.h"
#include "../unit/player_ctrl.h"
#include <vector>
#include <map>
#include <memory>
namespace wumpus_game{
    class game_map {
    private:
        std::vector<std::shared_ptr<env_tile>> tilePointers;
        std::map<std::string,std::shared_ptr<unit>> unitMap;
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
        std::map<std::string,std::shared_ptr<unit>> getUnitMap(){ return unitMap;};
        std::shared_ptr<player_ctrl> getPlayerPtr(){ return playerP;};


    private:
        env_tile* createTile(int tileID);

    };

}
#endif //INC_3PROJECTSPEL_WORLD_H
