//
// Created by erik on 2015-11-05.
//

#include "env_tile.h"

wumpus_game::env_tile::~env_tile() {

}

bool wumpus_game::env_tile::add_Item(wumpus_game::item *obj) {
    stuffInRoom.insert(std::make_pair(obj->get_name(),obj));
}

//incase check if player has right item to pick up for certain area
bool wumpus_game::env_tile::pick_up(std::string item_name, std::shared_ptr<wumpus_game::player_ctrl> ptr) {
    auto iterator = stuffInRoom.find(item_name);
    if (iterator==stuffInRoom.end()){
        return false;//item does not exist
    }
    return iterator->second;
}

void wumpus_game::env_tile::exit(std::shared_ptr<wumpus_game::unit> character) {
    typedef std::map<std::string,std::shared_ptr<wumpus_game::unit>>::iterator mapIterator;
    std::pair<mapIterator,mapIterator> itPair = charInRoom.equal_range(character->getName());

    while(itPair.first != itPair.second){
        if (itPair.first->second == character){
            charInRoom.erase(itPair.first);
            return ;
        }
        (itPair.first)++;
    }

}
