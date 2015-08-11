#include<iostream>

using namespace std;

void findMissingSum(int a[],int size){
	int sum = (size+1)*(size+2)/2;
	for(int i = 0; i < size; i++)
		sum = sum - a[i];
	cout << "the missing number is " << sum << endl;
}

int main(){
	int input[] = {1,2,5,6,3,7,8};
	int size = sizeof(input)/sizeof(input[0]);
	findMissingSum(input,size);
	return 0;
}
