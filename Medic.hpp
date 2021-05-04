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
        }
        ~Medic() { }
        Player& drive(City c);
        Player& fly_direct(City c);
        Player& fly_charter(City c);
        Player& fly_shuttle(City c);
        Player& treat(City c);
    };
}