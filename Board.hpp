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
        bool research_station = false;
    };

    class Board {
    public:
        /* key: city enum. value: city name as string, city color, city neighbors  */
        map<City,city_struct> cities;
        /* key: city enum. value: city disease number  */
        map<City,int> diseases;
        /* key: c/city color. value: boolean (true: medicin found)  */
        map<Color,bool> medicines;
        int research_stations = 0;
        int medicines_count = 0;
        /* constructor/destructor */
        Board();
        ~Board() { }
        /* [] operator for getting disease integer reference */
        int& operator[](City city) {
            if (this->diseases[city]==0) {this->diseases[city] = 0;}
            return this->diseases[city];
        };
        /* () operator for getting city struct */
        city_struct& operator()(City city) {return cities.at(city);};
        /* << board output operator */
        friend ostream& operator<<(ostream& os, Board& b);
        /* removing all cures */
        void remove_cures() {for (auto &cure : medicines) {cure.second = false;}};
        /* returning boolean (true: no disease at all) */
        bool is_clean();
        /* getting any color enum as string */
        string get_color(Color c);
    };
}