#include<iostream>

using namespace std;

void unSortedSubarray(int a[],int size){
	int l,r,left_index,right_index;
	for(int i = 0; i < size - 2; i++){
		if(a[i+1] < a[i]){
			l = i;
			break;
		}
	}
	for(int i = size - 1;i > 0; i--){
		if(a[i] < a[i-1]){
			r = i;
			break;
		}
	}
	left_index = l;
	right_index = r;
	cout << l << "  " << r << endl;
	int min = a[l];
	int max = a[r];
	for(int i = l; i <= r; i++){
		if(a[i] < min)
			min = a[i];
		if(a[i] > max)
			max = a[i];
	}
	cout << min << "  " << max << endl;
	for(int i = 0; i < l; i++){
		if(a[i] > min)
			left_index = i;
	}
	for(int i = r; i < size - 1; i++){
		if(a[i] < max)
			right_index = i;
	}
	cout << left_index << "  " << right_index << endl;
}
			

int main(){
	//int input[] = {0,1,15,25,6,7,30,40,50};
	int input[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int size = sizeof(input)/sizeof(input[0]);
	unSortedSubarray(input,size);
	return 0;
}
	
	
