#pragma once
#include <map>
#include <iostream>
#include <list>
using namespace std;

#include "City.hpp"
#include "Color.hpp"

namespace pandemic {
    struct city_struct{
        City city;
        Color color;
        list<City> neighbors;
        int disease;
        void operator=(const int n) {disease = n;}
        friend ostream& operator<<(ostream& os, const city_struct& s) {return os;};
    };

    class Board {
    public:
        map<City,city_struct> board;
        Board();
        ~Board() { }
        city_struct& operator[](City city) {return board[city];};
        friend ostream& operator<<(ostream& os, const Board& b) {return os;};
        bool is_clean() {return false;};
    };
}