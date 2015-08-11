#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<sys/stat.h>
#include "Ticket.h"
#include "TicketManager.h"


using namespace std;

bool fileExists(const std::string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
	return true;
    }
    return false;
}

TicketManager::TicketManager(string file_name){
	if( fileExists(file_name)){
		ticket_file.open(file_name, ios::in | ios::out);
	}
	
	else
	{
		ticket_file.open(file_name, ios::out);
		ticket_file.close();
		ticket_file.open(file_name, ios::in | ios::out);
	}

	if(!ticket_file.good())
		cout << "Stream not good\n";
}

bool TicketManager::loadTicket(string PNR, Ticket& t){
	int count = 0, count1 = 0;
	ticket_file.seekg(0,ios::beg);
	string pnr, trainnum, source, destination, p_name,coach_num, temp = ",";
	char p_gender;
	int p_age, seatnum;
	bool found = false;
	while(!found){
		ticket_file >> pnr;
		if(ticket_file.eof())
			break;
		ticket_file >> temp >> trainnum >> temp >> source >> temp >> destination >> temp;
		if(pnr != PNR){	
			while(temp!= "end"){
				ticket_file >> temp;
				count1++;
				if(temp == "end") {
					break;
				}
			}
			if(ticket_file.eof())
				break;
		}
		
		else {
			found = true;
			t.assignValue(pnr, trainnum, source, destination);
			while(1){
				if(count == 0){
					ticket_file >> p_name;
					count++;
				}	
				ticket_file >> temp >> p_age >> temp >> p_gender >> temp;
				ticket_file >> coach_num >> temp >> seatnum >> temp >> temp;
				t.addPassenger(p_name, p_age, p_gender, coach_num, seatnum);
				if(temp == "end")
					break;
				p_name = temp;
			}

		}

	}
	ticket_file.clear();
	return found;
}

void TicketManager::saveTicket(const Ticket& t){
	ticket_file.seekp(0,ios::end);
	t.writeTicket(ticket_file);
}
