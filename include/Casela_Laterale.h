//
// Created by Alvise Garberino on 23/12/23.
//

#ifndef MONOPOLY_CASELA_LATERALE_H
#define MONOPOLY_CASELA_LATERALE_H

enum class Tipologia {
    economic = 0, standard, luxury;
}

class Casella_Laterale : public Casella {

private:
    int type;


public:
    void setType(Tipologia n);

    int getType() { return type; }

};

#endif //MONOPOLY_CASELA_LATERALE_H
