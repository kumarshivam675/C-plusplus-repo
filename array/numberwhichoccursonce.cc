#include<iostream>

using namespace std;

int main(){
	int input[] = {7,3,5,4,5,3,4};
	int size = sizeof(input)/sizeof(input[0]);
	int x = input[0];
	for(int i = 1; i < size; i++)
		x = x ^ input[i];
	cout << x << endl;
	return 0;
}
		
