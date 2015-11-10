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


bool wumpus_game::env_tile::move_it_to_char(std::shared_ptr<wumpus_game::unit> srcPtr, std::vector<std::string> strVector) {
    //vector[0];//Pick $item with $right/left hand
    std::map<std::string, item*>::iterator itemIterator = stuffInRoom.find(strVector[0]);
    if (itemIterator!= stuffInRoom.end()){
        item* itemPointer = itemIterator->second;
        bool puSuccess = srcPtr->addItem(itemPointer,strVector[2]);
        if(puSuccess){
            stuffInRoom.erase(itemIterator);
            return true;
        }
    }

    return false;
}

bool wumpus_game::env_tile::move_it_to_tile(std::shared_ptr<wumpus_game::unit> ptr, std::vector<std::string> vector) {
    item* itemPtr = ptr->get_item(vector[0]);
    if (itemPtr == nullptr){
        return false;
    }
    else{
        stuffInRoom.insert(std::make_pair(itemPtr->get_name(),itemPtr));
        return true;
    }
}
