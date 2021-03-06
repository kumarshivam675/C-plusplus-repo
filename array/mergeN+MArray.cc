#include<iostream>
#include<algorithm>

using namespace std;

void swap(int& a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void moveToEnd(int a[],int size){
	int l = 0;
	int r = size - 1;
	while(l<=r){
		while(a[l] == 0)
			l++;
		while(a[r] != 0)
			r--;
		if(l > r)
			break;
		swap(a[l],a[r]);
	}
}	

void merge(int a[], int b[],int n, int m){
	moveToEnd(b,m);
	int i = 0, j = 0;
	int index = m - n + 1;
	sort(b,b+m);
	while(i != n && index != m){
		if(a[i] < b[index]){
			b[j] = a[i];
			i++;
			j++;
		}
		else{
			b[j] = b[index];
			index++;
			j++;
		}	
	}
	while(i != n){
		b[j] = a[i];
		i++;
		j++;
	}
	while(index != m){
		b[j] = b[index];
		j++;
		index++;
	}
	
	for(int i = 0; i < m;i++)
		cout << b[i] << "  ";
	cout << "\n";	
}

int main(){
	int a[] = {4,5,6,7};
	int b[] = {1,0,2,0,0,3,0};
	int n = sizeof(a)/sizeof(a[0]);
	int m = sizeof(b)/sizeof(b[0]);
	merge(a,b,n,m);
	return 0;
}
	
	
