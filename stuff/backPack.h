//
// Created by erik on 2015-11-07.
//

#ifndef INC_3PROJECTSPEL_BACKPACK_H
#define INC_3PROJECTSPEL_BACKPACK_H

#include "container.h"

namespace wumpus_game {

    class backPack : public container{
    public:
        backPack(int hold_weight, int hold_vol, std::string name);

    };

}

#endif //INC_3PROJECTSPEL_BACKPACK_H
