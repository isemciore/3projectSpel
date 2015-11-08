//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_PLAYER_CTRL_H
#define INC_3PROJECTSPEL_PLAYER_CTRL_H

#include <iostream>
#include "unit.h"
#include "../stuff/container.h"

namespace wumpus_game {
    class player_ctrl : public unit{

    public:
        player_ctrl():unit(){};
        ~player_ctrl();
        item* rightHand;
        item* leftHand;
        container* back;

        bool performAction();

        bool travelDirection(std::string);
        bool castSpell(std::string input);

        bool shotArrow(std::string);
        bool pickUpItem(std::string);
        bool dropItem(std::string);
        bool listNeightBours(std::string);
        //travel direction
        //cast spell Dir
        //shot arrow Dir
        //pick Up item
        //drop item
        //list neighbours direction
        //

    };
}

#endif //INC_3PROJECTSPEL_PLAYER_CTRL_H
