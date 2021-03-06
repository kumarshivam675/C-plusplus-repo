#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &s,int item){
	if(s.empty()){
		s.push(item);
		return ;
	}
	int temp = s.top();
	s.pop();
	insertAtBottom(s,item);
	s.push(temp);
}

void reverse(stack<int> &s){
	if(s.empty())
		return ;
	int temp = s.top();
	s.pop();
	reverse(s);
	
	insertAtBottom(s,temp);
}


int main(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.top() << endl;
	reverse(s);
	cout << s.top() << endl;
	return 0;
}
		
