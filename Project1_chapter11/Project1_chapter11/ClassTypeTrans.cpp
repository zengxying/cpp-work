
#include "ClassTyeTrans.h";
#include <iostream>

namespace ClassType {

	ClassType::ClassTypeTrans::ClassTypeTrans(int temp) {
		value = temp;
		std::cout << "构造函数调用ClassTypeTrans(int temp)：" << temp << std::endl;
	}

	ClassType::ClassTypeTrans::ClassTypeTrans() {
		value = 0.0;
	}

	ClassType::ClassTypeTrans::~ClassTypeTrans() {
		std::cout << "销毁对象 class type trans"<< value << std::endl;
	}

	ClassType::ClassTypeTrans::operator double() const { // 定义的地方不需要使用explicit来修饰
		return value;
	}

	void ClassType::ClassTypeTrans::showClassTT()const {
		std::cout << "showClassTT value :" << this << std::endl;
	}
}