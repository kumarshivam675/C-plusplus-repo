// Ticket.h
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class Passenger;

struct sPassenger{
	char spassenger_name[25];
	int spassenger_age;
	char spassenger_gender;
	char scoach_number[25];
	int sseat_number;
};

struct sTicket{
	char sPNR[25];
	char strain_num[25];
	char ssource[25];
	char sdestination[25];
	int count = 0;
	sPassenger pobj[6];
};


class Ticket{
	string PNR;
	string train_num;
	string source;
	string destination;
	vector<Passenger*> mypassenger_details;
public:
	sTicket sobj;
	~Ticket();
	Ticket();
	string getPNR();
	Ticket(string pnr, string train_no, string src, string dest);
	void addPassenger(string pname, int age, char gender, string coach, int seat);
	void printTicket() const;
	void writeTicket(fstream& file_stream) const;
	void assignValue( string pnr, string trainnum, string source, string destination);
};

