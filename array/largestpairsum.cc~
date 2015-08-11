#include<iostream>

using namespace std;

void largestPairSum(int a[], int size){
	int largest1 = a[0];
	int largest2 = a[0];
	for(int i = 1; i < size; i++){
		if(a[i] > largest1){
			largest2 = largest1;
			largest1 = a[i];
		}
		else if(a[i] > largest2)
			largest2 = a[i];
	}
	cout << largest1 + largest2 << endl;
}

int main(){
	int input[] = {12,34,10,6,40,80,79};
	int size = sizeof(input)/sizeof(input[0]);
	largestPairSum(input,size);
	return 0;
}
