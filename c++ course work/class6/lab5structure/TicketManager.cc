#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<sstream>
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
		ticket_file.open(file_name, ios::in | ios::out | ios::binary);
	}
	
	else
	{
		ticket_file.open(file_name, ios::out);
		ticket_file.close();
		ticket_file.open(file_name, ios::in | ios::out | ios::binary);
	}

	if(!ticket_file.good())
		cout << "Stream not good\n";
}

bool TicketManager::loadTicket(string PNR, Ticket& t){
	stringstream str;
	str << PNR << endl;
	string pnr = str.str();
	sTicket obj;
	bool found = false;
	while(!found){
		ticket_file.read((char*)&obj, sizeof(obj));
		if(obj.sPNR == pnr){
			found = true;
			t.sobj = obj;
		}
	}
	
	return found;
}

void TicketManager::saveTicket(const Ticket& t){
	ticket_file.seekp(0,ios::end);
	t.writeTicket(ticket_file);
}
