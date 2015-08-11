/* 
 * File:   MyStack.h
 * Author: vivek
 *
 * Created on 28 January, 2015, 11:52 AM
 */

#ifndef MYSTACK_H
#define	MYSTACK_H

class MyStack {
private:
    std::vector<int> _v;
public:
    MyStack(void);
    ~MyStack(void);
    void push(int);
    int pop();
    std::string toString();

};

#endif	/* MYSTACK_H */

