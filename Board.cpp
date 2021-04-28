#include "Board.hpp"
#include <iostream>

#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <list>

namespace pandemic {
    Board::Board() {
        board[City::Algiers] = (city_struct){City::Algiers,Color::Black,{City::Madrid, City::Paris, City::Istanbul, City::Cairo}};
    }
}