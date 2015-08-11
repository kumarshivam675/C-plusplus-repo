#include<cstdlib>
#include<fstream>
#include<iostream>
#include<cstdlib>
#include<string>
#include "VfsCommand.h"

using namespace std;

void processInstructions(istream& is, bool is_interactive);
VfsCommand *getVfsCommand( string cmdline );

int main(int argc, char *argv[])
{
	if( argc == 2 ){
		if( string(argv[1]) == string("--interactive")){
			processInstructions(cin, true);
		}
		else{
			ifstream cmdfile(argv[1]);
			if (! cmdfile.is_open()){
				cout << "Error opening file " << argv[1] << endl; 
				exit (2); 
			}

			processInstructions(cmdfile, false);
		}
	}
	else{
		cout << "Usage: " << argv[0] << " --interactive | cmdfile" << endl;
		exit(1);
	}
}

void processInstructions(istream& is, bool is_interactive)
{
	string cmdline;
	if(is_interactive){
		cout << "vfs> "; 
		cout.flush();
	}
	while( getline(is, cmdline) ){
		// cout << "Line read: " << cmdline << endl;
		VfsCommand *cmd = VfsCommand::getVfsCommand( cmdline );
		if( cmd == (VfsCommand*) 0 )
			break;		

		// Take all necessary action
		try{		
			cmd->doCommand();
		}
		catch(const char *err){
			cout << err << endl;
			cout << cmd->usage() << endl;
		}
		catch(...){
			cout << "Unknown encountered" << endl;
			cout << cmd->usage() << endl;
		}
		
		if(is_interactive){
			cout << "vfs> "; cout.flush();
		}
	}
}


