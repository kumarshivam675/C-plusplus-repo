// Ticket.h
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class Passenger;

class Ticket{
	string PNR;
	string train_num;
	string source;
	string destination;
	vector<Passenger*> mypassenger_details;
public:
	~Ticket();
	Ticket();
	string getPNR();
	Ticket(string pnr, string train_no, string src, string dest);
	void addPassenger(string pname, int age, char gender, string coach, int seat);
	void printTicket() const;
	void writeTicket(fstream& file_stream) const;
	void assignValue( string pnr, string trainnum, string source, string destination);
};

