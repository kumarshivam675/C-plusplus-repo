//Camera.h

#include<string>

//#include "Phone.h"

class Camera {
	std::string cameramake;
	int zoomlevel;
	enum photomode{Auto,night, sunny};
public:
	Camera(std::string make);
	void click();
};
