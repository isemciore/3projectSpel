//
// Created by erik on 2015-11-06.
//

#ifndef INC_3PROJECTSPEL_SAVEALOAD_H
#define INC_3PROJECTSPEL_SAVEALOAD_H

#include <string>

namespace wumpus_game {
    class saveAload {
    private:
        bool isSave;
    public:
        saveAload();//New saveFile
        saveAload(std::string dir); //savefileLoc/name


        bool isSaveFile(){ return isSave;}
    };
}

#endif //INC_3PROJECTSPEL_SAVEALOAD_H
