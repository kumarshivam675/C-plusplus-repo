#include<iostream>

using namespace std;

void findCeil(int a[], int size,int key){
	int ceil = -1, floor = -1,mid;
	int start = 0, end = size - 1;
	while(start <= end){
		mid = (start + end)/2;
		if(a[mid] == key){
			cout << a[mid] << "  " << a[mid] << endl;
			return ;
		}
		
		if(a[mid] > key){
			ceil = a[mid];
			end = mid - 1;
		}
		else if(a[mid] < key){
			floor = a[mid];
			start = start + 1;
		}
	}
	cout << ceil << "  " << floor << endl;
}

int main(){
	int input[] = {1,2,4,6,9,10,11};
	int size = sizeof(input)/sizeof(input[0]);
	findCeil(input,size,8);
	return 0;
}
	

