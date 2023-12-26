//
// Created by Kevin Shefkiu on 26/12/23.
//

#ifndef MONOPOLY_BOX_H
#define MONOPOLY_BOX_H

#include <string>

enum class BoxType {
    economic = 0, standard, luxury
};

class Box {

protected:

    std::string identifying;

public:

    std::string getIdentifying() { return identifying; }

    void setIdentifying(std::string s) { identifying = s; }

};


#endif //MONOPOLY_BOX_H
