#include<iostream>

#include "Account.h"

void showAccount(Account &aptr);

main()
{
	Account a1(101);
//	a1.show();
	showAccount( a1);
	SavingsAccount a2(101, 10000);
//	a2.show();
	showAccount(a2);

	Account *a3 = new SavingsAccount(103,5000);
//	a3->show();
	showAccount(*a3);

	Account *a4 = new SavingsAccount(104,4000);
	showAccount(*a4);
	
}

void showAccount( Account &aptr)
{
	aptr.show();
}
