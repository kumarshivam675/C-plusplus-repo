//VfsFolderInfo

#ifndef VFSFOLDERINFO_H
#define VFSFOLDERINFO_H

#include "VfsNodeInfo.h"

#include<string>
#include<vector>
#include<cstring>
#include<sstream>

class VfsFileInfo;
struct HeaderRecord;

class VfsFolderInfo: public VfsNodeInfo{
	std::string node_path;
	std::vector<VfsFileInfo*> vfsfile;
	std::vector<VfsFolderInfo*> subfolder;
	VfsFolderInfo* parentfolder;
public:
	void getHeader(HeaderRecord& header);
	VfsFolderInfo(std::string nodename,std::string node_path);
	void addChild(VfsFolderInfo* f);
	void setParent(VfsFolderInfo* p);
	int get_nodetype();
	void printChild(std::vector<std::string> &content);
	std::string getPath();
	
};

#endif
