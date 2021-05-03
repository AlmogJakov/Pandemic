#include "Dispatcher.hpp"
#include <iostream>
#include <sstream>

namespace pandemic {
    Player& Dispatcher::fly_direct(City c) {
        if (!board.cities[this->city].research_station) {
            stringstream ss;
            ss << "cannot drive from " << board.cities[this->city].city << " to " << board.cities[c].city;
            throw invalid_argument(ss.str());
        }
        this->city = c;
        return *this;
    };
}