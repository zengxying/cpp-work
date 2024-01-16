#include "mytime.h";

int main() {

	Time time;
	time.reset(24, 39);

	Time time01 = Time(1, 52);
	time.show();
	time01.show();
	Time sum = time.sum(time01);
	sum.show();

	Time all = sum + time + time01; // 运算符重载
	all.show();
	Time all01 = sum.operator+(time).operator+(time01); // 运算符重载
	all01.show();
}