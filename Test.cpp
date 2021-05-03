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
#include <map>
#include <set>

using namespace std;

struct city_s {
    string city;
    Color color;
    set<City> neighbors;
};
map<City,city_s> cities;
set<City> research_stations_cities;
void init() {
	/* init cities map */
	cities = {
		{City::Algiers,(city_s){"Algiers",Color::Black,{City::Madrid, City::Paris, City::Istanbul, City::Cairo}}},
        {City::Atlanta,(city_s){"Atlanta",Color::Blue,{City::Chicago, City::Miami, City::Washington}}},
        {City::Baghdad,(city_s){"Baghdad",Color::Black,{City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi}}},
        {City::Bangkok,(city_s){"Bangkok",Color::Red,{City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}}},
        {City::Beijing,(city_s){"Beijing",Color::Red,{City::Shanghai, City::Seoul}}},
        {City::Bogota,(city_s){"Bogota",Color::Yellow,{City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}}},
        {City::BuenosAires,(city_s){"BuenosAires",Color::Yellow,{City::Bogota, City::SaoPaulo}}},
        {City::Cairo,(city_s){"Cairo",Color::Black,{City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}}},
        {City::Chennai,(city_s){"Chennai",Color::Black,{City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}}},
        {City::Chicago,(city_s){"Chicago",Color::Blue,{City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}}},
        {City::Delhi,(city_s){"Delhi",Color::Black,{City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata}}},
        {City::Essen,(city_s){"Essen",Color::Blue,{City::London, City::Paris, City::Milan, City::StPetersburg}}},
        {City::HoChiMinhCity,(city_s){"HoChiMinhCity",Color::Red,{City::Jakarta, City::Bangkok, City::HongKong, City::Manila}}},
        {City::HongKong,(city_s){"HongKong",Color::Red,{City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}}},
        {City::Istanbul,(city_s){"Istanbul",Color::Black,{City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}}},
        {City::Jakarta,(city_s){"Jakarta",Color::Red,{City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}}},
        {City::Johannesburg,(city_s){"Johannesburg",Color::Yellow,{City::Kinshasa, City::Khartoum}}},
        {City::Karachi,(city_s){"Karachi",Color::Black,{City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi}}},
        {City::Khartoum,(city_s){"Khartoum",Color::Yellow,{City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}}},
        {City::Kinshasa,(city_s){"Kinshasa",Color::Yellow,{City::Lagos, City::Khartoum, City::Johannesburg}}},
        {City::Kolkata,(city_s){"Kolkata",Color::Black,{City::Delhi, City::Chennai, City::Bangkok, City::HongKong}}},
        {City::Lagos,(city_s){"Lagos",Color::Yellow,{City::SaoPaulo, City::Khartoum, City::Kinshasa}}},
        {City::Lima,(city_s){"Lima",Color::Yellow,{City::MexicoCity, City::Bogota, City::Santiago}}},
        {City::London,(city_s){"London",Color::Blue,{City::NewYork, City::Madrid, City::Essen, City::Paris}}},
        {City::LosAngeles,(city_s){"LosAngeles",Color::Yellow,{City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney}}},
        {City::Madrid,(city_s){"Madrid",Color::Blue,{City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers}}},
        {City::Manila,(city_s){"Manila",Color::Red,{City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney}}},
        {City::MexicoCity,(city_s){"MexicoCity",Color::Yellow,{City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota}}},
        {City::Miami,(city_s){"Miami",Color::Yellow,{City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}}},
        {City::Milan,(city_s){"Milan",Color::Blue,{City::Essen, City::Paris, City::Istanbul}}},
        {City::Montreal,(city_s){"Montreal",Color::Blue,{City::Chicago, City::Washington, City::NewYork}}},
        {City::Moscow,(city_s){"Moscow",Color::Black,{City::StPetersburg, City::Istanbul, City::Tehran}}},
        {City::Mumbai,(city_s){"Mumbai",Color::Black,{City::Karachi, City::Delhi, City::Chennai}}},
        {City::NewYork,(city_s){"NewYork",Color::Blue,{City::Montreal, City::Washington, City::London, City::Madrid}}},
        {City::Osaka,(city_s){"Osaka",Color::Red,{City::Taipei, City::Tokyo}}},
        {City::Paris,(city_s){"Paris",Color::Blue,{City::Algiers, City::Essen, City::Madrid, City::Milan, City::London}}},
        {City::Riyadh,(city_s){"Riyadh",Color::Black,{City::Baghdad, City::Cairo, City::Karachi}}},
        {City::SanFrancisco,(city_s){"SanFrancisco",Color::Blue,{City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}}},
        {City::Santiago,(city_s){"Santiago",Color::Yellow,{City::Lima}}},
        {City::SaoPaulo,(city_s){"SaoPaulo",Color::Yellow,{City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}}},
        {City::Seoul,(city_s){"Seoul",Color::Red,{City::Beijing, City::Shanghai, City::Tokyo}}},
        {City::Shanghai,(city_s){"Shanghai",Color::Red,{City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}}},
        {City::StPetersburg,(city_s){"StPetersburg",Color::Blue,{City::Essen, City::Istanbul, City::Moscow}}},
        {City::Sydney,(city_s){"Sydney",Color::Red,{City::Jakarta, City::Manila, City::LosAngeles}}},
        {City::Taipei,(city_s){"Taipei",Color::Red,{City::Shanghai, City::HongKong, City::Osaka, City::Manila}}},
        {City::Tehran,(city_s){"Tehran",Color::Black,{City::Baghdad, City::Moscow, City::Karachi, City::Delhi}}},
        {City::Tokyo,(city_s){"Tokyo",Color::Red,{City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}}},
		{City::Washington,(city_s){"Washington",Color::Blue,{City::Atlanta, City::NewYork, City::Montreal, City::Miami}}}
	};
	/* choose random 16 cities to be with research stations */
	while (research_stations_cities.size()<16) {
		auto it = cities.begin();
		std::advance(it, (uint)rand() % cities.size());
		research_stations_cities.insert(it->first);
    };
}

