#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	int edge = sum/2;
	if(edge == n-1)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
	
		
		
