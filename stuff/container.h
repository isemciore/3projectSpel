//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_CONTAINER_H
#define INC_3PROJECTSPEL_CONTAINER_H

#include <vector>
#include "item.h"
#include <memory>
#include <map>
namespace wumpus_game {
    class container : public item {
        //std::vector<item> itemsInBp;
    private:
        int _hold_weight;
        int _hold_volume;
        std::map<std::string, item*> stuffInContainer;

    public:
        container(int hold_weight, int hold_volume,std::string name);
        container(const container &) = delete;
        bool add(item*){ return true};
        item* getFromBP(std::string itemName){
            auto itPair = stuffInContainer.find(itemName);
            if (itPair!= stuffInContainer.end()){
                item* itemPtr = itPair->second;
                stuffInContainer.erase(itPair);
                return itemPtr;
            }
            return nullptr;
        }
        bool consume(const item &);
        bool containItem(std::string item) {
            auto itPair = stuffInContainer.find(item);
            return itPair == stuffInContainer.end();
        }


    };

}

#endif //INC_3PROJECTSPEL_CONTAINER_H
