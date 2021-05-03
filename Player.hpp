#pragma once
#include <iostream>
#include <set>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

namespace pandemic {
    class Player {
    protected:
        virtual string Role() {return "Player";};
        pandemic::Board& board;
        City city;
        set<City> cards = { };
        /* Providing access to private variables (board, cards etc.) for special skills players */
        /* (special skills players can not inherit board class friendship from player class in C++) */
    public:
        Player(Board& b, City c): board(b) {
            board = b;
            city = c;
        }
        ~Player() { }
        virtual Player& drive(City c);
        virtual Player& fly_direct(City c);
        virtual Player& fly_charter(City c);
        virtual Player& fly_shuttle(City c);
        virtual Player& build();
        virtual Player& discover_cure(Color c);
        virtual Player& treat(City c);
        string role();
        Player& take_card(City c);
    };
}