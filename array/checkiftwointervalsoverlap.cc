#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct interval{
	int start;
	int end;
};

bool compare(interval &i1, interval &i2){
	return (i1.start < i2.start) ? true:false ;
}

int main(){
	int size,start,end;
	cin >> size;
	vector<interval> vec;
	vector<interval>::iterator it;
	vector<interval>::iterator it_temp;
	while(size--){
		interval p;
		cin >> start >> end;
		p.start = start;
		p.end = end;
		vec.push_back(p);
	}
	sort(vec.begin(),vec.end(),compare);
	it = vec.begin();
	it++;
	it_temp = vec.begin();
	for(; it != vec.end(); it++){
		if((*it).start < (*it_temp).end){
			cout << "yes\n";
			return 0;
		}
		it_temp = it;
	}
	
	/*for(it = vec.begin(); it != vec.end(); it++)
		cout << (*it).start << "  " << (*it).end << endl;*/
	cout << "No\n";
	return 0;
}
