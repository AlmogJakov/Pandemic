#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic {
    class Researcher: public Player {
        string Role() {return "Researcher";};
    public:
        Researcher(Board& b, City c): Player(b,c) {}
        ~Researcher() { }
        Player& discover_cure(Color c);
    };
}