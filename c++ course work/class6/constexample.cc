#include<iostream>

class DemoClass{
		int somenum;
public:
		int othernum;
		int getNum() const{
				return somenum;
		}

		void setNum(int val){
				somenum = val;
		}

};

void someFunc ( const DemoClass &d, DemoClass &d2 );
void anotherFun(DemoClass& d);
main()
{
		DemoClass *d1 = new DemoClass;

		const DemoClass *d2 = d1;
		d1->othernum = 10;
//		d2->othernum = 20;

		someFunc(*d1, *d1);
}

void someFunc ( const DemoClass& d, DemoClass& d2 ){
		
	//	d.setNum(25);//Error
		int x = d.getNum();//Okay

		d2.setNum(25);//Okay
		int y =d2.getNum();//Okay

		//anotherFun(d);//Error
}

void anotherFun(DemoClass& d){
}
