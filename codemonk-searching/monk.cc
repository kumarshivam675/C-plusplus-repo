#include <iostream>
using namespace std;

int main()
{
	long long int input,max,monk,size;
	cin >> input;
	for(long long int i = 0; i < input; i++){
		monk = 0;
		max = 0;
		cin >> size;
		long long int *arr1,*arr2;
		arr1 = new long long int[size];
		arr2 = new long long int[size];
		for(long long int j = 0; j < size; j++)
			cin >> arr1[j];
		for(long long int j = 0; j < size; j++)
			cin >> arr2[j];
			
		long long int it1 = 0,it2 = 0;
		//cout << size << endl;
		while(it1 < size && it2 < size){
			if(arr1[it1] <= arr2[it2]){
				//cout << "hello\n";
				monk = it2 -it1;
				it2++;
			}
			else
				it1++;
				
			if(monk > max){
					//cout << "updating\n";
					max = monk;
				}
		
		}
		cout << max << endl;
	}
    return 0;
}

