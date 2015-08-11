// VfsCommand
#include <string>
#include <iostream>
#include<sstream>
#include "VfsCommand.h"
#include "VfsRepository.h"

using namespace std;

VfsCommand *VfsCommand::getVfsCommand( string cmdline )
{
	string cmd, arg1, arg2;
	VfsCommand *cmdObject;

	stringstream cmdstr(cmdline);
	
	cmdstr >> cmd >> arg1 >> arg2;
	// cout << "cmd:" << cmd << " arg1:" << arg1 << " arg2:" << arg2 << endl;
	if( cmd == "quit" || cmd == "exit" ){
		cmdObject = (VfsCommand*) 0;
	} else if( cmd == "create" ){
		// Create and return specific object for the command
		cmdObject = new VfsCreateCommand( arg1, arg2 );
	} else if( cmd == "open" ){
		// Create and return specific object for the command
		cmdObject = new VfsOpenCommand( arg1 );
	} else if( cmd == "close" ){
		// Create and return specific object for the command
		cmdObject = new VfsCloseCommand();
	} else if( cmd == "list" ){
		// Create and return specific object for the command
		cmdObject = new VfsListCommand( arg1 );
	} else if( cmd == "makedir" ){
		// Create and return specific object for the command
		cmdObject = new VfsMakeDirCommand( arg1 );
	} else if( cmd == "copy" ){
		// Create and return specific object for the command
		cmdObject = new VfsCopyCommand( arg1, arg2 );
	} else if( cmd == "move" ){
		// Create and return specific object for the command
		cmdObject = new VfsMoveCommand( arg1, arg2 );
	} else if( cmd == "cat" ){
		// Create and return specific object for the command
		cmdObject = new VfsCatCommand( arg1  );
	}
	else{
		// Return error command object
		cmdObject = new VfsInvalidCommand();
	}
	return cmdObject;
}

//========================================================================

VfsCommand::VfsCommand( const char *cmd, string arg1, string arg2) :
	command(cmd), param1(arg1), param2(arg2)
{
}

//========================================================================

VfsInvalidCommand::VfsInvalidCommand() :
	VfsCommand("error", string(""), string(""))
{
}

int VfsInvalidCommand::doCommand()
{
	throw "Invalid command";
}

string VfsInvalidCommand::usage()
{
	return ("Commands: create open close list makedir copy move cat");
}

//========================================================================

VfsCreateCommand::VfsCreateCommand( string arg1, string arg2) :
	VfsCommand("create", arg1, arg2)
{
}

int VfsCreateCommand::doCommand()
{
	VfsRepository repo(param1);
	repo.create(param2);
	cout << "VfsCreateCommand executed" << endl;
}

string VfsCreateCommand::usage()
{
	return ("create file-system-name");
}

//========================================================================

VfsOpenCommand::VfsOpenCommand( string arg1 ) :
	VfsCommand("open", arg1, string("") )
{
}

int VfsOpenCommand::doCommand()
{
	cout << "VfsOpenCommand executed" << endl;
}

string VfsOpenCommand::usage()
{
	return ("open file-system-name");
}

//========================================================================

VfsCloseCommand::VfsCloseCommand() :
	VfsCommand("close", string(""), string(""))
{
}

int VfsCloseCommand::doCommand()
{
	cout << "VfsCloseCommand executed" << endl;
}

string VfsCloseCommand::usage()
{
	return ("close");
}

//========================================================================

VfsMakeDirCommand::VfsMakeDirCommand( string arg1 ) :
	VfsCommand("makedir", arg1, string("") )
{
}

int VfsMakeDirCommand::doCommand()
{
	cout << "VfsMakeDirCommand executed" << endl;
}

string VfsMakeDirCommand::usage()
{
	return ("makedir full-dir-path");
}

//========================================================================

VfsCopyCommand::VfsCopyCommand( string arg1, string arg2) :
	VfsCommand("copy", arg1, arg2)
{
}

int VfsCopyCommand::doCommand()
{
	cout << "VfsCopyCommand executed" << endl;
}

string VfsCopyCommand::usage()
{
	return ("copy source-full-path dest-full-path");
}

//========================================================================

VfsMoveCommand::VfsMoveCommand( string arg1, string arg2) :
	VfsCommand("move", arg1, arg2)
{
}

int VfsMoveCommand::doCommand()
{
	cout << "VfsMoveCommand executed" << endl;
}

string VfsMoveCommand::usage()
{
	return ("move source-full-path dest-full-path");
}

//========================================================================

VfsCatCommand::VfsCatCommand( string arg1 ) :
	VfsCommand("cat", arg1, string("") )
{
}

int VfsCatCommand::doCommand()
{
	cout << "VfsCatCommand executed" << endl;
}

string VfsCatCommand::usage()
{
	return ("cat text-file-path");
}

//========================================================================

VfsListCommand::VfsListCommand( string arg1 ) :
	VfsCommand("list", arg1, string(""))
{
}

int VfsListCommand::doCommand()
{
	cout << "VfsListCommand executed" << endl;
}

string VfsListCommand::usage()
{
	return ("list full-path");
}

//========================================================================

VfsDeleteCommand::VfsDeleteCommand( string arg1 ) :
	VfsCommand("delete", arg1, string(""))
{
}

int VfsDeleteCommand::doCommand()
{
	cout << "VfsDeleteCommand executed" << endl;
}

string VfsDeleteCommand::usage()
{
	return ("delete full-file-or-folder-path");
}



