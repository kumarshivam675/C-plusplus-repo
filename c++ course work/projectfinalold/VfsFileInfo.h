//VfsFileInfo

#ifndef VFSFILEINFO_H
#define VFSFILEINFO_H

#include "VfsNodeInfo.h"

class VfsFile;
class VfsFolderInfo;
struct HeaderRecord;

class VfsFileInfo:public VfsNodeInfo{
	long file_bytes;
	int file_offset;
	VfsFile* vfsfile;
	VfsFolderInfo* vfsfolder;
public:
	virtual void getHeader(HeaderRecord& header);
	VfsFileInfo();
	VfsFileInfo(std::string nodename,long filesbytes, int fileoffset);
	int get_nodetype();
};

#endif
