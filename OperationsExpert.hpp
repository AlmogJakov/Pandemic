#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic {
    class OperationsExpert: public Player {
    public:
        OperationsExpert(Board b, City c): Player(b,c) {}
        ~OperationsExpert() { }
        Player& build() {return *this;};
    };
}