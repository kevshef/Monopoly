//
// Created by Kevin Shefkiu on 26/12/23.
//

#ifndef MONOPOLY_BOX_H
#define MONOPOLY_BOX_H

#include <iostream>

enum class ProprietyType {
    economic = 0, standard, luxury
};

enum class BoxType {
    angular = 0, lateral
};

class Box {

protected:

    char identifying_building;

    BoxType type;

    bool isStart = false;

public:

    Box(int position);

    char getIdentifying() const { return identifying_building; }

    void setIdentifying(char c) { identifying_building = c; }

    BoxType getType() const { return type; }

    bool getStart() const { return isStart; }

};

std::ostream& operator<<(std::ostream& os, Box& obj);

#endif //MONOPOLY_BOX_H
