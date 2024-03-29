/**
 * Filename: Board.cpp
 * Author: Shefkiu Kevin
 * Created: 05/01/2024
 **/

 #include "../include/Board.h"

/**
 * @brief Default constructor for the Board class.
 *
 * @details Initializes the Board object by creating a sequence of Box objects. The board is populated with a specific distribution of box types based on the indices.
 */
Board::Board() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(std::time(nullptr)));

    // Array to represent the counts of different box types
    int counts[] = {8, 10, 6};

    // Loop to initialize the board with boxes
    for (int i = 0; i < 28; i++) {
        bool isEnd = true;
        do {
            int temp = rand() % 3;
            if (i == 0 || i == 7 || i == 14 || i == 21) {
                // Initialize a Box object with a special type for specific indices
                board.push_back(Box(i, 4, i));
                isEnd = false;
            } else if (counts[temp] > 0) {
                counts[temp]--;
                // Initialize a Box object with a random type
                board.push_back(Box(i, temp, i));
                isEnd = false;
            }
        } while (isEnd);
    }
}

/**
 * @brief Getter function to retrieve the board vector.
 *
 * @return Reference to the vector of Box objects representing the board.
 */
std::vector<Box>& Board::getBoard() {
    return board;
}

/**
 * @brief Getter function that returns the coordinate corresponding to the passed index.
 *
 * @param position
 *
 * @return of coordinates in a form of string to display.
 */
std::string Board::getCoordinates(int position) {
    return coordinates[position];
}

/**
 * @brief Overloaded stream insertion operator to allow printing Board objects to an ostream.
 *
 * @param os The output stream to which the Board information will be printed.
 * @param obj The Board object to be printed.
 *
 * @return The modified output stream.
 *
 * @details Prints the layout of the board to the output stream, including box types.
 */
std::ostream& operator<<(std::ostream& os, Board& obj) {
    std::vector<Box> temp = obj.getBoard();
    char c = 'A';
    os << "\t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\n";

    //helper variables to display the board in a clockwise way
    int j = 19;
    int k = 7;


     //The loop is made to display the array ordered in a clockwise way to help manage the player movement
     //the c++ increases the char variable used to show the letters on the left while printing.

    for (int i = 0; i < 28; i++) {

        if (i == 0 || (i > 7 && i < 15))
            os << c++ << "\t";
        if (i < 8) {
            os << temp[i] << "\t";
            if (i == 7)
                os << "\n";
        } else if(i > 13 && i < 22) {
                os << temp[i + k] << "\t";
                k -= 2;
        } else if (i < 14) {
                os << temp[i + j] << "\t\t\t\t\t\t\t" << temp[i] << "\n";
                j = j - 2;
        }
    }
    os << "\n";

    return os;
}