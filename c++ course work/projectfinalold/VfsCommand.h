// VfsCommand
#include <string>

using namespace std;

class VfsRepository;

class VfsCommand{
protected:
	string command;
	string param1;
	string param2;
	VfsRepository *repo;
public:
	static VfsCommand *getVfsCommand( string cmdline, VfsRepository *repo );

	VfsCommand(VfsRepository *repo, const char *command, string arg1, string arg2);
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
	VfsCreateCommand( VfsRepository *repo, string arg1, string arg2);
	virtual string usage();
	virtual int doCommand();
};

class VfsOpenCommand : public VfsCommand{
public:
	VfsOpenCommand( VfsRepository *repo, string arg1, string arg2  );
	virtual string usage();
	virtual int doCommand();
};

class VfsCloseCommand : public VfsCommand{
public:
	VfsCloseCommand(VfsRepository *repo);
	virtual string usage();
	virtual int doCommand();
};

class VfsMakeDirCommand : public VfsCommand{
public:
	VfsMakeDirCommand( VfsRepository *repo, string arg1 );
	virtual string usage();
	virtual int doCommand();
};

class VfsCopyCommand : public VfsCommand{
public:
	VfsCopyCommand( VfsRepository *repo, string arg1, string arg2);
	virtual string usage();
	virtual int doCommand();
};

class VfsMoveCommand : public VfsCommand{
public:
	VfsMoveCommand( VfsRepository *repo, string arg1, string arg2);
	virtual string usage();
	virtual int doCommand();
};

class VfsCatCommand : public VfsCommand{
public:
	VfsCatCommand( VfsRepository *repo, string arg1 );
	virtual string usage();
	virtual int doCommand();
};

class VfsListCommand : public VfsCommand{
public:
	VfsListCommand( VfsRepository *repo, string arg1 );
	virtual string usage();
	virtual int doCommand();
};

class VfsDeleteCommand : public VfsCommand{
public:
	VfsDeleteCommand( VfsRepository *repo, string arg1 );
	virtual string usage();
	virtual int doCommand();
};

