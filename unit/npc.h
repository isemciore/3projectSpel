//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_NPC_H
#define INC_3PROJECTSPEL_NPC_H

#include "unit.h"

namespace wumpus_game {
    class npc : public unit{
    public:
        npc();
        npc(const npc& ) = delete;
        virtual ~npc();

        virtual bool performAction() = 0;
    };
}

#endif //INC_3PROJECTSPEL_NPC_H
