#include<iostream>
#include<algorithm>

using namespace std;

void reversal(int a[],int d,int size){
	cout << sizeof(a) << endl;
	reverse(a,a+d);
	reverse(a+d,a+size);
	reverse(a,a+size);
	for(int i = 0; i < size; i++)
		cout << a[i] << "  ";
	cout << "\n";
}

int main(){
	int input[] = {1,2,3,4,5,6,7,8,9,10};
	int size = sizeof(input)/sizeof(input[0]);
	reversal(input,2,size);
}

