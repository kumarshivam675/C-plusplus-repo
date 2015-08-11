#include<iostream>

using namespace std;

void merge(int a[], int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	int *left, *right;
	left = new int[n1];
	right = new int[n2];
	
	for(int i = 0; i < n1; i++)
		left[i] = a[l+i];
	for(int i = 0; i < n2; i++)
		right[i] = a[m+1+i];
		
	int i = 0, j = 0, k = l;
	while(i < n1 && j < n2){
		if(left[i] <= right[j]){
			a[k] = left[i];
			i++;
		}
		else{
			a[k] = right[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		a[k] = left[i];
		i++;
		k++;
	}
	while(j < n2){
		a[k] = right[j];
		j++;
		k++;
	}
}

void mergeSort(int a[],int l,int r){
	if(l < r){
		int m = (l + r)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
	}
}

int main(){
	int input[] = {7,6,5,4,3,2,1};
	int size = sizeof(input)/sizeof(input[0]);
	mergeSort(input,0,size-1);
	for(int i = 0; i < size; i++)
		cout << input[i] << "  ";
	cout << "\n";
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
