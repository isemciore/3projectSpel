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
        using env_tile::env_tile;

        virtual ~ocean_tile();


        virtual bool enter(std::shared_ptr<unit> character) override;

        virtual void exit(std::shared_ptr<unit> character) override;


    };

}

#endif //INC_3PROJECTSPEL_OCEAN_TILE_H
