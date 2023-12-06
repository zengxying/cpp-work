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
	Stock(const std::string& name, double price=0.0, int count=0); // ûд��public�� Ĭ����private��������
	bool buy();
	bool shop();
	void update();
	void show();
	void show01() const;
};

class DefaultConstructorClass {
public:
	void test() {
		std::cout << "����û�й��캯����class" << std::endl;
	}
	
	void test01() const{
		std::cout << "����û�й��캯����class" << std::endl;
	}

	~DefaultConstructorClass() {
		std::cout << "����û�й��캯����class  ~DefaultConstructorClass  �ͷŶ���" << std::endl;
	}
};

#endif // !CPP_H_CustomClass
