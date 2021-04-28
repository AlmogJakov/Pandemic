/**
 * AUTHORS: AlmogJakov
 * 
 * Date: 2021-04
 */

#include "doctest.h"

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <iostream>
#include <stdexcept>
using namespace std;


TEST_CASE("just a test") {
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
	board[City::Kinshasa] = 3;      // put 3 yellow disease cubes in Kinshasa.
	board[City::Kinshasa] = 2;      // change number of disease cubes in Kinshasa to 2.
	board[City::MexicoCity] = 3;    // put 3 yellow disease cubes in MexicoCity
	board[City::HoChiMinhCity] = 1; // put 1 red disease cube in HoChiMinhCity
	board[City::Chicago] = 1;       // put 1 blue disease cube in Chicago

	OperationsExpert player {board, City::Atlanta};  // initialize an "operations expert" player on the given board, in Atlanta.
	player.take_card(City::Johannesburg)
	 .take_card(City::Khartoum)
	 .take_card(City::SaoPaulo)
	 .take_card(City::BuenosAires)
	 .take_card(City::HoChiMinhCity);
}