#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic {
    class Scientist: public Player {
        string Role() {return "Scientist";};
        int n_cards;
    public:
        Scientist(Board& b, City c, int n): Player(b,c) {
            n_cards = n;
        }
        ~Scientist() { }
        Player& discover_cure(Color c);
    };
}