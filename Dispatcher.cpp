#include "Dispatcher.hpp"
#include <iostream>
#include <sstream>

namespace pandemic {
    Player& Dispatcher::fly_direct(City c) {
        if (this->city == c || (this->cards.count(c)==0&&!board.cities[this->city].research_station)) {
            stringstream ss;
            ss << "cannot fly from " << board.cities[this->city].city << " to " << board.cities[c].city;
            throw invalid_argument(ss.str());
        }
        if (!board.cities[this->city].research_station) {
            this->cards.erase(c);
        }
        this->city = c;
        return *this;
    };
}