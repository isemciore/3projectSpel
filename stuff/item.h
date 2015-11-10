//
// Created by erik on 2015-11-05.
//

#ifndef INC_3PROJECTSPEL_STUFF_H
#define INC_3PROJECTSPEL_STUFF_H

#include <string>

namespace wumpus_game {

    class item {
        int _weight;
        int _volume;
        std::string _itemName;
        bool containOther = false;
    public:
        item(double weight,double volume, std::string name);
        item();


        std::string get_name();


    };

}
#endif //INC_3PROJECTSPEL_STUFF_H
