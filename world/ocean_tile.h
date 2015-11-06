//
// Created by erik on 2015-11-06.
//

#ifndef INC_3PROJECTSPEL_OCEAN_TILE_H
#define INC_3PROJECTSPEL_OCEAN_TILE_H

#include "env_tile.h"


namespace wumpus_game {
    class ocean_tile : public env_tile {
    public:
        ocean_tile(int);

        virtual void drop_item(item *obj);

        using env_tile::env_tile;

        virtual ~ocean_tile();

        virtual int direction() override;

        virtual std::weak_ptr<env_tile> direction(int dir) override {
            return neighbourPointer[dir];}

        virtual void enter(std::shared_ptr<unit> character) override;

        virtual void exit(std::shared_ptr<unit> character) override;

        virtual void pick_up(item *obj) override;


    };

}

#endif //INC_3PROJECTSPEL_OCEAN_TILE_H
