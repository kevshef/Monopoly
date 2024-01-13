cmake_minimum_required(VERSION 3.22.1)
project(Monopoly)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")


add_executable(Monopoly
        src/main.cpp
        src/Board.cpp
        src/Box.cpp
        src/Player.cpp
        src/BankAccount.cpp
        src/ComputerPlayer.cpp
        src/HumanPlayer.cpp
        src/Game.cpp)

target_include_directories(Monopoly PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
