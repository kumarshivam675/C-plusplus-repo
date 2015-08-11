#include<iostream>

using namespace std;

int getLeft(int i){
	return 2*i + 1;
}

int getParent(int i){
	return (i-1)/2;
}

int getRight(int i){
	return 2*i + 2;
}

void maxHeapify(int a[],int index,int size){
	int largest = index;
	if(a[getLeft(index)] > a[largest] && largest < size)
		largest = getLeft(index);
	if(a[getRight(index)] > a[largest] && largest < size)
		largest = getRight(index);
	if(largest != index && largest < size){
		swap(a[index],a[largest]);
		maxHeapify(a,largest,size);
	}
}

void Heapify(int a[],int size){
	int parent = getParent(size-1);
	for(int i = parent; i >= 0; i--)
		maxHeapify(a,i,size);
}

int extractMax(int a[],int &size){
	swap(a[0],a[size-1]);
	int temp = a[size-1];
	size--;
	maxHeapify(a,0,size);
	return temp;
}

void kLargestElement(int a[],int size,int k){
	Heapify(a,size);
	for(int i = 0; i < size; i++)
		cout << a[i] << "  ";
	cout << endl;
	for(int i = 0; i < k; i++)
		cout << extractMax(a,size) << endl;
}


int main(){
	int input[] = {1,2,3,4,5,6,7,8,9,10};
	int size = sizeof(input)/sizeof(input[0]);
	//Heapify(input,size);
	//extractMax(input,size);
	kLargestElement(input,size,5);
	return 0;
}






	
