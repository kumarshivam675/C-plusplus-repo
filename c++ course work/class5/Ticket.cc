//Ticket.cc
#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>

#include "Ticket.h"
#include "Passenger.h"
#include "TrainRun.h"

using namespace std;

Ticket::Ticket(TrainRun *t1, string source, string destination): source_station(source), dest_station(destination){
	PNR_Number =rand()%10000;
	train = t1;
	train->addTicket(this);
}

void Ticket::addPassenger(string name, int age, char gender,string coach, int seat){
	Passenger *ptr = new Passenger(name, age, gender, coach, seat, this, train);
	passenger_details.push_back(ptr);
}

void Ticket::printTicket(){
	string temp;
	temp = train->printTrainDetails();
	cout << "PNR Number is " << PNR_Number << "\t\t\t";
	cout << "Train Running Date is " << temp << "\n";
	cout << "Source Station is " << source_station << "\t";
	cout << "Destination Station is " << dest_station << endl;
	cout << "\tName\t\t\t" << "Age\t\t\t" << "Gender\t\t\t" << "Coach\t\t\t" << "Seat\n";
	for(int i = 0; i< passenger_details.size(); i++){
		passenger_details[i]->printPassenger();
	}
}


void Ticket::printTicketChart(){
	cout << PNR_Number << endl;
}

Ticket::~Ticket(){
	for(int i = 0; i< passenger_details.size(); i++)
		delete passenger_details[i];
	
}
