//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_CONTAINER_H
#define INC_3PROJECTSPEL_CONTAINER_H

#include <vector>
#include "item.h"
namespace wumpus_game {
    class container : item {
        std::vector<item> itemsInBp;
    private:
        int hold_weight;
        int hold_volume;

    public:
        container(const container &) = delete;

        bool add(const item &);
        bool move(const item &, std::vector<item> dst);
        bool consume(const item &);
        bool move(const item & item_to_be_moved, const container& dst_cont);
        bool containItem(std::string item);




    };

}

#endif //INC_3PROJECTSPEL_CONTAINER_H
