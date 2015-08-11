#include<iostream>

using namespace std;

void findNumberofTriangles(int a[], int size){
	int k, count = 0;
	for(int i = 0; i < size-2; i++){
		k = i+2;
		for(int j = i+1; j < size; j++){
			while(a[i] + a[j] > a[k] && k < size)
				k++;
				
			count += k-j-1;
			cout << i << "  " << j << "  " << k << "  " << count << endl;
		}
	}
	cout << count << endl;
}

int main(){
	int input[] = {3,4,6,7};
	//int input[] = {300,200,101,100,22,21,10};
	int size = sizeof(input)/sizeof(input[0]);
	findNumberofTriangles(input,size);
	return 0;
}
