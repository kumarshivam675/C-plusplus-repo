#include<iostream>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void sort012(int a[], int size){
	int low = 0;
	int mid = 0;
	int high = size - 1;
	while(mid <= high){
		if(a[mid] == 0){
			swap(a[low],a[mid]);
			low++;
			mid++;
		}
		else if(a[mid] == 1)
			mid++;
		else{
			swap(a[high],a[mid]);
			high--;
		}
	}
	for(int i = 0; i < size; i++)
		cout << a[i] << "  ";
	cout << "\n";
}

int main(){
	int input[] = {2,2,2,2,1,2,1,1,0,1};
	int size = sizeof(input)/sizeof(input[0]);
	sort012(input,size);
}
