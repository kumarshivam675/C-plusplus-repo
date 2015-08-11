#include<stdio.h>

void swap( int &v1, int &v2)
{
	int temp = v2;
	v2 = v1;
	v1 = temp;
}

int main()
{
	int x = 10;
	int y = 20;
	swap(x,y);
	printf("%d %d\n",x,y);
}
