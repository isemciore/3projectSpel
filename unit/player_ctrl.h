//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_PLAYER_CTRL_H
#define INC_3PROJECTSPEL_PLAYER_CTRL_H

#include "unit.h"

namespace wumpus_game {
    class player_ctrl : public unit{
    public:
        player_ctrl():unit(){};
        ~player_ctrl();


        bool performAction();
    };
}

#endif //INC_3PROJECTSPEL_PLAYER_CTRL_H
