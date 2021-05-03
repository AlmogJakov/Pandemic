#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic {
    class Virologist: public Player {
        string Role() {return "Virologist";};
    public:
        Virologist(Board& b, City c): Player(b,c) {}
        ~Virologist() { }
        Virologist& treat(City c);
    };
}