#include<iostream>
#include<vector>
#include<map>

using namespace std;

void countCollision(int a[], int size){
	map<int,int> myMap;
	map<int,int>::iterator it;
	int count = 0;
	for(int i = 0; i < size; i++){
		int x = a[i]%10;
		myMap[x] += 1;
	}
	for(it = myMap.begin(); it != myMap.end(); it++){
		count += (it->second - 1);
		//cout << it->first << "  " << it->second << endl;
	}
	cout << count << endl;

}

int main(){
	int size,input;
	cin >> input;
	for(int i = 0; i < input; i++){
		int *a;
		cin >> size;
		a = new int[size];
		for(int j = 0; j < size;j++)
			cin >> a[j];
		countCollision(a,size);
	}
	return 0;
}
