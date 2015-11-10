//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_NPC_H
#define INC_3PROJECTSPEL_NPC_H

#include "unit.h"

namespace wumpus_game {
    class npc : public unit{
    public:
        npc():unit(){};


        virtual bool takeDamage(int i);

        virtual int attackDamage();

        ~npc();

        virtual bool performAction();
    };
}

#endif //INC_3PROJECTSPEL_NPC_H
