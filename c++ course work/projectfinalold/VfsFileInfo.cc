#include "VfsFileInfo.h"
#include "VfsFile.h"
#include "VfsFolderInfo.h"
#include "VfsRepository.h"

using namespace std;

VfsFileInfo::VfsFileInfo(){
	//VfsNodeInfo();
}

VfsFileInfo::VfsFileInfo(string nodename,long filesbytes, int fileoffset): VfsNodeInfo(nodename){
	//VfsNodeInfo(nodename);
	file_bytes = filesbytes;
	file_offset = fileoffset;
}

void VfsFileInfo::getHeader(HeaderRecord& header){
	header.offset = file_offset;
	header.size = file_bytes;
	header.node_type = 0;
}

int VfsFileInfo::get_nodetype(){
	return 0;
}
