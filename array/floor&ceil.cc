#include<iostream>

using namespace std;

void floorceil(int a[], int size, int key){
	int start = 0;
	int end = size - 1;
	int floor = -1, ceil = -1;
	while(start <= end){
		int mid = (start + end)/2;
		if(a[mid] == key){
			floor = key;	
			ceil = key;
			break;
		}
		if(a[mid] < key){
			floor = a[mid];
			start = mid + 1;
		}
		else if(a[mid] > key){
			ceil = a[mid];
			end = mid - 1;
		}
	}
	cout << floor << "  " << ceil << endl;
}

int main(){
	int input[] = {1,3,5,6,9,12,13};
	int size = sizeof(input)/sizeof(input[0]);
	floorceil(input,size,10);
	return 0;
}
