
#include "ClassTyeTrans.h";
#include <iostream>

namespace ClassType {

	ClassType::ClassTypeTrans::ClassTypeTrans(int temp) {
		value = temp;
		std::cout << "���캯������ClassTypeTrans(int temp)��" << temp << std::endl;
	}

	ClassType::ClassTypeTrans::ClassTypeTrans() {
		value = 0.0;
	}

	ClassType::ClassTypeTrans::~ClassTypeTrans() {
		std::cout << "���ٶ��� class type trans"<< value << std::endl;
	}

	ClassType::ClassTypeTrans::operator double() const { // ����ĵط�����Ҫʹ��explicit������
		return value;
	}

	void ClassType::ClassTypeTrans::showClassTT()const {
		std::cout << "showClassTT value :" << this << std::endl;
	}
}