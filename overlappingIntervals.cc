#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Coordinate{
	int x;
	int y;
};

bool compare(Coordinate &a, Coordinate &b){
	return a.x < b.x;
}

void checkOverlap(vector<Coordinate> coord){
	vector<Coordinate>::iterator it;
	sort(coord.begin(),coord.end(),compare);
	
	for(it = coord.begin(); it != coord.end(); it++)
		cout << (*it).x << " " << (*it).y << endl;	
	
	int i = 1;	
	cout << "the answer is\n\n";
	int start = coord[0].x;
	int end = coord[0].y;
	while(i < coord.size()){
		while(end >= coord[i].x && i < coord.size()){
			end = max(coord[i].y,end);
			i++;
		}
		cout << start << " " << end << endl;
		start = coord[i].x;
		end = coord[i].y;
	}
	//cout << coord[coord.size()-1].x << " " << coord[coord.size()-1].y << endl;
}


int main(){
	vector<Coordinate> coord;
	int size;
	cin >> size;
	while(size--){
		struct Coordinate c;
		cin >> c.x;
		cin >> c.y;
		coord.push_back(c);
	}
	checkOverlap(coord);
	return 0;
}
