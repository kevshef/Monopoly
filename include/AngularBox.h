//
// Created by Kevin Shefkiu on 22/12/23.
//

#ifndef MONOPOLY_ANGULARBOX_H
#define MONOPOLY_ANGULARBOX_H

#include "../include/Box.h"

class AngularBox : public Casella {

public:

    bool start;

private:

    AngularBox(bool start);

    bool isStart() { return start; }

};

#endif //MONOPOLY_ANGULARBOX_H
