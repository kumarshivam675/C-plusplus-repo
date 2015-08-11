//Camera.cc

#include<iostream>
#include<string>

#include "Camera.h"

Camera::Camera(std::string make) :
	cameramake(make){
	zoomlevel = 0;
}  

void Camera::click(){
	std::cout << "Click " << std::endl;
}
