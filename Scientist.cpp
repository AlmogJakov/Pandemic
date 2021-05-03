#include "Scientist.hpp"
#include <iostream>
#include <sstream>

namespace pandemic {
    Player& Scientist::discover_cure(Color c) {
        int colors = 0;
        for (auto city : this->cards) {
            if (board.cities[city].color==c) {colors++;}
            if (colors>=n_cards) {break;}
        }
        if (!board.cities[this->city].research_station || colors<n_cards) {
            stringstream ss;
            ss << "cannot discover_cure in " << board.cities[this->city].city;
            throw invalid_argument(ss.str());
        }
        if (board.medicines[c]) {return *this;}
        colors = 0;
        for (auto city = this->cards.begin(); city != this->cards.end(); ) {
            if (board.cities[*city].color==c) {
                city = this->cards.erase(city);
                colors++;
            } else {++city;}
            if (colors>=n_cards) {break;}
        }
        board.medicines[c] = true;
        return *this;
    };
}