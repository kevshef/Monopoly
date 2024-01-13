/**
 * Filename: Box.h
 * Author: Garberino Alvise
 * Created: 05/01/2024
 **/

#ifndef MONOPOLY_BOX_H
#define MONOPOLY_BOX_H

#include <iostream>
#include <vector>


// Enum representing different types of properties
enum class PropertyType {
    ECONOMIC = 0, STANDARD, LUXURY
};

// Enum representing different types of boxes on the board
enum class BoxType {
    ANGULAR = 0, LATERAL
};

class Box {

private:

    char identifyingBuilding = ' ';

    void setProperty(int);

    // Type of the box (ANGULAR or LATERAL)
    BoxType type;

    // Type of property on the box (ECONOMIC, STANDARD, LUXURY)
    PropertyType propertyType;

    int ownerNumber;

    bool free = false;

    int price;

    int housePrice;

    int hotelPrice;

    int dailyHousePrice;

    int dailyHotelPrice;

    bool isStart = false;

    std::vector<int> playersPosition;

    std::vector<int> playerIdentifier;

    int boxPosition;

public:

    Box(int, int, int);

    char getIdentifying() const;

    BoxType getType() const;

    PropertyType getPropertyType() const;

    bool getStart() const;

    bool isFree() const;

    int getPrice() const;

    int getHousePrice() const;

    int getHotelPrice() const;

    int getDailyHousePrice() const;

    int getDailyHotelPrice() const;

    void setNotFree(int);

    void setFree();

    int getOwnerNumber() const;

    void setIdentifying();

    std::vector<int> getPlayersPosition() const {return playersPosition; }

    void setPlayersPosition(std::vector<int>, std::vector<int>);

    int getBoxPositionOnBoard() {return boxPosition; }

    std::vector<int> getPlayerIdentifier() {return playerIdentifier;}

};

std::ostream& operator<<(std::ostream&, Box&);

#endif //MONOPOLY_BOX_H