
#include "ClassTyeTrans.h";
#include <iostream>

namespace ClassType {

	ClassType::ClassTypeTrans::ClassTypeTrans(int temp) {
		value = temp;
	}

	ClassType::ClassTypeTrans::ClassTypeTrans() {
		value = 0.0;
	}

	ClassType::ClassTypeTrans::~ClassTypeTrans() {
		std::cout << "Ïú»Ù¶ÔÏó class type trans" << std::endl;
	}

	ClassType::ClassTypeTrans::operator double() const {
		return value;
	}
}