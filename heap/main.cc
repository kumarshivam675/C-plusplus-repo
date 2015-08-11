#include<iostream>
#include"Heap.h"

using namespace std;

int main(){
	Heap h(10);
	h.insert(5);
	h.insert(3);
	h.insert(7);
	h.insert(8);
	h.insert(0);
	h.insert(1);
	h.insert(10);
	h.print();
	//h.decreaseKey(3,2);
	h.extractMin();
	h.print();
	return 0;
}
