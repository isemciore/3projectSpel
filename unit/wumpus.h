//
// Created by erik on 2015-11-06.
//

#ifndef INC_3PROJECTSPEL_WUMPUS_H
#define INC_3PROJECTSPEL_WUMPUS_H

#include "npc.h"

namespace wumpus_game {

    class wumpus : public npc {

    public:
        wumpus():npc(){};
        virtual ~wumpus(){};
        bool performAction() override;
    };

}

#endif //INC_3PROJECTSPEL_WUMPUS_H
