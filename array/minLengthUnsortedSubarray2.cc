#include<iostream>

using namespace std;

void findSubarray(int a[], int size){
	int l = 0;
	int r = size - 1;
	while(a[l] < a[l+1])
		l++;
	while(a[r] > a[r-1])
		r--;
	//cout << "first l and r " << l << "  " << r << endl;
	int min = a[l];
	int max = a[l];
	for(int i = l; i <= r; i++){
		if(a[i] < min)
			min = a[i];
		if(a[i] > max)
			max = a[i];
	}
	//cout << "min and max " << min << "  " << max << endl;
	for(int i = 0; i <= l; i++){
		if(a[i] > min){
			l = i;	
			break;
		}
	}
	for(int i = size-1; i >= r; i--){
		if(a[i] < max){
			r = i;
			break;
		}
	}
	cout << l << "  " << r << endl;
}

int main(){
	//int input[] = {10,12,20,30,25,40,32,31,35,50,60};
	int input[] = {0,1,15,25,6,7,30,40,50};
	int size = sizeof(input)/sizeof(input[0]);
	findSubarray(input,size);
	return 0;
}








