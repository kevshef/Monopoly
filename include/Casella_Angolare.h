//
// Created by Alvise Garberino on 23/12/23.
//

#ifndef MONOPOLY_CASELLA_ANGOLARE_H
#define MONOPOLY_CASELLA_ANGOLARE_H

#include "../include/Casella.h"

class Casella_Angolare : public Casella {

public:

    bool start;

private:

    bool isStart() { return start; }

};

#endif //MONOPOLY_CASELLA_ANGOLARE_H
