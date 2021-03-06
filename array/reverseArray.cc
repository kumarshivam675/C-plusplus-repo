#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void reverse(int a[], int size){
	int l = 0;
	int r = size - 1;
	while(l <= r){
		int temp = a[l];
		a[l] = a[r];
		a[r] = temp;
		l++;
		r--;
	}
	for(int i = 0; i < size; i++)
		cout << a[i] << "  ";
	cout << endl;
}

void reverseUsingVector(int size){
	vector<int> v;
	int input;
	for(int i = 0; i < size; i++){
		cin >> input;
		v.push_back(input);
	}
	reverse(v.begin(),v.end());
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << "  ";
	cout << "\n";
}

int main(){
	//int input[] = {1,2,3,4,5,6};
	//int size = sizeof(input)/sizeof(input[0]);
	//reverse(input,size);
	int size;
	cin >> size;
	reverseUsingVector(size);
	return 0;
}
