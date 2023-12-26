//
// Created by Kevin Shefkiu on 26/12/23.
//

#ifndef MONOPOLY_BOX_H
#define MONOPOLY_BOX_H

enum class BoxType {
    economic = 0, standard, luxury
};

class Box {

protected:

    char identifying_character;

public:

    char getIdentifyingCharacter() { return identifying_character; }
};


#endif //MONOPOLY_BOX_H
