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
        item* googles;
        container* back;

        bool performAction();

        //travel direction
        //cast spell Dir
        //shot arrow Dir
        //pick Up item
        //drop item
        //list neighbours direction
        //

        virtual bool hasItem(std::string string) override;

        virtual bool addItem(item *itemPtr, std::string location) override;

        virtual item *get_item(std::string itemName) override;

        virtual bool takeDamage(int i) override;

        virtual bool moveItem(std::vector<std::string> vStringcmd);

        virtual int attackDamage() override;
    };
}

#endif //INC_3PROJECTSPEL_PLAYER_CTRL_H
