//
// Created by erik on 2015-11-06.
//

#include "ocean_tile.h"
#include "env_tile.h"

wumpus_game::ocean_tile::~ocean_tile() {

}


bool wumpus_game::ocean_tile::enter(std::weak_ptr<unit> character) {

}

void wumpus_game::ocean_tile::exit(std::weak_ptr<unit> character) {

}

void wumpus_game::ocean_tile::pick_up(wumpus_game::item *obj) {

}

wumpus_game::ocean_tile::ocean_tile(int i) : env_tile(i) {
    dirFeasible[0] = true;
    dirFeasible[2] = true;
    dirFeasible[4] = true;
    dirFeasible[6] = true;
}
