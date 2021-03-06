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
	dataFileName = file_name;
	if( fileExists(file_name)){
		dataFileStr.open(file_name, ios::in | ios::out | ios::binary);
	}
	
	else
	{
		dataFileStr.open(file_name, ios::out | ios::binary);
		dataFileStr.close();
		dataFileStr.open(file_name, ios::in | ios::out | ios::binary);

		
	}

	if(!dataFileStr.good())
		cout << "Stream not good\n";
}

bool TicketManager::loadTicket(string PNR, Ticket& t){
	cout << "welcome\n";
	dataFileStr.open(dataFileName, ios::in | ios:: out | ios::binary);
	dataFileStr.seekg(0,ios::beg);
	string temp;
	bool found = false;
	while(!found){
		cout << "welcome again\n";
		if(dataFileStr.read((char*) &t , sizeof (Ticket))){
			cout << "again\n";
			cout<<t.getPNR()<<" T.GETPNR()"<<endl;
			temp = t.getPNR(); //Segmentation fault is happening here in the function t.getPNR()
			cout << "\nand why\n";
			cout << temp << "what happened\n";
			//if(temp == PNR)
				cout << "not bad\n";
				//found = true;
		}
		else 
			break;
	}
	return found;
}

void TicketManager::saveTicket(Ticket& t){
	//cout << "\n pnr checking1\n" << t.getPNR() << "\npnr checking\n" << endl;
	dataFileStr.seekp(0,ios::end);
	dataFileStr.write ((char*) &t, sizeof (Ticket));
	dataFileStr.close();
}
