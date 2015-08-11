#include<iostream>
#include<climits>
#include"Heap.h"

using namespace std;

Heap::Heap(int capac){
	size = 0;
	capacity = capac;
	arr = new int(capacity);
}

int Heap::parent(int i){
	return (i-1)/2;
}
	
int Heap::left(int index){
	return 2*index + 1;
}
	
int Heap::right(int index){
	return 2*index + 2;
}
	
int Heap::getMin(){
	return arr[0];
}
	
void Heap::swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
	
void Heap::insert(int value){
    arr[size] = value;
    int i = size;
    while(i >= 0 && arr[i] < arr[parent(i)]){
    	//cout << "befor swaping " << arr[i] << "   " << arr[parent(i)] << endl;
        swap(arr[i],arr[parent(i)]);
       // cout << "after swapping " << arr[i] << "  " << arr[parent(i)] << endl;
        i = parent(i);
    }
    size++;
}

void Heap::print(){
    for(int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }
}

void Heap::decreaseKey(int i, int new_value){
	arr[i] = new_value;
	
	while(i >= 0 && arr[i] < arr[parent(i)]){
		swap(arr[i],arr[parent(i)]);
		i = parent(i);
	}
}

void Heap::minHeapify(int i){
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l < size && arr[l] < arr[i])
		smallest = l;
	if(r < size && arr[r] < arr[l])
		smallest = r;
	if(smallest != i){
		swap(arr[i],arr[smallest]);
		minHeapify(smallest);
	}
}

void Heap::extractMin(){
	if(size == 0)
		return ;
	if(size == 1){
		size --;
		return ;
	}
	swap(arr[0],arr[size-1]);
	size--;
	minHeapify(0);	
}

void Heap::deleteKey(int i){
	decreaseKey(i,INT_MIN);
	extractMin();
}

void Heap::heapify(int a[], int a_size){
	Heap h(size);
	for(int i = a_size - 1; i >=0; i++){
		j = i;
		while(j > 0){
			if(a[j] < a[parent(j)]){
				swap(a[j],a[parent(j)]);
				j = parent(j);
			}
			else
				minHeapify(























