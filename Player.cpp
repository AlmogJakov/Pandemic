#include "Player.hpp"
#include <iostream>
#include <sstream>

const int five_cards = 5;

namespace pandemic {
    Player& Player::drive(City c) {
        if (this->city==c || board.cities[this->city].neighbors.count(c)==0) {
            stringstream ss;
            ss << "cannot drive from " << board.cities[this->city].city << " to " << board.cities[c].city;
            throw invalid_argument(ss.str());
        }
        this->city = c;
        return *this;
    };

    Player& Player::fly_direct(City c) {
        if (this->city == c || this->cards.count(c)==0) {
            stringstream ss;
            ss << "cannot drive from " << board.cities[this->city].city << " to " << board.cities[c].city;
            throw invalid_argument(ss.str());
        }
        
        this->city = c;
        this->cards.erase(c);
        return *this;
    };

    Player& Player::fly_charter(City c) {
        if (this->city == c || this->cards.count(this->city)==0) {
            stringstream ss;
            ss << "cannot drive from " << board.cities[this->city].city << " to " << board.cities[c].city;
            throw invalid_argument(ss.str());
        }
        this->cards.erase(this->city);
        this->city = c;
        return *this;
    };

    Player& Player::fly_shuttle(City c) {
        if (this->city == c || !board.cities[this->city].research_station || !board.cities[c].research_station) {
            stringstream ss;
            ss << "cannot drive from " << board.cities[this->city].city << " to " << board.cities[c].city;
            throw invalid_argument(ss.str());
        }
        this->city = c;
        return *this;
    };

    Player& Player::build() {
        if (board.cities[this->city].research_station) {
            return *this;
        }
        if (this->cards.count(this->city)==0) {
            stringstream ss;
            ss << "cannot build research station to " << board.cities[this->city].city;
            throw invalid_argument(ss.str());
        }
        if (!board.cities[this->city].research_station) {
            this->cards.erase(this->city);
            this->board.research_stations++;
            board.cities[this->city].research_station = true;
        }
        return *this;
    };

    Player& Player::discover_cure(Color c) {
        int colors = 0;
        for (auto city : this->cards) {
            if (board.cities[city].color==c) {colors++;}
            if (colors>=five_cards) {break;}
        }
        if (!board.cities[this->city].research_station || colors<five_cards) {
            stringstream ss;
            ss << "cannot discover_cure for " << board.cities[this->city].city;
            throw invalid_argument(ss.str());
            return *this;
        }
        if (board.medicines[c]) {return *this;}
        colors = 0;
        /* TODO: implement in such a way that each scenario has an unambiguous result (for the purpose of the tests) */
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

    Player& Player::treat(City c) {
        if (this->city!=c || board[this->city] == 0) {
            stringstream ss;
            ss << "cannot treat " << board.cities[c].city;
            throw invalid_argument(ss.str());
        }
        if (board.medicines[board.cities[this->city].color]) {
            board[this->city] = 0;
            return *this;
        }
        board[this->city]--;
        return *this;
    };

    Player& Player::take_card(City c) {
        this->cards.insert(c);
        return *this;
    };
}