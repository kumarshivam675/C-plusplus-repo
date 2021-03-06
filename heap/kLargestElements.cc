#include<iostream>
#include<climits>

using namespace std;

int getParent(int i){
	return (i-1)/2;
}

int getLeftChild(int i){
	return 2*i + 1;
}

int getRightChild(int i){
	return 2*i + 2;
}

int getMin(int a[]){
	return a[0];
}

void swap(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}

void printHeap(int a[],int size){
	for(int i = 0; i < size; i++)
		cout << a[i] << "  ";
	cout << endl;
}

void minHeapify(int a[],int i,int size){
	int small = i;
	int l = getLeftChild(i);
	int r = getRightChild(i);
	if(a[l] < a[i] && l < size){
		small = l;
	}
	if(a[r] < a[small] && r < size){
		small = r;
	}
	if(small != i && small < size){
		swap(a[i],a[small]);
		minHeapify(a,small,size);
	}
}

void Heapify(int a[],int size){
	int start = getParent(size-1);
	for(int i = start; i >= 0; i--)
		minHeapify(a,i,size);
}

/*int extractMin(int a[], int size){
	int temp = a[0];
	a[0] = INT_MAX;
	size--;
	minHeapify(a,0,size);
	return temp;
}*/


void KLargest(int a[],int size,int k){
	int *ans;
	ans = new int[k];
	for(int i = 0; i < k; i++){
		ans[i] = a[i];
	}
	Heapify(ans,k);
	printHeap(ans,k);
	for(int i = k; i < size; i++){
		if(a[i] > getMin(ans)){
			ans[0] = a[i];
			minHeapify(ans,0,k);
		}
		printHeap(ans,k);
	}
}
	
	

int main(){
	int input[] = {1,2,3,4,5,6,7,8,9,10};
	int size = sizeof(input)/sizeof(input[0]);
	int k = 3;
	KLargest(input,size,k);
	return 0;
}
