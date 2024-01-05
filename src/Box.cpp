#include "../include/Box.h"

/**
 * @brief Constructor for the Box class.
 *
 * @param position The position index of the box.
 * @param propertyType The type of property associated with the box.
 *
 * @details Initializes a Box object with the specified position and property type.
 */
Box::Box(int position, int propertyType) {
    if (position == 0) {
        type = BoxType::ANGULAR;
        isStart = true;
    } else if (position == 7 || position == 20 || position == 27)
        type = BoxType::ANGULAR;
    else {

        setProperty(propertyType);
    }

}

/**
 * @brief Sets the property details for the box based on its type.
 *
 * @param propertyType The type of property associated with the box.
 */
void Box::setProperty(int pType) {
    free = true;
    type = BoxType::LATERAL;

    switch (pType) {
        case 0:
            propertyType = PropertyType::ECONOMIC;
            price = 6;
            housePrice = 3;
            hotelPrice = 3;
            dailyHousePrice = 2;
            dailyHotelPrice = 4;
            break;
        case 1:
            propertyType = PropertyType::STANDARD;
            price = 10;
            housePrice = 5;
            hotelPrice = 5;
            dailyHousePrice = 4;
            dailyHotelPrice = 8;
            break;
        case 2:
            propertyType = PropertyType::LUXURY;
            price = 20;
            housePrice = 10;
            hotelPrice = 10;
            dailyHousePrice = 7;
            dailyHotelPrice = 14;
            break;
    }
}

/**
 * @brief Sets the box as not free and assigns an owner number.
 *
 * @param playerNumber The player number to assign as the owner.
 */
void Box::setNotFree(int playerNumber) {
    free = false;
    ownerNumber = playerNumber;
}

/**
 * @brief Toggles the identifying character of the box.
 */
void Box::setIdentifying() {
    identifyingBuilding = (identifyingBuilding == '*') ? '^' : '*';
}

/**
 * @brief Getter function to retrieve the identifying character of the box.
 *
 * @return The identifying character of the box.
 */
char Box::getIdentifying() const {
    return identifyingBuilding;
}

/**
 * @brief Getter function to retrieve the type of the box.
 *
 * @return The type of the box (ANGULAR or LATERAL).
 */
BoxType Box::getType() const {
    return type;
}

/**
 * @brief Getter function to retrieve the property type of the box.
 *
 * @return The property type of the box (ECONOMIC, STANDARD, or LUXURY).
 */
PropertyType Box::getPropertyType() const {
    return propertyType;
}

/**
 * @brief Getter function to check if the box represents the starting position.
 *
 * @return True if the box is the starting position, false otherwise.
 */
bool Box::getStart() const {
    return isStart;
}

/**
 * @brief Getter function to check if the box is free (not owned by any player).
 *
 * @return True if the box is free, false if it has an owner.
 */
bool Box::isFree() const {
    return free;
}

/**
 * @brief Getter function to retrieve the price of the box.
 *
 * @return The price of the box.
 */
int Box::getPrice() const {
    return price;
}

/**
 * @brief Getter function to retrieve the price of building a house on the box.
 *
 * @return The price of building a house on the box.
 */
int Box::getHousePrice() const {
    return housePrice;
}

/**
 * @brief Getter function to retrieve the price of building a hotel on the box.
 *
 * @return The price of building a hotel on the box.
 */
int Box::getHotelPrice() const {
    return hotelPrice;
}

/**
 * @brief Getter function to retrieve the daily price of owning a house on the box.
 *
 * @return The daily price of owning a house on the box.
 */
int Box::getDailyHousePrice() const {
    return dailyHousePrice;
}

/**
 * @brief Getter function to retrieve the daily price of owning a hotel on the box.
 *
 * @return The daily price of owning a hotel on the box.
 */
int Box::getDailyHotelPrice() const {
    return dailyHotelPrice;
}

/**
 * @brief Getter function to retrieve the owner number of the box.
 *
 * @return The owner number of the box.
 */
int Box::getOwnerNumber() const {
    return ownerNumber;
}

/**
 * @brief Overloaded stream insertion operator to allow printing Box objects to an ostream.
 *
 * @param os The output stream to which the Box information will be printed.
 * @param obj The Box object to be printed.
 *
 * @return The modified output stream.
 *
 * @details Prints the representation of the box, including its type and identifying character.
 */
std::ostream& operator<<(std::ostream& os, Box& obj) {
    if (obj.getStart())
        os << "|P|";
    else if (static_cast<int>(obj.getType()) == 0)
        os << "| |";
    else {
        os << "|";


        if (obj.getPropertyType() == PropertyType::ECONOMIC)
            os << "E";
        else if (obj.getPropertyType() == PropertyType::STANDARD)
            os << "S";
        else
            os << "L";

        if (obj.getIdentifying() != ' ')
            os << obj.getIdentifying();

        os << "|";

    }

    return os;
}