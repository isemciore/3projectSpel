//
// Created by erik on 2015-11-05.
//

#include "container.h"
#include <memory>
wumpus_game::container::container(int hold_weight, int hold_volume, std::string name)
    : item(0,0,name)
    , _hold_weight(hold_weight)
    , _hold_volume(hold_volume){

}

