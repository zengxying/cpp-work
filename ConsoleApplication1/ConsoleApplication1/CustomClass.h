#ifndef CPP_H_CustomClass
#define CPP_H_CustomClass

#include <string>
#include <iostream>
class Stock {

private:
	std::string _name;
	double _price;
	int _count;
	void printInfo() { std::cout << "name:" << _name << "	price:" << _price << " count:" << _count << std::endl; };

public:
	~Stock();
	Stock(const std::string& name, double price=0.0, int count=0); // 没写到public下 默认是private的作用域
	bool buy();
	bool shop();
	void update();
	void show();
	void show01() const;
};

class DefaultConstructorClass {
public:
	void test() {
		std::cout << "测试没有构造函数的class" << std::endl;
	}
	
	void test01() const{
		std::cout << "测试没有构造函数的class" << std::endl;
	}

	~DefaultConstructorClass() {
		std::cout << "测试没有构造函数的class  ~DefaultConstructorClass  释放对象" << std::endl;
	}
};

#endif // !CPP_H_CustomClass
