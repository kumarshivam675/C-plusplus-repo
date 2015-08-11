#include<iostream>

using namespace std;

int main(){
	int x = 4,y;
	void *p = &x;
	double z = 3.14;
	*p = *(&z);
	y = x + z;
	cout << y << "\n" << p;
	return 0;
}
