#include "FieldDoctor.hpp"
#include <iostream>
#include <sstream>

namespace pandemic {
    Player& FieldDoctor::treat(City c) {
        bool found = false;
        if (this->city==c) {found = true;}
        else {for (auto nei : board.cities[this->city].neighbors) {if (nei==c) {found = true;}}}
        if (!found || board[c] == 0) {
            stringstream ss;
            ss << "cannot treat " << board.cities[c].city << " (current city: " << board.cities[city].city << ")";
            throw invalid_argument(ss.str());
        }
        if (board.medicines[board.cities[c].color]) {
            board[c] = 0;
            return *this;
        }
        board[c]--;
        return *this;
    };
}