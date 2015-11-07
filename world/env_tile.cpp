//
// Created by erik on 2015-11-05.
//

#include "env_tile.h"

wumpus_game::env_tile::~env_tile() {

}

bool wumpus_game::env_tile::add_Item(wumpus_game::item *obj) {
    stuffInRoom.insert(std::make_pair(obj->get_name(),obj));
}
