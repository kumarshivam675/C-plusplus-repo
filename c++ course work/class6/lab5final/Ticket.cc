#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "Ticket.h"
#include "Passenger.h"

using namespace std;

Ticket::Ticket(){
}

Ticket::Ticket(string pnr, string trainnumber, string sourcestation, string destinationstation){
	PNR = pnr;
	train_num = trainnumber;
	source = sourcestation;
	destination = destinationstation;
}
	

string Ticket::getPNR(){
	//cout << "returning PNR Number\n";
	return PNR;
}

void Ticket::printTicket() const
{
	cout << "Printing Ticket\n";
	cout << "Train Number" << train_num << "\t\tSource" << source << "\t\tDestination" << destination << "\n";
	cout << "\t" << "Name\t\t" << "Age\t\t" << "Gender\t\t" << "Coach\t\t" << "Seat\n";
	for( int i = 0; i < mypassenger_details.size(); i++){
		mypassenger_details[i]->showPassenger();
	}
}

void Ticket::addPassenger(string name, int age, char gender, string coach, int seat){
	Passenger *ptr = new Passenger(name, age, gender, coach, seat);
	mypassenger_details.push_back(ptr);
}

void Ticket::writeTicket(fstream& file_stream) const{
	file_stream << PNR << " , " << train_num << " , " << source << " , " << destination << " , ";
	for(int i = 0; i < mypassenger_details.size(); i++){
		mypassenger_details[i]->writePassenger(file_stream);
	}
	file_stream << "end\n";
}
	
void Ticket::assignValue(string pnr, string trainnum, string train_source, string train_destination){
	PNR =pnr;
	train_num = trainnum;
	source = train_source;
	destination =train_destination;
}

Ticket::~Ticket(){
	//cout << "invoking destructor\n";
	for(int i = 0; i < mypassenger_details.size(); i++)
		delete mypassenger_details[i];
}
	
