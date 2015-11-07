//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_PIT_TILE_H
#define INC_3PROJECTSPEL_PIT_TILE_H

#include "env_tile.h"

namespace wumpus_game {
    class pit_tile : public env_tile{

    public:
        pit_tile(int n);
        using env_tile::env_tile;
        virtual ~pit_tile();

        virtual bool enter(std::shared_ptr<unit> character) override;

        virtual void exit(std::shared_ptr<unit> character) override;


        virtual bool pick_up(std::string string);
    };
}


#endif //INC_3PROJECTSPEL_PIT_TILE_H
