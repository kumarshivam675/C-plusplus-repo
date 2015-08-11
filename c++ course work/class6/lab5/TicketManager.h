#include<string>
#include<fstream>

using namespace std;

class Ticket;

class TicketManager{
	string dataFileName;
	fstream dataFileStr;
public:
	TicketManager(string file_name);
	void saveTicket(Ticket& t);
	bool loadTicket(string PNR, Ticket& t);
};
