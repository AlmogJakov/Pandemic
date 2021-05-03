#include "Medic.hpp"
#include <iostream>
#include <sstream>

namespace pandemic {
    Player& Medic::drive(City c) {
        if (board.cities[this->city].neighbors.count(c)==0) {
            stringstream ss;
            ss << "cannot drive from " << board.cities[this->city].city << " to " << board.cities[c].city;
            throw invalid_argument(ss.str());
        }
        this->city = c;
        if (auto_heal[board.cities[c].color]) {board.cities[c].disease = 0;}
        return *this;
    };

    Player& Medic::treat(City c) {
        if (this->city!=c || board.cities[this->city].disease == 0) {
            stringstream ss;
            ss << "cannot treat " << board.cities[c].city;
            throw invalid_argument(ss.str());
        }
        if (board.medicines[board.cities[this->city].color]) {
            auto_heal[board.cities[c].color] = true;
        }
        board.cities[this->city].disease = 0;
        return *this;
    };
}