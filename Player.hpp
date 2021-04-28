#pragma once
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

namespace pandemic {
    class Player {
        pandemic::Board board;
        City city;
    public:
        Player(Board b, City c) {
            board = b;
            city = c;
        }
        ~Player() { }
        virtual Player& drive(City c) {return *this;};
        virtual Player& fly_direct(City c) {return *this;};
        virtual Player& fly_charter(City c) {return *this;};
        virtual Player& fly_shuttle(City c) {return *this;};
        virtual Player& build() {return *this;};
        virtual Player& discover_cure(Color c) {return *this;};
        virtual Player& treat(City c) {return *this;};
        string role() {return "";};
        Player& take_card(City c) {return *this;};
    };
}