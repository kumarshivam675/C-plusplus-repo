#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int filepos1 = 0;
int filepos2 = 0;
int file1_bytes;
int file2_bytes;

int store(){
		string container = "container.bin";
		string f1 = "iodemo.bin";
		string f2 = "train.bin";
		char buffer[10240];
		fstream fin, fout;
		fout.open(container, ios::out | ios:: binary);
		fin.open(f1, ios::in | ios::binary);
		fin.read(buffer,10240);
		file1_bytes = fin.gcount();
		cout << file1_bytes << endl;
		fout.write(buffer, file1_bytes);
		fin.close();
		filepos2 = fout.tellp();
		fin.open(f2,ios::in | ios::binary);
		fin.read(buffer, 10240);
		file2_bytes = fin.gcount();
		fout.write(buffer, file2_bytes);
		fin.close();
		fout.close();
}

			
void retrieve(int file){
		char buffer1[10240];
		string anothercontainer = "anothercontainer.bin";
		fstream fin, fout;
		fin.open("container.bin",ios::in | ios::binary);
		fout.open(anothercontainer, ios::out | ios::binary);
		if(file == 1){
			fin.seekg(0,ios::beg);
			cout << file1_bytes << endl;
			fin.read(buffer1, file1_bytes);
			int filesize = fin.gcount();
			fout.write(buffer1, file1_bytes);
			fin.close();
			fout.close();
		}
		
		else{
			fin.seekg(filepos1,ios::beg);
			fin.read(buffer1, file2_bytes);
			int filesize = fin.gcount();
			fout.write(buffer1, filesize);
			fin.close();
			fout.close();
		}
}
		
			
		

main()
{
	store();
	retrieve(1);
}
		

		
