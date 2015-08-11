#include<iostream>
#include<vector>

using namespace std;

int main(){
	int size;
	cin >> size;
	vector<int> v;
	int value;
	char s;
	cin >> value;
	v.push_back(value);
	size--;
	while(cin >> s >> value && s == ',' && size>0){
		v.push_back(value);
		size--;
		if(size == 0)
			break;
	}
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	return 0;
}
