//
// Created by erik on 2015-11-05.
//

#include "pit_tile.h"


wumpus_game::pit_tile::~pit_tile() {

}

int wumpus_game::pit_tile::direction() {
 return 0;
}


void wumpus_game::pit_tile::enter(std::shared_ptr<unit> character) {

}

void wumpus_game::pit_tile::exit(std::shared_ptr<unit> character) {

}

void wumpus_game::pit_tile::pick_up(wumpus_game::item *obj) {

}

wumpus_game::pit_tile::pit_tile(int n) : env_tile(n) {
    accessible = false;
}
