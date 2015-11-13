//
// Created by erik on 2015-11-07.
//

#ifndef INC_3PROJECTSPEL_PALADIN_H
#define INC_3PROJECTSPEL_PALADIN_H

#include "player_ctrl.h"

namespace wumpus_game {

    class paladin : public player_ctrl {
    public:
        using player_ctrl::player_ctrl;
        paladin():player_ctrl(){}
    };

}

#endif //INC_3PROJECTSPEL_PALADIN_H
