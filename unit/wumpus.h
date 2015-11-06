//
// Created by erik on 2015-11-06.
//

#ifndef INC_3PROJECTSPEL_WUMPUS_H
#define INC_3PROJECTSPEL_WUMPUS_H

#include "npc.h"

namespace wumpus_game {

    class wumpus : public npc {

    public:
        virtual bool performAction();
    };

}

#endif //INC_3PROJECTSPEL_WUMPUS_H
