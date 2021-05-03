#pragma once
#include <map>
#include <iostream>
#include <set>
using namespace std;

#include "City.hpp"
#include "Color.hpp"

namespace pandemic {
    struct city_struct{
        string city;
        Color color;
        set<City> neighbors;
        int disease = 0;
        bool research_station = false;
        void operator=(const int n) {disease = n;}
        friend ostream& operator<<(ostream& os, const city_struct& s);
    };

    class Board {
        map<City,city_struct> cities;
        int research_stations = 0;
        int medicines_count = 0;
        map<Color,bool> medicines;
        /* Providing access to private variables (board, medicines etc.) for the players */
        /* (players with special skills can not inherit the friendship from Player class in C++) */
        friend class Player;
        friend class Researcher;
        friend class Scientist;
        friend class FieldDoctor;
        friend class GeneSplicer;
        friend class OperationsExpert;
        friend class Dispatcher;
        friend class Medic;
        friend class Virologist;
    public:
        Board();
        ~Board() { }
        city_struct& operator[](City city) {return cities[city];};
        friend ostream& operator<<(ostream& os, const Board& b);
        void remove_cures() {for (auto &cure : medicines) {cure.second = false;}};
        bool is_clean();
        string get_color(Color c);
    };
}