/* return new player according to the input ('n' variable used only for Scientist constructor) */
Player get_new_player(Board& board, City city, string role, int n = 4) {
	if (role == "Researcher") return Researcher{board,city};
	if (role == "Scientist") return Scientist{board,city,n};
	if (role == "FieldDoctor") return FieldDoctor{board,city};
	if (role == "GeneSplicer") return GeneSplicer{board,city};
	if (role == "OperationsExpert") return OperationsExpert{board,city};
	if (role == "Dispatcher") return Dispatcher{board,city};
	if (role == "Medic") return Medic{board,city};
	if (role == "Virologist") return Virologist{board,city};
	return Player{board,city};
}

/* for the purpose of discovering a cure for a city */
Researcher five_cards_researcher(Board& board, City city) {
	Researcher researcher(board, city);
	Color color = cities[city].color;
	int counter = 0;
	for (auto &c : cities) {
		if (c.second.color==color) counter++;
		researcher.take_card(c.first);
		if (counter==5) break;
	}
	return researcher;
}

//////////////////////////////////////////////////////////////////////////
///////////////////////////// Tests Methods //////////////////////////////
//////////////////////////////////////////////////////////////////////////

/* ---------------------------- Drive Test ---------------------------- */
void drive_test(Player& player, Board& board) {
	/* Medic Action (checks auto heal) */
	if (player.role()=="Medic") {
		Board b;
		Medic medic{b, City::Algiers};
		set<Color> auto_heal_cities;
		for (auto &city : cities) {
			/* choose 2 random medications (out of the 4) */
			if (auto_heal_cities.size()<2&&auto_heal_cities.count(b[city.first].color)==0) {
				auto_heal_cities.insert(b[city.first].color);
				Researcher researcher = five_cards_researcher(board, city.first);
				researcher.discover_cure(city.second.color);
			}
			/* choose a random disease level from 1 to 9 to any city */
			b[city.first] = (rand() % 9) + 1;
		}
		for (auto &city : cities) {
			/* travel to any city */
			Medic same_role_player(b, city.first);
			/* If the disease in the current city has been treated */
			if (auto_heal_cities.count(b[city.first].color)) {
				Player p{b, city.first};
				/* should throw an error (presence of the medic already set the disease to 0) */
				CHECK_THROWS(p.treat(city.first));
			}
		}
	}
	/* Any-Player-Role Action */
	for (auto &city : cities) {
		/* attempt to travel to a non-neighboring city */
		for (auto &far_city : cities) {
			if (city.first!=far_city.first&&city.second.neighbors.count(far_city.first)==0) {
				Player same_role_player = get_new_player(board, city.first, player.role());
				same_role_player.take_card(far_city.first);
				/* should throw an error (non-neighboring cities) */
				CHECK_THROWS(same_role_player.drive(far_city.first));
			}
	    }
		/* attempt to travel to a neighboring city */
		for (auto &neighbor : city.second.neighbors) {
			Player same_role_player = get_new_player(board, city.first, player.role());
			/* should not throw an error (iteration of the neighbors) */
			CHECK_NOTHROW(same_role_player.drive(neighbor));
	    }
	}
}

