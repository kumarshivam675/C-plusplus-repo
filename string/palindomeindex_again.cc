#include<iostream>

using namespace std;

void findIndex(string str){
	map<char,int> myMap;
	map<char,int>::iterator it;
	for(int i = 0; i < str.length(); i++){
		myMap[str[i]] += 1;
	}

int main(){
	string str;
	int size;
	while(size--){
		cin >> str;
		findIndex(str);
	}
	return 0;
}
