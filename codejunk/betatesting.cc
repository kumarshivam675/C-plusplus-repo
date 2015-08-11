#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main(){
	int size;
	map<string,int> mymap;
	map<string,int>::iterator it;
	//map<int,string> reversemap;
	map<string,int>::reverse_iterator itt;
	cin >> size;
	//map<int,string>::iterator it1;
	string str;
	for(int i = 0; i < size; i++){
		cin >> str;
		mymap[str] += 1;
	}
	for(it = mymap.begin(); it != mymap.end(); it++){
		cout << "printing1 " << it->first << "  " << it->second << endl;

	}
	for(itt = mymap.rbegin(); itt != mymap.rend(); itt++){
		cout << "printing " << itt->first << "  " << itt->second << endl;

	}
	
	return 0;
}
	
	
