#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <sstream>

namespace pandemic {
    class FieldDoctor: public Player {
        string Role() {return "FieldDoctor";};
    public:
        FieldDoctor(Board& b, City c): Player(b,c,"FieldDoctor") { }
        ~FieldDoctor() { }
        Player& treat(City c);
    };
}