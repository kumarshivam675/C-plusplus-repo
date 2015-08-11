//account.h

#include<string>

class Account{
private:
	int acc_id;
	std::string name;
public:
	Account();
	Account(int acc_id, std::string n);
	Account(const Account& a);
};
