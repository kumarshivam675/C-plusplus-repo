#include<iostream>

using namespace std;

int binarySearch(int a[], int size, int key){
	int start = 0;
	int end = size - 1;
	while(start <= end){
		int mid = (start + end)/2;
		if(a[mid] == key){
			int i = mid;
			while(a[i] == a[mid])
				i--;
			return i+1;
		}
		if(a[mid] > key)
			end = mid - 1;
		else if(a[mid] < key)
			start = mid + 1;
	}
	return -1;
}

int majorityElement(int a[], int size, int key){
	int start = binarySearch(a,size,key);
	int last = start + size/2;
	if(a[start] == a[last])
		return 1;
	else 
		return 0;
}

int main(){
	int input[] = {1,2,3,3,3,3,10};
	int size = sizeof(input)/sizeof(input[0]);
	cout << majorityElement(input,size,2) << endl;
	return 0;
}
