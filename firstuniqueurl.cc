#include<iostream>
#include<map>
#include<vector>

const int m = 101;

using namespace std;

void findUnique(string a[], int size){
	int index = size-1;
	map<int, vector<string> > myMap;
	vector<string>::iterator it;
	for(int i = size-1; i >= 0; i--){
		int sum = 0, flag = 0;
		for(int j = 0; j < a[i].length(); j++)
			sum += a[i][j];
		sum = sum%m;
		if(myMap.find(sum) != myMap.end()){
			cout << "found\n";
			for(it = myMap[sum].begin(); it != myMap[sum].end(); it++){
				if(*it == a[i])
					flag = 1;
			}
			if(flag == 0){
				index = i;
			}
			
		}
		else{
			myMap[sum].push_back(a[i]);
			index = i;
		}
		cout << "i is " << i << " and index is " << index << endl;
	}
	cout << index << endl;
}

int main(){
	string s[] = {"a.com", "b.com","c.com", "a.com", "b.com", "d.com","c.com"};
	int size = sizeof(s)/sizeof(s[0]);
	cout << size << endl;
	findUnique(s,size);
	return 0;
}
