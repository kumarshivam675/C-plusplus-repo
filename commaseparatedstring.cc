#include<iostream>
#include<vector>
#include<sstream>

using namespace std;


void commaseparatedstring(){
	string input = "10,12,45,54";
	stringstream ss(input);
	string token;

	while(getline(ss, token, ',')) {
		cout << token << '\n';
	}
}



int main(){
	commaseparatedstring();
	return 0;
}
