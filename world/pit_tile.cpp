//
// Created by erik on 2015-11-05.
//

#include "pit_tile.h"


wumpus_game::pit_tile::~pit_tile() {

}


bool wumpus_game::pit_tile::enter(std::weak_ptr<unit> character) {

}

void wumpus_game::pit_tile::exit(std::weak_ptr<unit> character) {

}


wumpus_game::pit_tile::pit_tile(int n) : env_tile(n) {
    accessible = false;
}

bool wumpus_game::pit_tile::pick_up(std::string string) {
    return false;
}
