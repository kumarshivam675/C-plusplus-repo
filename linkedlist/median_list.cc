#include<iostream>
#include<list>
#include<iomanip>

using namespace std;

int main(){
	list<int> mylist;
	list<int>::iterator it;
	list<int>::iterator middle;
	int input,value;
	cin >> input;
	for(int i = 0; i < input; i++){
		cin >> value;
		it = mylist.begin();
		while(*it < value)
			it++;
		mylist.insert(it,value);
		if(i == 0)
			middle = mylist.begin();
		if(mylist.size()%2 == 0){
			if(*middle > value)
				middle--;
		}
		else{
			if(*middle < value)
				middle++;
		}
		if(mylist.size()&1)
			cout << fixed << setprecision(1) << float(*middle) << endl;
		else{
			int temp  =*middle;
			middle++;
			cout << fixed << setprecision(1) << float(temp + *middle)/2 << endl;
			middle--;
		}
	}
	//for(it = mylist.begin(); it != mylist.end(); it++)
	//	cout << *it << endl;
	return 0;
}
