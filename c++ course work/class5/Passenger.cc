//Passenger.cc
#include<iostream>
#include<string>

#include "Passenger.h"
#include "Reservation.h"
#include "TrainRun.h"
#include "Ticket.h"

using namespace std;

Passenger::Passenger(string pass_name, int pass_age, char pass_gender, string coach, int seat, Ticket* t1, TrainRun* tr){
	name = pass_name;
	age = pass_age;
	gender = pass_gender;
	my_ticket = t1;
	my_reservation = new Reservation(coach, seat, this, tr);
	
}

void Passenger::printPassenger(){
	cout << "\t" << name << "\t\t\t";
	cout << age << "\t\t\t";
	cout << gender << "\t\t\t";
	my_reservation->printReservationDetails();
}

void Passenger::printPassengerChart(int temp_seat){
	cout << "\t";
	cout << name << "\t\t\t";
	cout << age << "\t\t\t";
	cout << gender << "\t\t\t";
	cout << temp_seat << "\t\t\t";
	my_ticket->printTicketChart();
}