/* --------------------------- Fly Direct Test --------------------------- */
/* should run build_test before this test (to build research stations) */
/* Dispatcher Action */
void fly_direct_test(Player& player, Board& board) {
	for (auto &city : cities) {
		for (auto &other_city : cities) {
			Dispatcher same_role_player(board, city.first);
			if (player.role()=="Dispatcher" && research_stations_cities.count(city.first)!=0) {
				CHECK_NOTHROW(same_role_player.fly_direct(other_city.first));
			}
		}
	}
	/* Other-Players Action (no special action when discovering cure) */
	for (auto &city : cities) {
		for (auto &other_city : cities) {
			Player same_role_player = get_new_player(board, city.first, player.role());
			if (city.first==other_city.first) continue;
			/* should throw an error (no card of destinition city) */
			CHECK_THROWS(same_role_player.fly_direct(other_city.first));
			same_role_player.take_card(other_city.first);
			/* should not throw an error (card taken) */
			CHECK_NOTHROW(same_role_player.fly_direct(other_city.first));
	    }
	}
}

/* --------------------------- Fly Charter Test --------------------------- */
// should take an empty board
void fly_charter_test(Player& player, Board& board) {
	for (auto &city : cities) {
		for (auto &other_city : cities) {
			if (city.first==other_city.first) continue;
			Player same_role_player = get_new_player(board, city.first, player.role());
			/* should throw an error (no card of the current city) */
			CHECK_THROWS(same_role_player.fly_charter(other_city.first));
			same_role_player.take_card(city.first);
			/* should not throw an error (card taken) */
			CHECK_NOTHROW(same_role_player.fly_charter(other_city.first));
	    }
	}
}

/* ------------------------- Build & Fly Shuttle Test ------------------------- */
/* should run build_test before this test (to build research stations) */
void fly_shuttle_test(Player& player, Board& board) {
	for (auto &city : cities) {
		for (auto &other_city : cities) {
			Player same_role_player = get_new_player(board, city.first, player.role());
			if (research_stations_cities.count(city.first)==0||
				research_stations_cities.count(other_city.first)==0) {
				/* should throw an error (no research station in src/dest city) */
				CHECK_THROWS(same_role_player.fly_shuttle(other_city.first));
			} else {
				/* should not throw an error (both cities have a research station) */
				CHECK_NOTHROW(same_role_player.fly_shuttle(other_city.first));
			}
	    }
	}
}

/* build research stations only for the cities generated randomly by init() method */
void build_test(Player& player, Board& board) {
	for (auto &city : research_stations_cities) {
		/* OperationsExpert Action */
		if (player.role()=="OperationsExpert") {
			OperationsExpert same_player_role(board, city);
			/* will never throw an error (truth of the action is tested in fly_shuttle_test) */
			CHECK_NOTHROW(same_player_role.build());
		} else {
			/* Default-Player Action */
			Player same_player_role = get_new_player(board, city, player.role());
			/* should throw an error (no card) */
			CHECK_THROWS(same_player_role.build());
			same_player_role.take_card(city);
			/* should not throw an error (card taken) */
			CHECK_NOTHROW(same_player_role.build());
		}
	}
}

void build_and_fly_shuttle_test(Player& player, Board& board) {
	/* build random research stations */
	build_test(player, board);
	/* pass the player (any type of player should behave the same way in fly_shuttle method) */
	fly_shuttle_test(player, board);
}

