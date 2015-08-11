/*
This is the test program for testing ticket persistence.
Assuming the name of the exe is a.out, you can run the program in the following
two modes:
Mode 1: a.out -s filename
In this mode, the program will store 10 tickets automatically into the given data file

Mode 2: a.out -r filename
In this mode, the program will prompt for PNR number and try to retrive that ticket
You can end by sending EOF key (ctrl-d)
*/

#include<iostream>
#include<string>
#include<sstream>
#include<ctime>

using namespace std;

#include "Ticket.h"
#include "Passenger.h"
#include "TicketManager.h"

void get_tickets( TicketManager& ticket_manager );
void store_tickets( TicketManager& ticket_manager );

main(int argc, char *argv[])
{
	if( argc != 3 || (string(argv[1]) != "-s" && string(argv[1]) != "-r" )){
		cerr << "Usage: " << argv[0] << " [-s | -r] datafile" << endl;
		exit(1);
	}
	string option = argv[1];
	string datafile = argv[2];
	
	TicketManager ticket_manager(datafile);
	if( option == "-s" )
		store_tickets(ticket_manager);
	else 
		get_tickets(ticket_manager);
}

void get_tickets( TicketManager& ticket_manager )
{
	string PNR;
	cout << "Enter PNR for retrieval" << endl;
	while( cin >> PNR ){
		Ticket ticket;
		//cout << "entry\n";
		bool status = ticket_manager.loadTicket( PNR, ticket );
		if( status ){
			//cout << "entry\n";
			ticket.printTicket();
		}
		else
			cout << "Ticket with PNR " << PNR << " not found" << endl;
		cout << "Enter PNR for retrieval" << endl;
	}
}

void store_tickets( TicketManager& ticket_manager )
{
	for( int i = 0; i < 10; i++ ){
		stringstream str;
		str << "PNR-" << i << endl;
		string PNR = str.str();

		// Clear the stringstream
		str.clear(); str.str("");
		str << "passenger-" << i << ".1";
		string passenger1 = str.str();

		str.clear(); str.str("");
		str << "passenger-" << i << ".1";
		string passenger2 = str.str();

		str.clear(); str.str("");
		str << "passenger-" << i << ".1";
		string passenger3 = str.str();

		Ticket t1(PNR,"TRAIN-101","BLR","MAS");
		t1.addPassenger(passenger1, 20, 'M',"S1",19);
		t1.addPassenger(passenger2, 22, 'M',"S1",20);
		t1.addPassenger(passenger3, 40, 'F',"S1",21);

		cout << "Saving ticket " << PNR << endl;
		ticket_manager.saveTicket( t1 );
	}
}
