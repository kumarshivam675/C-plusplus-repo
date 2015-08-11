//Phone.cc
#include<iostream>
#include<string>
#include "CompositePhone.h"
#include "Camera.h"


CompositePhone::CompositePhone(std::string anum, std::string make){
	phoneNumber = anum;
	ptr = new Camera(make);
}

void CompositePhone::Call(){
	std::cout << "Calling " << phoneNumber << std::endl;
}
void CompositePhone::click(){
	ptr->click();
}

CompositePhone::~CompositePhone(){
	delete ptr;
}