/* ---------------------------- Discover Cure Test ---------------------------- */
void discover_cure_test(Player& player, Board& board) {
	/* Scientist Action */
	if (player.role() == "Scientist") {
		for (auto &city : cities) {
			int iRand = (rand() % 9) + 1;
			Scientist scientist(board, city.first, iRand);
			int counter = 0;
			for (auto &c : cities) {
				if (city.second.color==c.second.color) {
					CHECK_THROWS(scientist.discover_cure(city.second.color));
					scientist.take_card(c.first);
					if ((++counter)==iRand) break;
				}
			}
			if (research_stations_cities.count(city.first)==0) {
				CHECK_THROWS(scientist.discover_cure(city.second.color));
			} else {
				CHECK_NOTHROW(scientist.discover_cure(city.second.color));
				board.remove_cures();
			}
		}
		return;
	}
	/* Researcher Action */
	if (player.role() == "Researcher") {
		for (auto &city : cities) {
			Researcher researcher(board, city.first);
			int counter = 0;
			for (auto &c : cities) {
				if (city.second.color==c.second.color) {
					CHECK_THROWS(researcher.discover_cure(city.second.color));
					researcher.take_card(c.first);
					if ((++counter)==5) break;
				}
			}
			CHECK_NOTHROW(researcher.discover_cure(city.second.color));
			board.remove_cures();
		}
		return;
	}
	/* GeneSplicer Action */
	if (player.role() == "GeneSplicer") {
		for (auto &city : cities) {
			GeneSplicer geneSplicer(board, city.first);
			int counter = 0;
			set<City> cards{};
			while (cards.size()<5) {
				auto it = cities.begin();
				std::advance(it, (uint)rand() % cities.size());
				geneSplicer.take_card(it->first);
				cards.insert(it->first);
			}
			if (research_stations_cities.count(city.first)==0) {
				CHECK_THROWS(geneSplicer.discover_cure(city.second.color));
			} else {
				board.remove_cures();
				CHECK_NOTHROW(geneSplicer.discover_cure(city.second.color));
			}
		}
		return;
	}
	/* Other-Players Action (no special action when discovering cure) */
	for (auto &city : cities) {
		Player default_player = get_new_player(board, city.first, player.role());
		if (research_stations_cities.count(city.first)!=0) {
			int counter = 0;
			for (auto &other_city : cities) {
				if (counter==5) {
					CHECK_NOTHROW(default_player.discover_cure(cities[city.first].color));
					break;
				} else if (city.first!=other_city.first&&cities[city.first].color==cities[other_city.first].color) {
					CHECK_THROWS(default_player.discover_cure(cities[city.first].color));
					default_player.take_card(other_city.first);
					counter++;
				}
			}
			board.remove_cures();
		} else {
			for (auto &other_city : cities) {
				default_player.take_card(other_city.first);
			}
			for (auto &other_city : cities) {
				CHECK_THROWS(default_player.discover_cure(cities[city.first].color));
			}
		}
	}
}

