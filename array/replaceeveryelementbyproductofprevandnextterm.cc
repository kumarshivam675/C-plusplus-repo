#include<iostream>

using namespace std;

int main(){
	int input[] = {2,3,4,5,6};
	int *ans;
	int size = sizeof(input)/sizeof(input[0]);
	ans = new int[size];
	for(int i = 0; i < size; i++){
		if(i == 0)
			ans[0] = input[0]*input[1];
		else if(i == size-1)
			ans[i] = input[i]*input[i-1];
		else
			ans[i] = input[i-1]*input[i+1];
	}
	for(int i = 0; i < size; i++)
		cout << ans[i] << "  ";
	cout << "\n";
	return 0;
}
