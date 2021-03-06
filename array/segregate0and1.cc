#include<iostream>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void segregate(int a[], int size){
	int l = 0;
	int r = size - 1;
	while(l <= r){
		while(a[l] == 0)
			l++;
		while(a[r] != 0)
			r--;
		if(l > r)
			break;
		swap(a[l],a[r]);
		l++;
		r--;
	}
	for(int i = 0; i < size; i++)
		cout << a[i] << "  ";
	cout << "\n";
}

int main(){
	int input[] = {1,1,1,1,0,0,1,1,1,0};
	int size = sizeof(input)/sizeof(input[0]);
	segregate(input,size);
	return 0;
}