/* ---------------------------- Treat Test ---------------------------- */
void treat_test(Player& player, Board& board) {
	/* Medic Action */
	if (player.role()=="Medic") {
		for (auto &city : cities) {
			Medic same_role_player(board, city.first);
			/* calculate a random variable (between 1 and 9) for the level of disease in the current city */
			int iRand = (rand() % 9) + 1;
			board[city.first] = iRand;
			/* should not throw an error (medic set the disease to 0) */
			CHECK_NOTHROW(same_role_player.treat(city.first));
			/* default player */
			Player p{board, city.first};
			/* should throw an error (medic already set the disease to 0) */
			CHECK_THROWS(p.treat(city.first));
		}
		return;
	}
	/* Virologist Action */
	if (player.role()=="Virologist") {
		for (auto &city : cities) {
			/* calculate a random variable (between 1 and 9) for the level of disease in the current city */
			int iRand = (rand() % 9) + 1;
			board[city.first] = iRand;
			/* should throw an error (medic set the disease to 0) */
			auto it = cities.begin();
			while (it->first==city.first) {
				it = cities.begin();
				std::advance(it, (uint)rand() % cities.size());
			}
			Virologist same_role_player(board, it->first);
			/* should throw an error (no card) */
			CHECK_THROWS(same_role_player.treat(city.first));
			Player p{board, city.first};
			/* take the card */
			same_role_player.take_card(city.first);
			/* should not throw an error (card taken) */
			CHECK_NOTHROW(same_role_player.treat(city.first));
		}
		return;
	}
	/* FieldDoctor Action */
	if (player.role()=="FieldDoctor") {
		for (auto &city : cities) {
			FieldDoctor same_role_player(board, city.first);
			/* calculate a random variable (between 1 and 9) for the level of disease in the current city */
			int iRand = (rand() % 9) + 1;
			board[city.first] = iRand;
			/* should throw an error (medic set the disease to 0) */
			auto it = cities.begin();
			it = cities.begin();
			std::advance(it, (uint)rand() % cities.size());
			board[it->first] = iRand;
			if (city.first==it->first || board[city.first].neighbors.count(it->first)) {
				/* should not throw an error (nearby city) */
				CHECK_NOTHROW(same_role_player.treat(it->first));
			} else {
				/* should throw an error (not a nearby city) */
				CHECK_THROWS(same_role_player.treat(it->first));
			}
		}
		return;
	}
	/* Other-Players Action */
	for (auto &city : cities) {
		Player same_role_player = get_new_player(board, city.first, player.role());
		/* calculate a random variable (between 1 and 9) for the level of disease in the current city */
		int iRand = (rand() % 9) + 1;
		board[city.first] = iRand;
		/* simulate a scenario where a cure is found (only for numbers greater than 5) */
		if (iRand>5) {
			/* discover a cure for the current city */
			Researcher researcher = five_cards_researcher(board, city.first);
			researcher.discover_cure(city.second.color);
			/* should not throw an error (disease level is greater than 0)) */
			CHECK_NOTHROW(same_role_player.treat(city.first));
			stringstream des;
			des << board[city.first];
			/* check if the disease level has been set to 0 (cure has been found) */
			CHECK(des.str() == "0");
			board.remove_cures();
		} else {
			/* simulate a scenario where a cure is not found (only for numbers smaller than 5) */
			while (iRand>=0) {
				/* should throw an error (trying to treat while disease level is 0) */
				if (iRand==0) {
					CHECK_THROWS(same_role_player.treat(city.first));
					break;
				}
				/* should not throw an error (reduce disease level by 1) */
				CHECK_NOTHROW(same_role_player.treat(city.first));
				iRand--;
				stringstream des;
				des << board[city.first];
				/* check if the disease level has been reduces by 1 */
				CHECK(des.str() == to_string(iRand));
			}
		}
		
	}
}

#include "Virologist.hpp"


//////////////////////////////////////////////////////////////////////////
////////////////////////////// Tests Cases ///////////////////////////////
///////////////  ________________________________________  ///////////////
/////////////// | Should run build_and_fly_shuttle_test  | ///////////////
/////////////// | before all to build research stations! | ///////////////
/////////////// |________________________________________| ///////////////
//////////////////////////////////////////////////////////////////////////

TEST_CASE("Player Test") {
	/* init */
	init();
	Board board;
	Player player(board, City::Washington);
	build_and_fly_shuttle_test(player, board);
	SUBCASE("Player Drive Test") {
		drive_test(player, board);
	}
	SUBCASE("Player Fly Direct Test") {
		fly_direct_test(player, board);
	}
	SUBCASE("Player Fly Charter Test") {
		fly_charter_test(player, board);
	}
	SUBCASE("Player Discover Cure Test") {
		discover_cure_test(player, board);
	}
	SUBCASE("Player Treat Test") {
		treat_test(player, board);
	}
}

TEST_CASE("Researcher Test") {
	/* init */
	init();
	Board board;
	Researcher player(board, City::Washington);
	build_and_fly_shuttle_test(player, board);
	SUBCASE("Researcher Drive Test") {
		drive_test(player, board);
	}
	SUBCASE("Researcher Fly Direct Test") {
		fly_direct_test(player, board);
	}
	SUBCASE("Researcher Fly Charter Test") {
		fly_charter_test(player, board);
	}
	SUBCASE("Researcher Discover Cure Test") {
		discover_cure_test(player, board);
	}
	SUBCASE("Researcher Treat Test") {
		treat_test(player, board);
	}
}

TEST_CASE("Scientist Test") {
	/* init */
	init();
	Board board;
	Scientist player(board, City::Washington, 4);
	build_and_fly_shuttle_test(player, board);
	SUBCASE("Scientist Drive Test") {
		drive_test(player, board);
	}
	SUBCASE("Scientist Fly Direct Test") {
		fly_direct_test(player, board);
	}
	SUBCASE("Scientist Fly Charter Test") {
		fly_charter_test(player, board);
	}
	SUBCASE("Scientist Discover Cure Test") {
		discover_cure_test(player, board);
	}
	SUBCASE("Scientist Treat Test") {
		treat_test(player, board);
	}
}

