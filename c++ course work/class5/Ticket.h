//Ticket.h

#include<vector>
#include<string>

using namespace std;
class Passenger;
class TrainRun;

class Ticket{
		int PNR_Number;
		string source_station;
		string dest_station;
		TrainRun *train;
		vector<Passenger*> passenger_details;
public:
		~Ticket();
		Ticket(TrainRun* t1 ,string source, string destination);
		void addPassenger(string name,int age,char gender,string coach,int seat_num);
		void printTicket();
		void printTicketChart();
};
