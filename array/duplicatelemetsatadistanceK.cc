#include<iostream>
#include<map>

using namespace std;

/*bool findDuplicate(int a[], int size, int k){
	int *ans;
	ans = new int[20];
	for(int i = 0; i < 20; i++)
		ans[i] = -1;
	for(int i = 0; i < size;i++){
		if(ans[a[i]] == 1)
			return true;
		ans[a[i]] = 1;
		if(i >= k)
			ans[a[i-k]] = -1;
		}
	return false;
}*/

bool findDulpicate(int a[], int size, int k){
	map<int, int> mymap;
	
	for(int i = 0; i < k; i++)
		mymap[a[i]] = 1;
	for(int i = k; i < size; i++){
		if(mymap[a[i]])
			return true;
		mymap[a[i]] = 1;
		mymap.erase(a[i-k]);
	}
	return false;
}

int main(){
	int input[] = {1,2,3,1,2};
	int size = sizeof(input)/sizeof(input[0]);
	cout << findDulpicate(input,size,3) << endl;
	return 0;
}
	
