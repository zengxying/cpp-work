#pragma once
#ifndef CPP_H_CLASS_TYPE_TRANS
#define CPP_H_CLASS_TYPE_TRANS
#include <iostream>
namespace ClassType {
	class ClassTypeTrans {
	private:
		double value;
	public :
		ClassTypeTrans();
		ClassTypeTrans(int temp);

		explicit operator double() const;
		~ClassTypeTrans();

		void showClassTT()const;
	};
}
#endif // !CPP_H_CLASS_TYPE_TRANS
