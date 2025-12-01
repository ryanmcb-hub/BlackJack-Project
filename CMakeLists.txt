cmake_minimum_required(VERSION 4.0)
project(BlackJackTest)

set(CMAKE_CXX_STANDARD 20)

add_executable(BlackJackTest main.cpp
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h
        Shoe.cpp
        Shoe.h
        CardGame.cpp
        CardGame.h)
