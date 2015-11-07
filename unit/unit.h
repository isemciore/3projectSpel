//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_UNIT_H
#define INC_3PROJECTSPEL_UNIT_H

#include <string>
#include "../stuff/item.h"

namespace wumpus_game{

    class unit {
        std::string nameID;
        int nGripP;
        item** itemP;

    public:
        unit(){}
        virtual ~unit(){};

        void setName(std::string name) {nameID=name;}
        std::string getName(){ return nameID;}
        virtual bool performAction() = 0;
    };


}

#endif //INC_3PROJECTSPEL_UNIT_H
