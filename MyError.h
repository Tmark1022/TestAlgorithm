#ifndef MYERROR_H
#define MYERROR_H
#include<string>

// �޶��������ö������
enum class ErrorNo{
	clear,
	out_of_range,
	over_flow,
	bad_param,			// ��������
};

void MyPerror(const std::string & str);
#endif