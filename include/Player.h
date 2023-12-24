//
// Created by Kevin Shefkiu on 23/12/23.
//

#ifndef MONOPOLY_PLAYER_H
#define MONOPOLY_PLAYER_H


class Player {

private:
    double _budget;
public:
    virtual int diceRoll() = 0;
};


#endif //MONOPOLY_PLAYER_H
