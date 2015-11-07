//
// Created by erik on 2015-11-05.
//

#include "pit_tile.h"


wumpus_game::pit_tile::~pit_tile() {

}


bool wumpus_game::pit_tile::enter(std::shared_ptr<unit> character) {
    return false;
}


wumpus_game::pit_tile::pit_tile(int n) : env_tile(n) {
    accessible = false;
}

bool wumpus_game::pit_tile::pick_up(std::string string) {
    return false;
}

void wumpus_game::pit_tile::exit(std::shared_ptr<unit> character) {
}
