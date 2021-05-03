#include "OperationsExpert.hpp"
#include <iostream>

namespace pandemic {
    Player& OperationsExpert::build() {
        if (!board.cities[this->city].research_station) {
            this->board.research_stations++;
            board.cities[this->city].research_station = true;
        }
        return *this;
    };
}