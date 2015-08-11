//Reservation.h
#include<string>

using namespace std;

class Passenger;
class TrainRun;

class Reservation{
		string coach_no;
		int seat_number;
		Passenger *mypassenger;
		TrainRun *mytrain;
public:
		~Reservation();
		Reservation(string coach, int seat, Passenger* p1, TrainRun* tr);
		void printReservationDetails();
		void printReservationChart();
		string coach();
};
