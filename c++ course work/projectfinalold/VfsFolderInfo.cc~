#include "VfsFolderInfo.h"
#include "VfsFileInfo.h"
#include "VfsRepository.h"

using namespace std;

VfsFolderInfo::VfsFolderInfo(string nodename, string nodepath): VfsNodeInfo(nodename){
	node_path = nodepath;
}

void VfsFolderInfo::getHeader(HeaderRecord& header){
	//strcpy(header.node_name, get_nodename.c_str());
	header.node_type = 1;
}

void VfsFolderInfo::addChild(VfsFolderInfo* f){
	//cout << "addingchild\n";
	subfolder.push_back(f);
}

void VfsFolderInfo::setParent(VfsFolderInfo* p){
	//cout <<"settingparent\n";
	parentfolder = p;
}

int VfsFolderInfo::get_nodetype(){
	return 1;
}

void VfsFolderInfo::printChild(vector<string> &content){
	for(int i = 0; i < subfolder.size(); i++){
		/*string nodename = get_nodename();
		string folderpath = subfolder[i]->getPath();
		stringstream str;
		str << folderpath << nodename;
		string finalpath = str.str();*/
		//content.push_back(finalpath);
		content.push_back(subfolder[i]->getPath());
	}
	//for(int i = 0; i < content.size(); i++)
	//	cout <<"hello\t" <<content[i]<<endl;
}

string VfsFolderInfo::getPath(){
	return node_path;
}
