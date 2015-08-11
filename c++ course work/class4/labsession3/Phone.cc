//Phone.cc
#include<iostream>
#include<string>
#include "Phone.h"


Phone::Phone(std::string anum) : phoneNumber(anum){
}

void Phone::Call(){
	std::cout << "Calling " << phoneNumber << std::endl;
}

