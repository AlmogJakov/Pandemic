#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <sstream>

namespace pandemic {
    class OperationsExpert: public Player {
        string Role() {return "OperationsExpert";};
    public:
        OperationsExpert(Board& b, City c): Player(b,c,"OperationsExpert") { }
        ~OperationsExpert() { }
        Player& build();
    };
}