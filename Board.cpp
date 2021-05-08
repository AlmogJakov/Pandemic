#include "Board.hpp"
#include <iostream>

#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <iomanip> // setw(), setfill(), left (or right).

namespace pandemic {
    Board::Board() {
        /* init cities map */
        cities = {
            {City::Algiers,(city_struct){"Algiers",Color::Black,{City::Madrid, City::Paris, City::Istanbul, City::Cairo}}},
            {City::Atlanta,(city_struct){"Atlanta",Color::Blue,{City::Chicago, City::Miami, City::Washington}}},
            {City::Baghdad,(city_struct){"Baghdad",Color::Black,{City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi}}},
            {City::Bangkok,(city_struct){"Bangkok",Color::Red,{City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}}},
            {City::Beijing,(city_struct){"Beijing",Color::Red,{City::Shanghai, City::Seoul}}},
            {City::Bogota,(city_struct){"Bogota",Color::Yellow,{City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}}},
            {City::BuenosAires,(city_struct){"BuenosAires",Color::Yellow,{City::Bogota, City::SaoPaulo}}},
            {City::Cairo,(city_struct){"Cairo",Color::Black,{City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}}},
            {City::Chennai,(city_struct){"Chennai",Color::Black,{City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}}},
            {City::Chicago,(city_struct){"Chicago",Color::Blue,{City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}}},
            {City::Delhi,(city_struct){"Delhi",Color::Black,{City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata}}},
            {City::Essen,(city_struct){"Essen",Color::Blue,{City::London, City::Paris, City::Milan, City::StPetersburg}}},
            {City::HoChiMinhCity,(city_struct){"HoChiMinhCity",Color::Red,{City::Jakarta, City::Bangkok, City::HongKong, City::Manila}}},
            {City::HongKong,(city_struct){"HongKong",Color::Red,{City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}}},
            {City::Istanbul,(city_struct){"Istanbul",Color::Black,{City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}}},
            {City::Jakarta,(city_struct){"Jakarta",Color::Red,{City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}}},
            {City::Johannesburg,(city_struct){"Johannesburg",Color::Yellow,{City::Kinshasa, City::Khartoum}}},
            {City::Karachi,(city_struct){"Karachi",Color::Black,{City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi}}},
            {City::Khartoum,(city_struct){"Khartoum",Color::Yellow,{City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}}},
            {City::Kinshasa,(city_struct){"Kinshasa",Color::Yellow,{City::Lagos, City::Khartoum, City::Johannesburg}}},
            {City::Kolkata,(city_struct){"Kolkata",Color::Black,{City::Delhi, City::Chennai, City::Bangkok, City::HongKong}}},
            {City::Lagos,(city_struct){"Lagos",Color::Yellow,{City::SaoPaulo, City::Khartoum, City::Kinshasa}}},
            {City::Lima,(city_struct){"Lima",Color::Yellow,{City::MexicoCity, City::Bogota, City::Santiago}}},
            {City::London,(city_struct){"London",Color::Blue,{City::NewYork, City::Madrid, City::Essen, City::Paris}}},
            {City::LosAngeles,(city_struct){"LosAngeles",Color::Yellow,{City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney}}},
            {City::Madrid,(city_struct){"Madrid",Color::Blue,{City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers}}},
            {City::Manila,(city_struct){"Manila",Color::Red,{City::HongKong, City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney}}},
            {City::MexicoCity,(city_struct){"MexicoCity",Color::Yellow,{City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota}}},
            {City::Miami,(city_struct){"Miami",Color::Yellow,{City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}}},
            {City::Milan,(city_struct){"Milan",Color::Blue,{City::Essen, City::Paris, City::Istanbul}}},
            {City::Montreal,(city_struct){"Montreal",Color::Blue,{City::Chicago, City::Washington, City::NewYork}}},
            {City::Moscow,(city_struct){"Moscow",Color::Black,{City::StPetersburg, City::Istanbul, City::Tehran}}},
            {City::Mumbai,(city_struct){"Mumbai",Color::Black,{City::Karachi, City::Delhi, City::Chennai}}},
            {City::NewYork,(city_struct){"NewYork",Color::Blue,{City::Montreal, City::Washington, City::London, City::Madrid}}},
            {City::Osaka,(city_struct){"Osaka",Color::Red,{City::Taipei, City::Tokyo}}},
            {City::Paris,(city_struct){"Paris",Color::Blue,{City::Algiers, City::Essen, City::Madrid, City::Milan, City::London}}},
            {City::Riyadh,(city_struct){"Riyadh",Color::Black,{City::Baghdad, City::Cairo, City::Karachi}}},
            {City::SanFrancisco,(city_struct){"SanFrancisco",Color::Blue,{City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}}},
            {City::Santiago,(city_struct){"Santiago",Color::Yellow,{City::Lima}}},
            {City::SaoPaulo,(city_struct){"SaoPaulo",Color::Yellow,{City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}}},
            {City::Seoul,(city_struct){"Seoul",Color::Red,{City::Beijing, City::Shanghai, City::Tokyo}}},
            {City::Shanghai,(city_struct){"Shanghai",Color::Red,{City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}}},
            {City::StPetersburg,(city_struct){"StPetersburg",Color::Blue,{City::Essen, City::Istanbul, City::Moscow}}},
            {City::Sydney,(city_struct){"Sydney",Color::Red,{City::Jakarta, City::Manila, City::LosAngeles}}},
            {City::Taipei,(city_struct){"Taipei",Color::Red,{City::Shanghai, City::HongKong, City::Osaka, City::Manila}}},
            {City::Tehran,(city_struct){"Tehran",Color::Black,{City::Baghdad, City::Moscow, City::Karachi, City::Delhi}}},
            {City::Tokyo,(city_struct){"Tokyo",Color::Red,{City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}}},
            {City::Washington,(city_struct){"Washington",Color::Blue,{City::Atlanta, City::NewYork, City::Montreal, City::Miami}}}
        };
        /* init medicines map */
        medicines = {
            {Color::Blue,false},
            {Color::Yellow,false},
            {Color::Black,false},
            {Color::Red,false}
        };
        diseases = {};
    }

