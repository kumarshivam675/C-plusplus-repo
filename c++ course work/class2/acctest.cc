//acctest.cc

#include<iostream>
#include<string>
#include "account.h"

main()
{
	Account a1;
	Account a2(24,"john");
	Account a3(a1);

	std::cout<<"i am done" << std ::endl;
}
