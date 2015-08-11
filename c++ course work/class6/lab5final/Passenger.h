// Passenger.h
#include<iostream>
#include<fstream>

using namespace std;

class Passenger{
	string passenger_name;
	int passenger_age;
	char passenger_gender;
	string coach_number;
	int seat_number;
public:
	Passenger(string pname, int age, char passenger_gender, string coach, int seat);
	void showPassenger() const;
	void writePassenger(fstream& file_stream);
};

