//Account.h

#include<iostream>

class Account{
protected:
	int account_num;
public:

	Account() : account_num(0) { }

	Account(int anum) : account_num(anum){
	}

	Account(Account& other) : account_num(other.account_num){
	}

	virtual void show(){
		std::cout << "Account num" << account_num << std::endl;
	}
};

class SavingsAccount : public Account{
	float min_balance;
public:
	SavingsAccount( int anum, float minbal) :
		Account(anum), min_balance(minbal){
	}
	void show(){
	std::cout << "Account number=" << account_num << std::endl;
	std::cout << "Min Balance=" << min_balance << std::endl;
	}
};
