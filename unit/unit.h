//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_UNIT_H
#define INC_3PROJECTSPEL_UNIT_H

#include <string>
#include <memory>
#include <vector>
#include "../stuff/item.h"
#include "../world/env_tile.h"
namespace wumpus_game{
    class env_tile;

    class unit {
    protected:
        std::string nameID;
        std::weak_ptr<env_tile> currentLPT;
        std::string unitType;

    public:
        unit();
        unit(std::string nameID,std::weak_ptr<env_tile>);
        virtual ~unit(){};

        void setName(std::string name) {nameID=name;}
        std::string getName() const { return nameID;}
        virtual bool performAction() = 0;


        virtual bool takeDamage(int) = 0;
        virtual int attackDamage() = 0;

        virtual bool retaliation(){ return true;}

        virtual bool hasItem(std::string){return false;}
        virtual bool addItem(item* itemPtr, std::string location){ return false;}
        virtual item* get_item(std::string itemName){ return nullptr;}

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