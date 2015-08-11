#include<iostream>
#include<stack>

using namespace std;

/*int main(){
	stack<int> mystack;
	for(int i = 0; i < 5; i++)
		mystack.push(i);
	while(!mystack.empty()){
		cout << mystack.top() << endl;
		mystack.pop();
	}
	return 0;
}*/

int main ()
{
  std::stack<int> foo,bar;
  foo.push (10); foo.push(20); foo.push(30);
  bar.push (111); bar.push(222);

  foo.swap(bar);

  std::cout << "size of foo: " << foo.size() << '\n';
  std::cout << "size of bar: " << bar.size() << '\n';

  return 0;
}
