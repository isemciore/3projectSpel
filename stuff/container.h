//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_CONTAINER_H
#define INC_3PROJECTSPEL_CONTAINER_H

#include <vector>
#include "item.h"
#include <map>
namespace wumpus_game {
    class container : item {
        //std::vector<item> itemsInBp;
        std::map<std::string, item*> stuffInContainer;
    private:
        int _hold_weight;
        int _hold_volume;

    public:
        container(int hold_weight, int hold_volume,std::string name);

        container(const container &) = delete;

        bool add(const item *);
        item* dropFromBP(std::string);
        bool consume(const item &);
        bool move(const item & item_to_be_moved, const container& dst_cont);
        bool containItem(std::string item);




    };

}

#endif //INC_3PROJECTSPEL_CONTAINER_H
