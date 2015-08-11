//Phone.h

#include<string>

class Phone{
	std::string phoneNumber;
	enum phoneState{ideal,inuse};
	
public:
	Phone(std::string anum);
	void Call();

};
