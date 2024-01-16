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
	Stock(const std::string& name, double price=0.0, int count=0); // 没写到public下 默认是private的作用域
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
		std::cout << "测试没有构造函数的class" << std::endl;
	}
	
	void test01() const{
		std::cout << "测试没有构造函数的class" << std::endl;
	}

	~DefaultConstructorClass() {
		std::cout << "测试没有构造函数的class  ~DefaultConstructorClass  释放对象" << std::endl;
	}
};

enum class EggType { // 加上class就可以使用同样的值了
	MIN,
	MEDIUM,
	MAX,
	NONE
};

enum struct EggType01 { // 加上struct就可以使用同样的值了
	MIN,
	MEDIUM,
	MAX,
	NONE
}; 
enum EggType02 { // 加上class就可以使用同样的值了
	MIN,
	MEDIUM,
	MAX,
	NONE
};
enum class EggType03 :short { // 加上class就可以使用同样的值了，使用 :short 来限定enum的整数类型
	MIN,
	MEDIUM,
	MAX,
	NONE = 256,
	NONE01 = 900000000000000
};

enum class ClotheType { // 严重性	代码	说明	项目	文件	行	禁止显示状态错误	C2365	“MIN” : 重定义；以前的定义是“枚举数”	ConsoleApplication1	D : \cpp_work\ConsoleApplication1\ConsoleApplication1\CustomClass.h	51

	MIN,
	MEDIUM,
	MAX,
	NONE
};

#endif // !CPP_H_CustomClass
