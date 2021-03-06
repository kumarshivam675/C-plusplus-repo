#include "VfsRepository.h"
#include "VfsNodeInfo.h"
#include "VfsFolderInfo.h"
#include "VfsFileInfo.h"
#include "PathString.h"
#include<cstring>
#include<sstream>

using namespace std;

VfsRepository::VfsRepository(){

}

VfsRepository::VfsRepository(string reponame,string extern_path){
	repo_name = reponame;
	repo_file_path = extern_path;
} 

void VfsRepository::create(string reponame, string repo_file_path){
	num_nodes = 0;
	fstream fout;
	fout.open(repo_file_path, ios::out | ios::binary);
	fout.write((char*)&num_nodes, sizeof(int));
	HeaderRecord header;
	for(int i = 0; i < MAX_NODES; i++)
		fout.write((char*)&header, sizeof(HeaderRecord));
	fout.close();
}

void VfsRepository::open(string reponame, std::string repo_file_path){
	fstream fin;
	HeaderRecord header;
	fin.open(repo_file_path, ios::in | ios::binary);
	if( !fin.good() ){
		cout << "Stream not good " << endl;
		//exit(1);
	}
	fin.read((char*)&num_nodes, sizeof(int));
	for(int i = 0; i < num_nodes; i++){
		fin.read((char*)&header, sizeof(HeaderRecord));
		string temp(header.node_name);
		if(header.node_type == 1){
			string temp_path(header.folder_path);
			VfsFolderInfo* folder = new VfsFolderInfo(temp,temp_path);
			vfsmap[temp]= folder;
		}
		
		else{
			VfsFileInfo* file = new VfsFileInfo(temp,header.size, header.offset);
			vfsmap[temp] = file;
		}
	}
	fin.close();
}

void VfsRepository::close(){
	fstream fout;
	fout.open("demo.vfs", ios::out | ios::binary);
	fout.seekp(0,ios::beg);
	num_nodes = vfsmap.size();
	//cout << "numnodes " << num_nodes << endl;
	fout.write((char*)&num_nodes, sizeof(int));
	map<string, VfsNodeInfo*>::iterator it;
	for(it = vfsmap.begin(); it != vfsmap.end(); it++){
		HeaderRecord header;
		strcpy(header.node_name, it->second->get_nodename().c_str());
		strcpy(header.folder_path, it->first.c_str());
		it->second->getHeader(header);
		fout.write((char*)&header, sizeof(HeaderRecord));
	}
	
	int rem_header = MAX_NODES - num_nodes;
	HeaderRecord header1;
	for(int i = 0; i < rem_header; i++)
		fout.write((char*)&header1, sizeof(HeaderRecord));
	fout.close();
	
}


void VfsRepository::makeDir(string path, string folder_name){
	stringstream str, str_folderpath;
	//str_folderpath << path << "/";
	str << path <<"/" << folder_name;
	string finalpath = str.str();
	//string folderpath = str_folderpath.str();
	map<string, VfsNodeInfo*>::iterator it;
	it = vfsmap.find(path);
	if(it != vfsmap.end()){
		VfsFolderInfo* f = new VfsFolderInfo(folder_name, finalpath);
		vfsmap[finalpath] = f;
		//cout << "parent \t foldername" << parent << folder_name << endl;
		dynamic_cast<VfsFolderInfo*>(it->second)->addChild(f);
		//it->second->addChild(f);
		f->setParent(dynamic_cast<VfsFolderInfo*>(it->second));
		//f->setParent(it->second);
	}
	
	else if(path ==""){
		VfsFolderInfo* f = new VfsFolderInfo(folder_name, "/");
		vfsmap[""] = f;
		//cout << "parent1 \t foldername" << parent << folder_name << endl;
		//dynamic_cast<VfsFolderInfo*>(it->second)->addChild(f);
		//it->second->addChild(f);
		//f->setParent(dynamic_cast<VfsFolderInfo*>(it->second));
		//f->setParent(it->second);
	}
}

void VfsRepository::list(string path, vector<string> &content){
	//PathString p(path,"/"); 
	//string parent = p.excludeLast();
	//cout <<"parent string" << parent << endl;
	if(path == "/")
		path = "";
	map<string, VfsNodeInfo*>::iterator it;
	it = vfsmap.find(path);
	if(it != vfsmap.end()){
		//cout << "parentstringfound\n";
		dynamic_cast<VfsFolderInfo*>(it->second)->printChild(content);
		//for(int i = 0; i < content.size(); i++)
		//	cout <<"helloagain \t" << content[i]<<endl;
	}
}
	
	
	
	
	
	
