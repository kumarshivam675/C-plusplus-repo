#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

void findMinDiff(long int a[], int size){
	sort(a,a+size);
	int min = INT_MAX;
	for(int i = 1; i < size; i++){
		if(a[i] - a[i-1] < min && a[i] != a[i-1])
			min = a[i] - a[i-1];
	}
	for(int i = 1; i < size;i++){
		if(a[i] - a[i-1] == min)
			cout << a[i-1]	<< " " << a[i] << " ";
	}
}

int main(){
	int size;
	cin >> size;
	long int a[size];
	for(int i = 0; i < size; i++)
		cin >> a[i];
	findMinDiff(a,size);
	return 0;
}
