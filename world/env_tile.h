//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_TILE_H
#define INC_3PROJECTSPEL_TILE_H
#include "../unit/unit.h"
#include "../stuff/item.h"

#include <memory>
#include <vector>
namespace wumpus_game{
    class env_tile {
    protected://Data
        int roomId;
        bool weaponWork;
        bool accessible = true;
        std::vector<item> stuffInThisRoom;
        std::vector<unit> charInThisRoom;
        std::vector<std::weak_ptr<env_tile>> neighbourPointer;
        bool dirFeasible[8] = {false};
        bool dirExist[8] = {false};

    public:
        explicit env_tile(int id):roomId(id){}
        env_tile(const env_tile & srcTile) = delete;

        virtual ~env_tile();

        virtual int direction() = 0;
        virtual std::weak_ptr<env_tile> direction(int dir) = 0;
        virtual void enter(std::shared_ptr<unit> character) = 0;
        virtual void exit(std::shared_ptr<unit> character) = 0;
        virtual void pick_up(item * obj) = 0;

        friend class game_map;

    private:

    };

}

#endif //INC_3PROJECTSPEL_TILE_H
