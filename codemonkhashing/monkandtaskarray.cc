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
	int size,number;
	long long int value;
	vector<long long int> array[61];
	vector<long long int>::iterator it;
	cin >> size;
	for(int i = 0; i < size; i++){
		cin >> value;
		number = popcount(value);
		array[number].push_back(value);
	}
	
	for(int i = 0; i < 61; i++){
		for(it = array[i].begin(); it != array[i].end(); it++)
			cout << *it << " ";
	}
}

int main() {
    int input;
    cin >> input;
    for(int i = 0; i < input; i++)
    	printOrder();
}
