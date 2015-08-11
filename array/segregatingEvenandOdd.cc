#include<iostream>

using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void printArray(int a[],int size){
	for(int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << "\n";
}

void segregateEvenandOdd(int a[], int size){
	int start = 0;
	int end = size - 1;
	//cout << start << "  " << end << endl;
	while(start < end){
		//cout << "hello\n";
		while(a[start] % 2 == 0)
			start++;
		while(a[end] % 2 != 0)
			end--;
		//if(start > end)
			//break;
		swap(a[start],a[end]);
		start++;
		end--;
		//printArray(a,size);
	}
	cout << "done\n";
}

int main(){
	int input[] = {1,3,5,7,2,4,6,8};
	int size = sizeof(input)/sizeof(input[0]);
	segregateEvenandOdd(input,size);
	printArray(input,size);
	return 0;
}
