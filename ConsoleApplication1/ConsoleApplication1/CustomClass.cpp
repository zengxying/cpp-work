#include <iostream>
#include "CustomClass.h"
Stock::Stock(const std::string& name, double price, int count) { // 头文件中定义默认值即可，这里写了默认值编译不通过
	_name = name;
	_price = price;
	_count = count;
	printInfo();
}


Stock::~Stock() {
	using namespace std;
	cout << "Stock::~Stock()" << endl;
}
bool Stock::buy() {
	using namespace std;
	cout << "Stock::buy()" << endl;

	return true;
}
bool Stock::shop() {

	using namespace std;
	cout << "Stock::shop()" << endl;
	return true;
}
void Stock::show() {
	using namespace std;
	cout << "Stock::show()" << endl;

}

void Stock::show01() const {
	using namespace std;
	cout << "Stock::show() const "<< _name << endl;

}

void Stock::update() {
	using namespace std;
	cout << "Stock::update()" << endl;

}

const Stock& Stock::compare(const Stock& other) const {
	//this->_price; // this是地址
	return other._price > _price ? other : *this;
}
const Stock& Stock::add(Stock& other) {
	_price = _price + other.getPrice(); // this是地址
	return *this;
}

