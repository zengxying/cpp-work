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
	double testParams;
	~Stock();
	Stock() { _name = "default"; _price = 0.0; _count = 0; };
	Stock(const std::string& name, double price=0.0, int count=0); // ûд��public�� Ĭ����private��������
	bool buy();
	bool shop();
	void update();
	void show();
	void show01() const;
	const Stock& compare(const Stock& other) const;
	const Stock& add(Stock& other);
	double getPrice() const { return _price; };
	double setPrice(double value) { _price = value; };
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

enum class EggType { // ����class�Ϳ���ʹ��ͬ����ֵ��
	MIN,
	MEDIUM,
	MAX,
	NONE
};

enum struct EggType01 { // ����struct�Ϳ���ʹ��ͬ����ֵ��
	MIN,
	MEDIUM,
	MAX,
	NONE
}; 
enum EggType02 { // ����class�Ϳ���ʹ��ͬ����ֵ��
	MIN,
	MEDIUM,
	MAX,
	NONE
};
enum class EggType03 :short { // ����class�Ϳ���ʹ��ͬ����ֵ�ˣ�ʹ�� :short ���޶�enum����������
	MIN,
	MEDIUM,
	MAX,
	NONE = 256,
	NONE01 = 900000000000000
};

enum class ClotheType { // ������	����	˵��	��Ŀ	�ļ�	��	��ֹ��ʾ״̬����	C2365	��MIN�� : �ض��壻��ǰ�Ķ����ǡ�ö������	ConsoleApplication1	D : \cpp_work\ConsoleApplication1\ConsoleApplication1\CustomClass.h	51

	MIN,
	MEDIUM,
	MAX,
	NONE
};

#endif // !CPP_H_CustomClass
