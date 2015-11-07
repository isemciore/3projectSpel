//
// Created by erik on 2015-11-06.
//

#ifndef INC_3PROJECTSPEL_TURTLE_H
#define INC_3PROJECTSPEL_TURTLE_H

#include "npc.h"

namespace wumpus_game {

    class turtle : public npc {
    public:
        turtle():npc(){};
        virtual ~turtle(){};
        bool performAction() override;
    };

}

#endif //INC_3PROJECTSPEL_TURTLE_H
