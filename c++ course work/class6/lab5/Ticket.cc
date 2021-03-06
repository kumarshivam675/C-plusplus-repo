#include<iostream>
#include<string>
#include<vector>
#include "Ticket.h"
#include "Passenger.h"

using namespace std;

Ticket::Ticket(){
}

Ticket::Ticket(string PNR, string trainnumber, string sourcestation, string destinationstation){
	PNR_Number = PNR;
	trainnum = trainnumber;
	source = sourcestation;
	destination = destinationstation;
}
	

string Ticket::getPNR(){
	//cout << "returning PNR Number\n";
	return PNR_Number;
}

void Ticket::printTicket(){
	cout << "Printing Ticket\n";
	cout << "Train Number\t\t" << trainnum << "Source\t\t" << source << "Destination\n" << destination;
	cout << "\t" << "Name\t\t" << "Age\t\t" << "Gender\t\t" << "Coach\t\t" << "Seat\n";
	for( int i = 0; i < mypassenger_details.size(); i++){
		mypassenger_details[i]->showPassenger();
	}
}

void Ticket::addPassenger(string name, int age, char gender, string coach, int seat){
	Passenger *ptr = new Passenger(name, age, gender, coach, seat);
	mypassenger_details.push_back(ptr);
}
