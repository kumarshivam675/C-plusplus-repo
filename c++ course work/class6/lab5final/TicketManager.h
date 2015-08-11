#include<fstream>

class Ticket;

class TicketManager{
	fstream ticket_file;
public:
	TicketManager( string ticket_file_name );
	void saveTicket(const Ticket& );
	bool loadTicket( string PNR, Ticket& );
};

