#include"Stack.h"
#include"Node.h"

#include<iostream>
#include <cstddef>

using namespace std;

Stack::Stack(){
	top = NULL;
	size = 0;
}

void Stack::push(int value){
	Node* newnode = new Node(value);
	newnode->setNext(top);
	top = newnode;
	size++;
}

int Stack::pop(){
	if(top == NULL){
		cout << "Empty Stack\n";
		return -1;
	}
	else{
		int value;
		Node* temp = new Node();
		temp = top;
		top = top->getNext();
		value = temp->getValue();
		size--;
		delete temp;
		return value;
	}
}

void Stack::traverse(){
	while(top != NULL){
		cout << top->getValue() << endl;
		top = top->getNext();
	}
}

int Stack::isEmpty(){
	if(top == NULL)
		return 1;
	else 
		return 0;
}

void Stack::nextGreaterElement(int a[], int size){
	 push(a[0]);
	 int pop_value, flag = 0;
	 for(int i = 1; i < size; i++){
	 	while(!isEmpty()){
	 		pop_value = pop();
		 	if(pop_value < a[i]){
		 		cout << pop_value << "     " << a[i] << endl;
		 	}
		 	else{
		 		push(pop_value);
		 		push(a[i]);
		 		break;
		 	}
		 	if(isEmpty())
		 		flag = 1;
	 	}
	 	if(flag == 1){
	 		push(a[i]);
	 		flag = 0;
	 	}
	 }
	 while(!isEmpty()){
	 	pop_value = pop();
	 	cout << pop_value << "     " << "-1" << endl;
	 }
	 
}

int Stack::getSize(){
	return size;
}

void Stack::span(int price[], int size){
	int pop_value, val[10], flag, flag1;
	Stack s;
	s.push(price[0]);
	val[0] = 1;
	for(int i = 1; i < size; i++){
		val[i] = 0;
		flag = 0;
		flag1 = 0;
		while(!s.isEmpty()){
			pop_value = s.pop();
			//cout <<"cost and flag first " << price[i] << "  " << flag << endl;
			if(pop_value < price[i]){
				flag = 1;
			}
			
			else if(flag == 0){
				//cout << "inside flag\n";
				s.push(pop_value);
				s.push(price[i]);
				val[i] = 1;
				flag1 = 1;
				break;
			}
			else{
				s.push(pop_value);
				s.push(price[i]);
				break;
			}
			//cout <<"cost and flag second " << price[i] << "  " << flag << endl;
		}
		int stack_size = s.getSize();
		if(flag1 == 0)
			val[i] = i - stack_size + 2;
	}
	for(int i = 0; i < size; i++){
		cout << val[i] << endl;
	}
}
			
	
	
	
	
	
	
	
	
	
	
