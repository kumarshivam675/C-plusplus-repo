//Reservation.cc
#include<iostream>
#include<string>

#include "Reservation.h"
#include "Passenger.h"
#include "TrainRun.h"

using namespace std;

Reservation::Reservation(string coach, int seat, Passenger* p1, TrainRun* tr) : coach_no(coach), seat_number(seat){
	mypassenger = p1;
	mytrain = tr;
	mytrain->addReservation(this);
}

void Reservation::printReservationDetails(){
	cout << coach_no << "\t\t\t";
	cout << seat_number << endl;
}

void Reservation::printReservationChart(){
	int temp_seat = seat_number;
	mypassenger->printPassengerChart(temp_seat);
}

string Reservation::coach(){
	return coach_no;
}

Reservation::~Reservation(){
	delete mypassenger;
	delete mytrain;
}
