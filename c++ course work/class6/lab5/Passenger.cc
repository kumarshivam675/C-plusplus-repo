#include<iostream>
#include<string>
#include "Passenger.h"

using namespace std;

Passenger::Passenger(string name, int p_age, char p_gender, string p_coach, int p_seat){
	pName = name;
	age = p_age;
	gender = p_gender;
	coach = p_coach;
	seatnum = p_seat;
}

string Passenger::showPassenger(){
	cout << pName << "\t\t" << age << "\t\t" << gender << "\t\t" << coach << "\t\t" << seatnum << "\n";
}
