// VfsCommand
#include <string>

using namespace std;

class VfsCommand{
protected:
	string command;
	string param1;
	string param2;
public:
	static VfsCommand *getVfsCommand( string cmdline );

	VfsCommand(const char *command, string arg1, string arg2);
	virtual string usage() = 0; // Pure virtual function
	virtual int doCommand() = 0; // Pure virtual function
};

class VfsInvalidCommand : public VfsCommand{
public:
	VfsInvalidCommand();
	virtual string usage();
	virtual int doCommand();
};

class VfsCreateCommand : public VfsCommand{
public:
	VfsCreateCommand( string arg1, string arg2);
	virtual string usage();
	virtual int doCommand();
};

class VfsOpenCommand : public VfsCommand{
public:
	VfsOpenCommand( string arg1 );
	virtual string usage();
	virtual int doCommand();
};

class VfsCloseCommand : public VfsCommand{
public:
	VfsCloseCommand();
	virtual string usage();
	virtual int doCommand();
};

class VfsMakeDirCommand : public VfsCommand{
public:
	VfsMakeDirCommand( string arg1 );
	virtual string usage();
	virtual int doCommand();
};

class VfsCopyCommand : public VfsCommand{
public:
	VfsCopyCommand( string arg1, string arg2);
	virtual string usage();
	virtual int doCommand();
};

class VfsMoveCommand : public VfsCommand{
public:
	VfsMoveCommand( string arg1, string arg2);
	virtual string usage();
	virtual int doCommand();
};

class VfsCatCommand : public VfsCommand{
public:
	VfsCatCommand( string arg1 );
	virtual string usage();
	virtual int doCommand();
};

class VfsListCommand : public VfsCommand{
public:
	VfsListCommand( string arg1 );
	virtual string usage();
	virtual int doCommand();
};

class VfsDeleteCommand : public VfsCommand{
public:
	VfsDeleteCommand( string arg1 );
	virtual string usage();
	virtual int doCommand();
};

