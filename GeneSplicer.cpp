#include "GeneSplicer.hpp"
#include <iostream>
#include <sstream>

const int five_cards = 5;

namespace pandemic {
    Player& GeneSplicer::discover_cure(Color c) {
        if (!board.cities[this->city].research_station || this->cards.size()<five_cards) {
            stringstream ss;
            ss << "cannot discover_cure in " << board.cities[this->city].city;
            throw invalid_argument(ss.str());
        }
        if (board.medicines[c]) {return *this;}
        int counter = 0;
        for (auto city = this->cards.begin(); city != this->cards.end(); ) {
            city = this->cards.erase(city);
            counter++;
            ++city;
            if (counter>=five_cards) {break;}
        }
        board.medicines[c] = true;
        return *this;
    };
}