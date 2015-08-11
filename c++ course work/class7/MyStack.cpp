/* 
 * File:   MyStack.cpp
 * Author: vivek
 * 
 * Created on 28 January, 2015, 11:52 AM
 */
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "MyStack.h"

using namespace std;

MyStack::MyStack(void) {
}

MyStack::~MyStack(void) {
}

void MyStack::push(int data) {
    this->_v.push_back(data);
}

int MyStack::pop() {
    int ret = _v.back();
    _v.pop_back();
    return ret;
}

std::string MyStack::toString() {
    std::string ret = "";
    std::stringstream sm;
    for (int i = 0; i < _v.size(); i++) {
        sm << _v[i] << " ";
    }
    return sm.str();
}