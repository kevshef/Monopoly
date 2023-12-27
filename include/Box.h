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

    virtual std::string getIdentifying() = 0;

    virtual void setIdentifying(std::string s) = 0;

};


#endif //MONOPOLY_BOX_H
