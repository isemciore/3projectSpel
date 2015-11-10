//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_UNIT_H
#define INC_3PROJECTSPEL_UNIT_H

#include <string>
#include <memory>
#include "../stuff/item.h"

namespace wumpus_game{

    class unit {
    protected:
        std::string nameID;


    public:
        unit(){}
        virtual ~unit(){};

        void setName(std::string name) {nameID=name;}
        std::string getName() const { return nameID;}
        virtual bool performAction() = 0;


        virtual bool takeDamage(int) = 0;
        virtual int attackDamage() = 0;

        virtual bool retaliation(){ return true;}
    protected:


    };


}

namespace std {
    template <>
    class hash<wumpus_game::unit>{
    public :
        size_t operator()(const wumpus_game::unit &src ) const
        {
            return hash<string>()(src.getName());
        }
    };
};



#endif //INC_3PROJECTSPEL_UNIT_H
//