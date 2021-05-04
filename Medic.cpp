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

    Player& Medic::fly_direct(City c) {
        if (this->cards.count(c)==0) {
            stringstream ss;
            ss << "cannot drive from " << board.cities[this->city].city << " to " << board.cities[c].city;
            throw invalid_argument(ss.str());
        }
        this->city = c;
        this->cards.erase(c);
        if (auto_heal[board.cities[c].color]) {board.cities[c].disease = 0;}
        return *this;
    };

    Player& Medic::fly_charter(City c) {
        if (this->cards.count(this->city)==0) {
            stringstream ss;
            ss << "cannot drive from " << board.cities[this->city].city << " to " << board.cities[c].city;
            throw invalid_argument(ss.str());
        }
        this->city = c;
        this->cards.erase(this->city);
        if (auto_heal[board.cities[c].color]) {board.cities[c].disease = 0;}
        return *this;
    };

    Player& Medic::fly_shuttle(City c) {
        if (!board.cities[this->city].research_station || !board.cities[c].research_station) {
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