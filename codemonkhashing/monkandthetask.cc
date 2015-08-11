#include <bitset>
#include <iostream>
#include <climits>
#include<vector>
#include<map>

using namespace std;

size_t popcount(size_t n) {
    std::bitset<sizeof(size_t) * CHAR_BIT> b(n);
    return b.count();
}

void printOrder(){
	int size;
	map<int, vector<long long int> > myMap;
	map<int , vector<long long int> >::iterator it;
	vector<long long int>::iterator it1;
	long long int value;
	cin >> size;
	for(int i = 0; i < size; i++){
		cin >> value;
		int number = popcount(value);
		myMap[number].push_back(value);
	}
	for(it = myMap.begin(); it != myMap.end(); it++){
		for(it1 = it->second.begin(); it1 != it->second.end(); it1++)
			cout << *it1 << " ";
	}
	//cout << endl;
}

int main() {
    int input;
    cin >> input;
    for(int i = 0; i < input; i++)
    	printOrder();
}
