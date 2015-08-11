#include "Ticket.h"
#include "TrainRun.h"
#include "Reservation.h"
#include "Passenger.h"

main()
{
	TrainRun *train1 = new TrainRun("2244","SBC","MAS","15-01-2015");
	TrainRun *train2 = new TrainRun("4341","SBC","DEL","16-01-2015");

	Ticket *ticket1 = new Ticket(
			train1,
			"Bangalore City",
			"Salem");
	ticket1->addPassenger("John",25,'M',"S1",25);
	ticket1->addPassenger("Jane",45,'F',"S1",26);
	ticket1->addPassenger("Joe",35,'M',"S2",33);
		
	Ticket *ticket2 = new Ticket(
			train1,
			"Bangalore City",
			"Chennai");
	ticket2->addPassenger("AnotherJohn",25,'M',"S1",35);
	ticket2->addPassenger("AnotherJane",45,'F',"S2",36);
	ticket2->addPassenger("AnotherJoe",35,'M',"S4",33);
	
	Ticket *ticket3 = new Ticket(
			train2,
			"Bangalore City",
			"Nagpur");
	ticket3->addPassenger("YetAnotherJohn",25,'M',"S1",25);
	ticket3->addPassenger("YetAnotherJane",45,'F',"S2",26);
	ticket3->addPassenger("YetAnotherJoe",35,'M',"S3",33);

	ticket1->printTicket();
	ticket2->printTicket();
	ticket3->printTicket();

	train1->printReservationChart();
	train2->printReservationChart();

	delete train1;
	delete train2;
	delete ticket1;
	delete ticket2;
	delete ticket3;
}

