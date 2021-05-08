#include "Virologist.hpp"
#include <iostream>
#include <sstream>

namespace pandemic {
    Virologist& Virologist::treat(City c) {
        if (board[c] == 0 || (this->city!=c && this->cards.count(c)==0)) {
            stringstream ss;
            ss << "cannot treat " << board.cities[c].city;
            throw invalid_argument(ss.str());
        }
        if (this->city!=c) {
            this->cards.erase(c);
        }
        if (board.medicines[board.cities[c].color]) {board[c] = 0;}
        else {board[c]--;}
        return *this;
    };
}