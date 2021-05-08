#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic {
    class GeneSplicer: public Player {
        string Role() {return "GeneSplicer";};
    public:
        GeneSplicer(Board& b, City c): Player(b,c,"GeneSplicer") {}
        ~GeneSplicer() { }
        Player& discover_cure(Color c);
    };
}