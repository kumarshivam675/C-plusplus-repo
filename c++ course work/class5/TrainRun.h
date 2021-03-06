//Train.h

#include<vector>
#include<string>

using namespace std;

class Ticket;
class Reservation;

class TrainRun{
		string train_number;
		string source;
		string destination;
		string date;
		vector<Ticket*> tickets;
		vector<Reservation*> reservations;
public:
		TrainRun(string trainnumber, string source, string destination, string date);
		void printReservationChart();
		string printTrainDetails();
		void addTicket(Ticket *ticket);
		void addReservation(Reservation* r);
};
