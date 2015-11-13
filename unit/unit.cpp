//
// Created by erik on 2015-11-05.
//

#include "unit.h"

wumpus_game::unit::unit() {

}

wumpus_game::unit::unit(std::string nameID, std::weak_ptr<wumpus_game::env_tile> ptr) {
    nameID = nameID;
    currentLPT = ptr;
}
