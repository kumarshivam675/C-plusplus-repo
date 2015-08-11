//Phone.h

#include<string>
//#include "Camera.h"

class Camera;

class CompositePhone{
	std::string phoneNumber;
	enum phoneState{ideal,inuse};
	Camera *ptr;
	
public:
	CompositePhone(std::string anum, std::string make);
	void Call();
	void click();
	~CompositePhone();

};
