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

// Class representing a box on the game board
class Box {

private:

    char identifyingBuilding = ' '; // Character to identify special building types

    // Private function to set the property of the box based on PropertyType
    void setProperty(int pType);

    BoxType type; // Type of the box (ANGULAR or LATERAL)

    PropertyType propertyType; // Type of property on the box (ECONOMIC, STANDARD, LUXURY)

    int ownerNumber; // Player number who owns the box

    bool free = false; // Indicates whether the box is free or owned by a player

    int price; // Price of the property on the box

    int housePrice; // Price to build a house on the property

    int hotelPrice; // Price to upgrade to a hotel on the property

    int dailyHousePrice; // Daily cost for owning a house on the property

    int dailyHotelPrice; // Daily cost for owning a hotel on the property

    bool isStart = false; // Indicates whether the box is a starting point

    std::vector<int> playersPosition;

    std::vector<int> playerIdentifier;

    int boxPosition;

public:

    Box(int position, int propertyType, int boxPosition);

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

    void setNotFree(int playerNumber);

    void setFree();

    int getOwnerNumber() const;

    void setIdentifying();

    std::vector<int> getPlayersPosition() const {return playersPosition; }

    void setPlayersPosition(std::vector<int> playersPosition, std::vector<int> playerIdentifier);

    int getBoxPositionOnBoard() {return boxPosition; }

    std::vector<int> getPlayerIdentifier() {return playerIdentifier;}

};

// Overloaded stream insertion operator to allow printing Box objects to an ostream
std::ostream& operator<<(std::ostream& os, Box& obj);

#endif //MONOPOLY_BOX_H