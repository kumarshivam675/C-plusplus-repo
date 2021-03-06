#include<iostream>
#include<algorithm>

using namespace std;

void findMedian(int a[], int b[], int size){
	int median;
	int a_start = 0,b_start = 0;
	int a_end = size - 1, b_end = size - 1;
	while(a_start <= a_end && b_start <= b_end){
		int a_mid = (a_start + a_end)/2;
		int b_mid = (b_start + b_end)/2;
		cout << "a's coordinates " << a_start << "  " << a_end << "  " << a_mid << endl;
		cout << "b's coordinates " << b_start << "  " << b_end << "  " << b_mid << endl;
		if(a[a_mid] == b[b_mid]){
			median = a[a_mid];
			break;
		}
		if(a[a_mid] < b[b_mid]){
			a_start =  a_mid;
			b_end = b_mid;
		}
		else if(b[b_mid] < a[a_mid]){
			b_start = b_mid;
			a_end = a_mid;
		}
		if(a_end - a_start <= 1 && b_start - b_end <= 1){
			median = (max(a[a_start],b[b_start]) + min(a[a_end],b[b_end]))/2;
			break;
		}
	}
	cout << median << endl;
}	

int main(){
	int a[] = {1,2,3,4,5};
	int b[] = {7,8,9,10,11};
	int size = sizeof(a)/sizeof(a[0]);
	findMedian(a,b,size);
	return 0;
}
		
