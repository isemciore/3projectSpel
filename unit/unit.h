//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_UNIT_H
#define INC_3PROJECTSPEL_UNIT_H

#include <string>
#include <memory>
#include "../stuff/item.h"

class env_tile;

namespace wumpus_game{

    class unit {
    protected:
        std::string nameID;
        std::shared_ptr<env_tile> unitCurrLoc;


    public:
        unit(){}
        virtual ~unit(){};

        void setName(std::string name) {nameID=name;}
        std::string getName(){ return nameID;}
        virtual bool performAction() = 0;

    protected:


    };


}

#endif //INC_3PROJECTSPEL_UNIT_H
//