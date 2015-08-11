// VfsCommand
#include <string>
#include <iostream>
#include<sstream>
#include "VfsCommand.h"
#include "VfsRepository.h"
#include "PathString.h"

using namespace std;

VfsCommand *VfsCommand::getVfsCommand( string cmdline, VfsRepository* repo )
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
		cmdObject = new VfsCreateCommand( repo, arg1, arg2 );
	} else if( cmd == "open" ){
		// Create and return specific object for the command
		cmdObject = new VfsOpenCommand( repo, arg1, arg2 );
	} else if( cmd == "close" ){
		// Create and return specific object for the command
		cmdObject = new VfsCloseCommand(repo);
	} else if( cmd == "list" ){
		// Create and return specific object for the command
		cmdObject = new VfsListCommand( repo, arg1 );
	} else if( cmd == "makedir" ){
		// Create and return specific object for the command
		cmdObject = new VfsMakeDirCommand( repo, arg1 );
	} else if( cmd == "copy" ){
		// Create and return specific object for the command
		cmdObject = new VfsCopyCommand( repo, arg1, arg2 );
	} else if( cmd == "move" ){
		// Create and return specific object for the command
		cmdObject = new VfsMoveCommand( repo, arg1, arg2 );
	} else if( cmd == "cat" ){
		// Create and return specific object for the command
		cmdObject = new VfsCatCommand( repo, arg1  );
	}
	else{
		// Return error command object
		cmdObject = new VfsInvalidCommand();
	}
	return cmdObject;
}

//========================================================================

VfsCommand::VfsCommand(VfsRepository *repoptr, const char* cmdname, string arg1, string arg2) : repo(repoptr), command(cmdname), param1(arg1), param2(arg2)
{
}

//========================================================================

VfsInvalidCommand::VfsInvalidCommand() :
	VfsCommand(nullptr,"error", string(""), string(""))
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

VfsCreateCommand::VfsCreateCommand( VfsRepository* repo, string arg1, string arg2) :
	VfsCommand(repo, "create", arg1, arg2)
{
}

int VfsCreateCommand::doCommand()
{
	VfsRepository repo;
	repo.create(param1, param2);

	cout << "VfsCreateCommand executed" << endl;
}

string VfsCreateCommand::usage()
{
	return ("create file-system-name file-system-path");
}

//========================================================================

VfsOpenCommand::VfsOpenCommand( VfsRepository* repo, string arg1, string arg2 ) :
	VfsCommand(repo, "open", arg1, arg2 )
{
}

int VfsOpenCommand::doCommand()
{
	repo->open(param1, param2);
	cout << "VfsOpenCommand executed" << endl;
}

string VfsOpenCommand::usage()
{
	return ("open file-system-name file-system-path");
}

//========================================================================

VfsCloseCommand::VfsCloseCommand(VfsRepository* repo) :
	VfsCommand(repo, "close", string(""), string(""))
{
}

int VfsCloseCommand::doCommand()
{
	repo->close();
	cout << "VfsCloseCommand executed" << endl;
}

string VfsCloseCommand::usage()
{
	return ("close");
}

//========================================================================

VfsMakeDirCommand::VfsMakeDirCommand( VfsRepository* repo, string arg1 ) :
	VfsCommand(repo, "makedir", arg1, string("") )
{
     PathString p (arg1,"/");

     string path = p.excludeLast();

     string folder_name = p.getLast();

     repo->makeDir(path, folder_name);
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

VfsCopyCommand::VfsCopyCommand( VfsRepository* repo, string arg1, string arg2) :
	VfsCommand(repo, "copy", arg1, arg2)
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

VfsMoveCommand::VfsMoveCommand( VfsRepository* repo, string arg1, string arg2) :
	VfsCommand(repo, "move", arg1, arg2)
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

VfsCatCommand::VfsCatCommand( VfsRepository* repo, string arg1 ) :
	VfsCommand(repo, "cat", arg1, string("") )
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

VfsListCommand::VfsListCommand( VfsRepository* repo, string arg1 ) :
	VfsCommand(repo, "list", arg1, string(""))
{
}

int VfsListCommand::doCommand()
{
	vector<string> contents;
	repo->list(param1, contents);
	for( auto s : contents )
		cout << s << endl;
	cout << "VfsListCommand executed" << endl;
}

string VfsListCommand::usage()
{
	return ("list full-path");
}

//========================================================================

VfsDeleteCommand::VfsDeleteCommand( VfsRepository* repo, string arg1 ) :
	VfsCommand(repo, "delete", arg1, string(""))
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



