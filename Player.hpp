#pragma once
#include <iostream>
#include <set>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

namespace pandemic {
    class Player {
    protected:
        pandemic::Board& board;
        string my_role;
        City city;
        set<City> cards = { };
    public:
        Player(Board& b, City c, string r): board(b), city(c), my_role(r) { }
        ~Player() { }
        virtual Player& drive(City c);
        virtual Player& fly_direct(City c);
        virtual Player& fly_charter(City c);
        virtual Player& fly_shuttle(City c);
        virtual Player& build();
        virtual Player& discover_cure(Color c);
        virtual Player& treat(City c);
        string role() {return my_role;}
        Player& take_card(City c);
    };
}