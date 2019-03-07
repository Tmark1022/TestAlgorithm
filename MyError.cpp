#include<iostream>
#include<string>
#include "MyError.h"

using std::cerr;
using std::endl;
using std::string;

// ∂®“Â¥ÌŒÛerrno
ErrorNo myerrno = ErrorNo::clear;

void MyPerror(const string & str){
	switch (myerrno)
	{
	case ErrorNo::clear: cerr << str << "no problem." << endl; break;
	case ErrorNo::out_of_range:cerr << str << "out of range." << endl; break;
	case ErrorNo::over_flow:cerr << str << "overflow." << endl; break;
	case ErrorNo::bad_param:cerr << str << "bad params." << endl; break;
	default:
		break;
	}
	myerrno = ErrorNo::clear;
}








