#ifndef MYERROR_H
#define MYERROR_H
#include<string>

// 限定作用域的枚举类型
enum class ErrorNo{
	clear,
	out_of_range,
	over_flow,
	bad_param,			// 传参有误
};

void MyPerror(const std::string & str);
#endif