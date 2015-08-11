// Program to demonstrate the following:
// a) reading commandline arguments
// b) Basic I/O using standard library
// c) How to read line-by-line from standard input

#include<cstdlib>
#include<iostream>

using namespace std;

int main(int argc, char *argv[])
{
	if( argc != 2 ){
		cout << "Usage: " << argv[0] << " input-string" << endl;
		exit(1);
	}
	
	string search_string = argv[1];
	
	string line;
	while( getline(cin, line) ){
		cout << "Line read: " << line << endl;
	}
}
