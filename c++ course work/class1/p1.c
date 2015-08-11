#include<stdio.h>

int myglobal=200;
extern int anotherglobal;
int main()
{
	printf("%d\n",myglobal);
	f1();
	printf("%d\n",myglobal);
	f2();
	printf("%d\n",myglobal);
	printf("%d\n",anotherglobal);
}
int f1()
{
	myglobal=10;
}
