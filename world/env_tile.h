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
namespace wumpus_game{
    class env_tile {
    protected://Data
        int roomId;
        bool weaponWork;
        bool accessible = true;
        std::map<std::string, item*> stuffInRoom;
        std::map<std::string, std::weak_ptr<unit>> charInRoom;
        std::map<std::string, std::weak_ptr<env_tile>> neighbourPointer;
        bool dirFeasible[8] = {false};

    public:
        explicit env_tile(int id):roomId(id){}
        env_tile(const env_tile & srcTile) = delete;

        virtual ~env_tile();
        std::map<std::string,std::weak_ptr<env_tile>> direction(){ return neighbourPointer;};
        virtual bool enter(std::weak_ptr<unit> character) = 0;
        virtual void exit(std::weak_ptr<unit> character) = 0;
        virtual void pick_up(item * obj) = 0;

        friend class game_map;

    private:

    };

}

#endif //INC_3PROJECTSPEL_TILE_H
