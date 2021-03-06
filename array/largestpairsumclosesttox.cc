#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

void findSum(int a[], int size, int sum){
	int l = 0,x,y;
	int r = size - 1;
	int temp_sum, closest_sum = INT_MAX;
	while(l < r){
		temp_sum = a[l] + a[r];
		//cout << "temp_sum " << temp_sum << endl;
		//cout << "compare " << abs(temp_sum - sum) << endl;
		if(abs(temp_sum - sum) < closest_sum){
			closest_sum = abs(temp_sum - sum);
			x = a[l];
			y = a[r];
		}
		if(a[l] + a[r] < sum)
			l++;
		else
			r--;
		//cout << "closest " << closest_sum << endl;
	}
	cout << x << "  " << y << endl;
}

int main(){
	int input[] = {10,22,28,29,30,40};
	int size = sizeof(input)/sizeof(input[0]);
	findSum(input,size,54);
	return 0;
}
		
