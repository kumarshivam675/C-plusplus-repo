#include<iostream>

main()
{
		int *x, **z;
		int y;
		x = new int ;
		x = &y;
		*x = 10;
		z=&x;
		std::cout << *x << std::endl << y << std::endl;
		**z = 20;
		std::cout << *z << std::endl << &y << std::endl << &x << std::endl << y << std::endl;
}
