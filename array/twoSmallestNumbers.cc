#include<iostream>
#include<climits>

using namespace std;

void twoSmallestNumber(int a[], int size){
	int small_first = INT_MAX, small_second = INT_MAX;
	for(int i = 0; i < size; i++){
		if(a[i] < small_first){
			small_second = small_first;
			small_first = a[i];
		}
		else if(a[i] < small_second){
			small_second = a[i];
		}
	}
	cout << small_first << "  " << small_second << endl;
}

int main(){
	int input[] = {10,20,1,5,7};
	int size = sizeof(input)/sizeof(input[0]);
	twoSmallestNumber(input,size);
	return 0;
}
		
