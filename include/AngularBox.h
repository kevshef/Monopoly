//
// Created by
//

#ifndef MONOPOLY_ANGULARBOX_H
#define MONOPOLY_ANGULARBOX_H

#include "../include/Box.h"

class AngularBox : public Box {

public:

    bool start;

    AngularBox(bool b);

    virtual std::string getIdentifying() { return identifying; }

    virtual void setIdentifying(std::string s) { identifying = s; }

};


#endif //MONOPOLY_ANGULARBOX_H
