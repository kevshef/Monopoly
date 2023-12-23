//
// Created by Alvise Garberino on 23/12/23.
//

#ifndef MONOPOLY_CASELLA_H
#define MONOPOLY_CASELLA_H


class Casella {

private:

    bool casa;

    bool hotel;

public:

    void setCasa() { casa = true; }

    void setHotel() { if (casa) { casa = false; hotel = true; } }

    bool getCasa() { return casa; }

    bool getHotel() { return hotel; }

protected:

};


#endif //MONOPOLY_CASELLA_H
