//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_TILE_H
#define INC_3PROJECTSPEL_TILE_H
#include "../unit/unit.h"
#include "../stuff/item.h"

#include <memory>
#include <map>
#include <vector>
#include "../unit/player_ctrl.h"

namespace wumpus_game{
    class env_tile {
    protected://Data
        int roomId;
        bool weaponWork;
        bool accessible = true;
        std::map<std::string, item*> stuffInRoom;
        std::map<std::string, std::shared_ptr<unit>> charInRoom;
        std::map<std::string, std::shared_ptr<env_tile>> neighbourPointer;
        bool dirFeasible[8] = {false};

    public:
        explicit env_tile(int id):roomId(id){}
        env_tile(const env_tile & srcTile) = delete;

        virtual ~env_tile();
        std::map<std::string,std::shared_ptr<env_tile>> direction(){ return neighbourPointer;};
        virtual bool enter(std::shared_ptr<unit> character) = 0;
        virtual void exit(std::shared_ptr<unit> character);
        virtual bool pick_up(std::string,std::shared_ptr<player_ctrl>);
        virtual bool add_Item(item* obj);
        friend class game_map;

    private:

    };

}

#endif //INC_3PROJECTSPEL_TILE_H
