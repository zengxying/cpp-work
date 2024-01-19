#pragma once
#ifndef CPP_H_CLASS_TYPE_TRANS
#define CPP_H_CLASS_TYPE_TRANS
namespace ClassType {
	class ClassTypeTrans {
	private:
		double value;
	public :
		ClassTypeTrans();
		ClassTypeTrans(int temp);

		operator double() const;
		~ClassTypeTrans();

	};
}
#endif // !CPP_H_CLASS_TYPE_TRANS
