//account.cc
#include<iostream>
#include<string>
#include "account.h"

using namespace std;

Account::Account()
{
	acc_id = 10;
	name = "shivam";
	cout<<"default constructor\n";
}

Account::Account(int anum , string n)
{
	acc_id = anum;
	name = n;
	cout<<"defined constructor\n";
	cout<<
}

Account::Account(const Account& other)
{
	acc_id = other.acc_id;
	name = other.name;
	cout<<"copy constructor\n";
}
