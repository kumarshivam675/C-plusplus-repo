//exceptionhandling demo
#include<iostream>
#include<vector>
#include<exception>

using namespace std;

void f1();
void f2();
void f3();

class SomeClass{
		int x;
public:
		SomeClass(int val):x(val){}
};

main()
{
		try{
				//SomeClass *someObj = new SomeClass(10);
				//f1();
				//f2();
				f3();
				//delete someObj;
		}
		catch(exception& ex)
		{
				//delete someObj; //clean up
				cout << "C++ exception handled\n";
		}
		catch(int ex)
		{
				cout << "Int Exception " << ex << "handled" << endl;
		}
				
		catch(string ex)
		{
				cout << "Sting Exception " << ex << "handled" << endl;
		}
		catch(...)
		{
				cout << "Unknown Exception handled" << endl;
		}
}

void f1(){
		vector<int> v;
		//cout << "Throwing int exception\n";
		//throw 25;
		cout << v.at(10) << endl;
}

void f2(){
		cout << "Throwing string exception\n";
		throw string("Help!");
}

void f3(){
		cout << "Throwing unknown type ecxeption\n";
		throw "Help";
}
