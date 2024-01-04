#include "../include/Board.h"

/**
 * @brief Default constructor for the Board class.
 *
 * @details Initializes the Board object by creating a sequence of Box objects.
 * The board is populated with a specific distribution of box types based on the indices.
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
            if (i == 0 || i == 7 || i == 20 || i == 27) {
                // Initialize a Box object with a special type for specific indices
                board.push_back(Box(i, 4));
                isEnd = false;
            } else if (counts[temp] > 0) {
                counts[temp]--;
                // Initialize a Box object with a random type
                board.push_back(Box(i, temp));
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
 * @brief Setter function to set the board with a given vector of boxes.
 *
 * @param boxes The vector of Box objects to set the board with.
 */
void Board::setBoard(const std::vector<Box>& boxes) {
    board = boxes;
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

    for( int i = 0; i < 28; i++ ) {
        if( i == 0 || (i > 7 && i % 2 == 0) && i < 21)
            os << c++ << "\t";

        if (i < 8 || i > 19) {
            os << temp[i] << "\t";

            if (i == 7)
                os << "\n";

        } else {
            os << temp[i] << "\t\t\t\t\t\t\t" << temp[i + 1] << "\n";
            i++;
        }
      
        if(i == 27)
            os << "\n";

    }
    os << "\n";

    return os;

}
