#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

void PythagoreanTriplet(int a[],int size){
	for(int i = 0; i < size; i++)
		a[i] = a[i]*a[i];
	sort(a,a+size);
	for(int i = size-1; i >= 0; i--){
		int l = 0;
		int r = i-1;	
		while(l < r){
			if(a[i] == a[l] + a[r]){
				//cout << i << "  " << l << "  " << r << endl;
				cout << sqrt(a[l]) << "  " << sqrt(a[r]) << "  " << sqrt(a[i]) << endl;
				return ;
			}
			else if(a[l] + a[r] < a[i])
				l++;
			else
				r--;
		}
	}
}

int main(){
	int input[] = {3,1,4,5,6};
	int size = sizeof(input)/sizeof(input[0]);
	PythagoreanTriplet(input,size);
	return 0;
}
