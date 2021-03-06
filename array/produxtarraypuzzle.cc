#include<iostream>

using namespace std;

void computeProduct(int a[], int size){
	int *prod;
	prod = new int[size];
	int temp = a[0];
	prod[0] = 1;
	for(int i = 1; i < size; i++){
		prod[i] = temp;
		temp = temp*a[i];
	}
	for(int i = 0; i < size; i++)
		cout << prod[i] << "  ";
	cout << "\n";
	temp = a[size-1];
	for(int i = size-2; i >= 0;i--){
		prod[i] *= temp;
		temp = temp * a[i];
	}
	for(int i = 0; i < size; i++)
		cout << prod[i] << "  ";
	cout << "\n";
}

int main(){
	int input[] = {10,3,5,6,2};
	int size = sizeof(input)/sizeof(input[0]);
	computeProduct(input,size);
	return 0;
}
