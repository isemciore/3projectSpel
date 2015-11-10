//
// Created by erik on 2015-11-05.
//

#include "player_ctrl.h"
#include "vector"
wumpus_game::player_ctrl::~player_ctrl() {

}


bool wumpus_game::player_ctrl::performAction() {
    return false;
}

bool wumpus_game::player_ctrl::takeDamage(int i) {
    return false;
}

int wumpus_game::player_ctrl::attackDamage() {
    return 0;
}

bool wumpus_game::player_ctrl::hasItem(std::string itemName) {
    if (rightHand->get_name() == itemName || leftHand->get_name()==itemName || googles->get_name()==itemName){
        return true;
    }
    return back->containItem(itemName);
}

bool wumpus_game::player_ctrl::addItem(wumpus_game::item *itemPtr, std::string location) {
    if (rightHand== nullptr){
        rightHand = itemPtr;
        std::cout << "picking up item "<<itemPtr->get_name()<<" with right hand";
        return true;
    }
    return false;
}

wumpus_game::item *wumpus_game::player_ctrl::get_item(std::string itemName) {
    /*item* rightHand;
    item* leftHand;
    item* googles;
    container* back;*/
    if (rightHand->get_name() == itemName){
        item* itemP = rightHand;
        rightHand = nullptr;
        return itemP;
    }
    if (leftHand->get_name() == itemName){
        item* itemP = leftHand;
        leftHand = nullptr;
        return itemP;
    }
    if (googles->get_name() == itemName){
        std::cout << "You cannot remove your googles\n";
        return nullptr;
    }
    return back->getFromBP(itemName);
}

bool wumpus_game::player_ctrl::moveItem(std::vector<std::string> vStringcmd) {
    //make sure target item have req.
    if (vStringcmd[3] == "right"){
        if (rightHand == nullptr){
            return false;
        }
    } else if (vStringcmd[3] == "left"){
        if (leftHand == nullptr){
            return false;
        }
    } else if (vStringcmd[3] == "backpack"){
        if (back == nullptr){
            return false;
        }
    } else{ return false;} //ctarget does not exist

    item* itemPtr = get_item(vStringcmd[0]);
    if (itemPtr== nullptr){
        std::cout << "dont have the item \n";
        return false;
    }

    if (vStringcmd[3] == "right"){
        rightHand  = itemPtr;
    } else if (vStringcmd[3] == "left"){
        leftHand   = itemPtr;
    } else if (vStringcmd[3] == "backpack"){
        back->add(itemPtr);
    }
    return true;
}