    /* get the color as string from city_struct object */
    string get_color(Color c) {
        if (c==Color::Blue) {return "Blue";}
        if (c==Color::Yellow) {return "Yellow";}
        if (c==Color::Black) {return "Black";}
        return "Red";
    }

    bool Board::is_clean() {
        for (auto &p : cities) {
                if (diseases.count(p.first)!=0&&diseases[p.first]>0) {return false;}
        }
        return true;
    }

    /* output operator for Board object */
    ostream& operator<<(ostream& os, Board& b) {
        const char separator    = ' ';
        const char lineSign    = '_';
        const int nameWidth     = 13;
        const int numWidth     = 3;
        const int lineWidth     = 55;
        /* setw() - helps to define the width of the output. */
        /* setfill() - Fill the rest with the character you want (in this case ' '). */
        /* left (or right) - allow to define the alignment. */
        os << left << setw(lineWidth) << setfill(lineSign) << "" << endl;
        int counter = 0;
        for (const auto &p : b.cities) {
            os << left << setw(nameWidth) << setfill(separator) << p.second.city << ":" << setw(numWidth) << setfill(separator) << b[p.first] << "| ";
            if ((++counter)%3==0) {os << endl;}
        }
        os << left << setw(lineWidth) << setfill(lineSign) << "" << "|" << endl;
        string total_details = "Research Stations: " + to_string(b.research_stations) + ". Medicines: " + to_string(b.medicines_count);
        os << left << setw(lineWidth) << setfill(separator) << total_details << "|" << endl;
        os << left << setw(lineWidth) << setfill(lineSign) << "" << "|" << endl;
        return os;
    };
}