TEST_CASE("FieldDoctor Test") {
	/* init */
	init();
	Board board;
	FieldDoctor player(board, City::Washington);
	build_and_fly_shuttle_test(player, board);
	SUBCASE("FieldDoctor Drive Test") {
		drive_test(player, board);
	}
	SUBCASE("FieldDoctor Fly Direct Test") {
		fly_direct_test(player, board);
	}
	SUBCASE("FieldDoctor Fly Charter Test") {
		fly_charter_test(player, board);
	}
	SUBCASE("FieldDoctor Discover Cure Test") {
		discover_cure_test(player, board);
	}
	SUBCASE("FieldDoctor Treat Test") {
		treat_test(player, board);
	}
}

TEST_CASE("GeneSplicer Test") {
	/* init */
	init();
	Board board;
	GeneSplicer player(board, City::Washington);
	build_and_fly_shuttle_test(player, board);
	SUBCASE("GeneSplicer Drive Test") {
		drive_test(player, board);
	}
	SUBCASE("GeneSplicer Fly Direct Test") {
		fly_direct_test(player, board);
	}
	SUBCASE("GeneSplicer Fly Charter Test") {
		fly_charter_test(player, board);
	}
	SUBCASE("GeneSplicer Discover Cure Test") {
		discover_cure_test(player, board);
	}
	SUBCASE("GeneSplicer Treat Test") {
		treat_test(player, board);
	}
}

TEST_CASE("OperationsExpert Test") {
	/* init */
	init();
	Board board;
	OperationsExpert player(board, City::Washington);
	build_and_fly_shuttle_test(player, board);
	SUBCASE("OperationsExpert Drive Test") {
		drive_test(player, board);
	}
	SUBCASE("OperationsExpert Fly Direct Test") {
		fly_direct_test(player, board);
	}
	SUBCASE("OperationsExpert Fly Charter Test") {
		fly_charter_test(player, board);
	}
	SUBCASE("OperationsExpert Discover Cure Test") {
		discover_cure_test(player, board);
	}
	SUBCASE("OperationsExpert Treat Test") {
		treat_test(player, board);
	}
}

TEST_CASE("Dispatcher Test") {
	/* init */
	init();
	Board board;
	Dispatcher player(board, City::Washington);
	build_and_fly_shuttle_test(player, board);
	SUBCASE("Dispatcher Drive Test") {
		drive_test(player, board);
	}
	SUBCASE("Dispatcher Fly Direct Test") {
		fly_direct_test(player, board);
	}
	SUBCASE("Dispatcher Fly Charter Test") {
		fly_charter_test(player, board);
	}
	SUBCASE("Dispatcher Discover Cure Test") {
		discover_cure_test(player, board);
	}
	SUBCASE("Dispatcher Treat Test") {
		treat_test(player, board);
	}
}

TEST_CASE("Medic Test") {
	/* init */
	init();
	Board board;
	Medic player(board, City::Washington);
	build_and_fly_shuttle_test(player, board);
	SUBCASE("Medic Drive Test") {
		drive_test(player, board);
	}
	SUBCASE("Medic Fly Direct Test") {
		fly_direct_test(player, board);
	}
	SUBCASE("Medic Fly Charter Test") {
		fly_charter_test(player, board);
	}
	SUBCASE("Medic Discover Cure Test") {
		discover_cure_test(player, board);
	}
	SUBCASE("Medic Treat Test") {
		treat_test(player, board);
	}
}

TEST_CASE("Virologist Test") {
	/* init */
	init();
	Board board;
	Virologist player(board, City::Washington);
	build_and_fly_shuttle_test(player, board);
	SUBCASE("Virologist Drive Test") {
		drive_test(player, board);
	}
	SUBCASE("Virologist Fly Direct Test") {
		fly_direct_test(player, board);
	}
	SUBCASE("Virologist Fly Charter Test") {
		fly_charter_test(player, board);
	}
	SUBCASE("Virologist Discover Cure Test") {
		discover_cure_test(player, board);
	}
	SUBCASE("Virologist Treat Test") {
		treat_test(player, board);
	}
}