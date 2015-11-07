//
// Created by erik on 2015-11-05.
//

#include "item.h"

wumpus_game::item::item(double weight, double volume, std::string name)
    : _weight(weight)
    , _volume(volume)
    , _itemName(name){

}

std::string wumpus_game::item::get_name() {
    return _itemName;
}
