#include<iostream>
#include<fstream>
#include<cstdlib>
#include <sys/stat.h>

using namespace std;

int file1pos = 0, file1_bytes;
int file2pos = 0, file2_bytes;
string f1 = "/usr/include/string.h"; // Some sample text file
string f2 = "/usr/bin/yes"; // some sample binary file

void writefiles();
void readfile(int whichone);

/*
This is a demonstration program for binary IO that does the following:
1. Create a binary container file called container.bin
2. Add two samples files into that container (/usr/include/string.h and /usr/bin/yes)
3. Extract each file individually from instide the container and store it in the current directory

When you finish running the program, you will see the following files in your current directory:
-rwxrwxrwx 1 rc rc 49721 Feb  3 10:32 container.bin
-rwxrwxrwx 1 rc rc 22521 Feb  3 10:32 file1copy.bin
-rwxrwxrwx 1 rc rc 27200 Feb  3 10:32 file2copy.bin

*/

main()
{
	writefiles();
	readfile(2);
	readfile(1);
}

void writefiles()
{
	char buffer[102400];
	struct stat buf;

	// Open containter file in output binary mode
	fstream constr;
	string container = "container.bin";

	// Just create the file using output mode if it does not exist
	constr.open(container, ios::out | ios::binary);
	// Close and reopen file in input / ooutput mode
	constr.close();
	constr.open(container, ios::in | ios::out | ios::binary);

	if( !constr.good() ){
		cout << "Stream not good " << endl;
		exit(1);
	}

	// Open f1 in read binary mode
	fstream f1str;
	f1str.open(f1, ios::in | ios::binary);
	stat(f1.c_str(), &buf);
	file1_bytes = buf.st_size;

	file1pos = 0;
	// Read the data from f1str
	f1str.read(buffer,file1_bytes);
	
	// Store buffer data into container
	constr.write(buffer,file1_bytes);
	file2pos = constr.tellp();
	
	// Repeat with the second file
	// Read the data from f2str
	fstream f2str;
	f2str.open(f2, ios::in | ios::binary);
	stat(f2.c_str(), &buf);
	file2_bytes = buf.st_size;

	f2str.read(buffer,file2_bytes);
	
	// Store buffer data into container
	constr.write(buffer,file2_bytes);

	// Close the file
	f1str.close();
	f2str.close();
	constr.close();
}


void readfile( int whichone )
{
	int bytestoread, pos;
	string ofname;

	if( whichone == 1 ){
		pos = file1pos;
		bytestoread = file1_bytes;
		
		// Name of the external file into which the read data is going to be stored
		ofname = "file1copy.bin";
	}
	else{
		pos = file2pos;
		bytestoread = file2_bytes;
		
		// Name of the external file into which the read data is going to be stored
		ofname = "file2copy.bin";
	}

	string container = "container.bin";
	fstream constr;

	constr.open(container, ios::in | ios::binary);

	fstream ofstr;
	char buffer[102400];

	cout << "Creating " << ofname << endl;

	ofstr.open(ofname, ios::out | ios::binary);
	constr.read(buffer,bytestoread);
	ofstr.write(buffer,bytestoread);

	// Close the files
	constr.close();
	ofstr.close();
}

