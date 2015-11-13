//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_PLAYER_CTRL_H
#define INC_3PROJECTSPEL_PLAYER_CTRL_H

#include <iostream>
#include "unit.h"
#include "../stuff/container.h"

namespace wumpus_game {
    class unit;

    class player_ctrl : public unit {
    public:
        using unit::unit;
        player_ctrl();
        ~player_ctrl();
        item* rightHand;
        item* leftHand;
        item* head;
        container* back;

        virtual bool takeDamage(int i);

        virtual int attackDamage();

        bool performAction();
    };
}

#endif //INC_3PROJECTSPEL_PLAYER_CTRL_H
