#include"Node.h"
#include"Stack.h"
#include<iostream>

using namespace std;

main(){
	Stack s;
	/*s.push(5);
	s.push(4);
	s.push(3);
	int value = s.pop();
	cout << "deleted node's value is: " << value << endl;*/
	int a[] = {4,5,2,25};
	//s.nextGreaterElement(a,4);
	//s.traverse();
	int price[] = {100,80,60,70,60,75,85};
	int price2[] ={10,4,5,90,120,80};
	int price1[] = {100,80};
	s.span(price2,6);
}
