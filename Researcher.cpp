#include "Researcher.hpp"
#include <iostream>
#include <sstream>

const int five_cards = 5;

namespace pandemic {
    Player& Researcher::discover_cure(Color c) {
        int colors = 0;
        for (auto city : this->cards) {
            if (board.cities[city].color==c) {colors++;}
            if (colors>=five_cards) {break;}
        }
        if (colors<five_cards) {
            stringstream ss;
            ss << "cannot discover_cure in " << board(this->city).city;
            throw invalid_argument(ss.str());
        }
        if (board.medicines[c]) {return *this;}
        colors = 0;
        for (auto city = this->cards.begin(); city != this->cards.end(); ) {
            if (board.cities[*city].color==c) {
                city = this->cards.erase(city);
                colors++;
            } else {++city;}
            if (colors>=five_cards) {break;}
        }
        board.medicines[c] = true;
        return *this;
    };
}