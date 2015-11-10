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

wumpus_game::item *wumpus_game::env_tile::get_item(std::string objName) {
    std::map<std::string, item*>::iterator iterator = stuffInRoom.find(objName);
    item* itemPointer = iterator->second;
    stuffInRoom.erase(iterator);
    return itemPointer;
}
