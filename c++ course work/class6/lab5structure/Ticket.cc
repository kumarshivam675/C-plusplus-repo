#include<iostream>
#include<cstring>
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
	strcpy(sobj.sPNR,pnr.c_str());
	strcpy(sobj.strain_num, trainnumber.c_str());
	strcpy(sobj.ssource, sourcestation.c_str());
	strcpy(sobj.sdestination,destinationstation.c_str());
}
	

string Ticket::getPNR(){
	//cout << "returning PNR Number\n";
	return PNR;
}

void Ticket::printTicket() const
{
	cout << "Printing Ticket\n";
	cout << "Train Number: " << sobj.strain_num << "\t\tSource: " << sobj.ssource << "\t\tDestination: " << sobj.sdestination << "\n";
	cout << "Name\t\t" << "Age\t\t" << "Gender\t\t" << "Coach\t\t" << "Seat\n";
	for( int i = 0; i < sobj.count; i++){
		cout << sobj.pobj[i].spassenger_name << "\t\t" << sobj.pobj[i].spassenger_age << "\t\t" << sobj.pobj[i].spassenger_gender;
		cout << "\t\t" << sobj.pobj[i].scoach_number << "\t\t" << sobj.pobj[i].sseat_number << "\n";
	}
	
}

void Ticket::addPassenger(string name, int age, char gender, string coach, int seat){
	Passenger *ptr = new Passenger(name, age, gender, coach, seat);
	mypassenger_details.push_back(ptr);
	int i = sobj.count;
	strcpy(sobj.pobj[i].spassenger_name, name.c_str());
	sobj.pobj[i].spassenger_age = age;
	sobj.pobj[i].spassenger_gender = gender;
	strcpy(sobj.pobj[i].scoach_number, coach.c_str());
	sobj.pobj[i].sseat_number = seat;
	sobj.count += 1;
	
}

void Ticket::writeTicket(fstream& file_stream) const{
	file_stream.write((char*)&sobj, sizeof(sTicket));
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
	
