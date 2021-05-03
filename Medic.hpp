#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic {
    class Medic: public Player {
        string Role() {return "Medic";};
        map<Color,bool> auto_heal;
    public:
        Medic(Board& b, City c): Player(b,c) {
            auto_heal = {
                {Color::Blue,b.medicines.count(Color::Blue)},
                {Color::Yellow,b.medicines.count(Color::Yellow)},
                {Color::Black,b.medicines.count(Color::Black)},
                {Color::Red,b.medicines.count(Color::Red)}
            };
            if (b.medicines.count(b[c].color)) {b[c].disease = 0;}
        }
        ~Medic() { }
        Player& drive(City c);
        Player& treat(City c);
    };
}