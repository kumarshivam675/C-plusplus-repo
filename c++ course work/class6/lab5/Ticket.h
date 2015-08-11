#include<string>
#include<vector>

using namespace std;

class Passenger;

class Ticket{
	string PNR_Number;
	string trainnum;
	string source;
	string destination;
	vector<Passenger*> mypassenger_details;
public:
	Ticket();
	Ticket(string PNR, string trainnumber, string sourcestation, string destinationstation);
	string getPNR();
	void addPassenger(string name, int age, char gender, string coachnum, int seatnum);
	void printTicket();
};
