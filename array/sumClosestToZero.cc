#include<iostream>
#include<cmath>
#include<algorithm>
#include<climits>

using namespace std;

void minSumPair(int a[],int size){
	sort(a,a+size);
	//for(int i = 0; i < size; i++)
	//	cout << a[i] << " ";
	//cout << endl;
	int start = 0;
	int end = size - 1;
	int min_l,min_r;
	int min_sum = INT_MAX;
	while(start < end){
		int sum = a[start] + a[end];
		if(min_sum > abs(sum)){
			//cout << "start and end " << start << "  " << end << endl;
			min_sum = sum;
			min_l = start;
			min_r = end;
		}
		if(sum > 0)
			end--;
		else if(sum < 0)
			start++;
	}
	cout << "answer is " << a[min_l] << " " << a[min_r] << endl;
}

int main(){
	int input[] = {1,85,70,60,-10,-80};
	int size = sizeof(input)/sizeof(input[0]);
	minSumPair(input,size);
	return 0;
}
		
