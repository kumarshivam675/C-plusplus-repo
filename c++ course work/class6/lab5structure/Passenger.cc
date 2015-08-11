#include<iostream>
#include<string>
#include<fstream>
#include "Passenger.h"

using namespace std;

Passenger::Passenger(string name, int p_age, char p_gender, string p_coach, int p_seat){
	passenger_name = name;
	passenger_age = p_age;
	passenger_gender = p_gender;
	coach_number = p_coach;
	seat_number = p_seat;
}

void Passenger::showPassenger() const
{
	cout << passenger_name << "\t\t" << passenger_age << "\t\t" << passenger_gender << "\t\t" << coach_number << "\t\t";
	cout << seat_number << "\n";
}

void Passenger::writePassenger(fstream& file_stream){
	file_stream << passenger_name << " , " << passenger_age << " , " << passenger_gender << " , ";
	file_stream << coach_number << " , " << seat_number << " , ";
}
