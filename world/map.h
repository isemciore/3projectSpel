//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_WORLD_H
#define INC_3PROJECTSPEL_WORLD_H

#include "env_tile.h"
#include "../saveAload.h"
#include <vector>
#include <memory>
namespace wumpus_game{
    class map{
    private:
        std::vector<std::shared_ptr<env_tile>> tilePointers;
        int nActivTiles;
        int max_n_tiles;
    public:
        map(){};
        map(saveAload saveFile);
        ~map();
        map(const map & srcMap);

        void set_n_Tiles(int nTiles);
        void bind_SQ_map();//bind tiles to each other


    private:
        env_tile* createTile(int tileID);

    };

}
#endif //INC_3PROJECTSPEL_WORLD_H
