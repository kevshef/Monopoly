#ifndef MONOPOLY_BOX_H
#define MONOPOLY_BOX_H

#include <iostream>

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
    void setProperty(PropertyType propertyType);

    BoxType type; // Type of the box (ANGULAR or LATERAL)

    PropertyType propertyType; // Type of property on the box (ECONOMIC, STANDARD, LUXURY)

    int ownerNumber = -1; // Player number who owns the box

    bool free = false; // Indicates whether the box is free or owned by a player

    int price; // Price of the property on the box

    int housePrice; // Price to build a house on the property

    int hotelPrice; // Price to upgrade to a hotel on the property

    int dailyHousePrice; // Daily cost for owning a house on the property

    int dailyHotelPrice; // Daily cost for owning a hotel on the property

    bool isStart = false; // Indicates whether the box is a starting point

public:

    // Constructor: Initializes the box based on its position and property type
    Box(int position, int propertyType);

    // Getter function to retrieve the identifying character of the box
    char getIdentifying() const;

    // Getter function to retrieve the type of the box (ANGULAR or LATERAL)
    BoxType getType() const;

    // Getter function to retrieve the property type of the box (ECONOMIC, STANDARD, LUXURY)
    PropertyType getPropertyType() const;

    // Getter function to check if the box is a starting point
    bool getStart() const;

    // Getter function to check if the box is free
    bool isFree() const;

    // Getter function to retrieve the price of the property on the box
    int getPrice() const;

    // Getter function to retrieve the price to build a house on the property
    int getHousePrice() const;

    // Getter function to retrieve the price to upgrade to a hotel on the property
    int getHotelPrice() const;

    // Getter function to retrieve the daily cost for owning a house on the property
    int getDailyHousePrice() const;

    // Getter function to retrieve the daily cost for owning a hotel on the property
    int getDailyHotelPrice() const;

    // Function to set the box as not free and assign an owner
    void setNotFree(int playerNumber);

    // Getter function to retrieve the owner number of the box
    int getOwnerNumber() const;

    // Function to toggle the identifying character of the box
    void setIdentifying();

};

// Overloaded stream insertion operator to allow printing Box objects to an ostream
std::ostream& operator<<(std::ostream& os, Box& obj);

#endif //MONOPOLY_BOX_H