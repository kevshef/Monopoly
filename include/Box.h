//
// Created by Kevin Shefkiu on 26/12/23.
//

#ifndef MONOPOLY_BOX_H
#define MONOPOLY_BOX_H

class Box {

protected:

    char identifying_building;

public:

    virtual char getIdentifying() = 0;

    virtual void setIdentifying(char c) = 0;

};

#endif //MONOPOLY_BOX_H
