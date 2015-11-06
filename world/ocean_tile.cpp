//
// Created by erik on 2015-11-06.
//

#include "ocean_tile.h"
#include "env_tile.h"

wumpus_game::ocean_tile::~ocean_tile() {

}

int wumpus_game::ocean_tile::direction() {
    return 5;
}

void wumpus_game::ocean_tile::enter(std::shared_ptr<unit> character) {

}

void wumpus_game::ocean_tile::exit(std::shared_ptr<unit> character) {

}

void wumpus_game::ocean_tile::pick_up(wumpus_game::item *obj) {

}

wumpus_game::ocean_tile::ocean_tile(int i) : env_tile(i) {
    dirFeasible[0] = true;
    dirFeasible[2] = true;
    dirFeasible[4] = true;
    dirFeasible[6] = true;
}

void wumpus_game::ocean_tile::drop_item(wumpus_game::item *obj) {

}
