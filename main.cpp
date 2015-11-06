#include <iostream>
#include "saveAload.h"
#include "game_Master.h"
#include <stdlib.h>

int main() {
    srand(10);
    std::string exitCond = "derp";
    bool notExit = true;
    while(notExit) {
        wumpus_game::saveAload saveFile;//INISTREAM TO SAVEFILE
        wumpus_game::game_Master currentGame(exitCond,saveFile);


        break;
    }
    return 0;
}