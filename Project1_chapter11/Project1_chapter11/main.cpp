#include "mytime.h";
#include <iostream>;
#include <fstream>;
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

	all = 2 * all; // 使用了友元函数来  operator * (2, all)
	all.show();
	all01 = all01 * 2; // 使用了all01.operator *(2) 重载了运算符
	all01.show();

	/// 让重载的函数返回了一个ostream类型的对象的引用
	std::cout << "ceshiwenzi " << all << "end \n"; //  << "end \n" 后面再加上这句话就报错了 应该是重载的方法没有返回一个ostream对象所以不能链式访问

	std::ofstream osf;
	osf.open("obj.txt");
	osf << time01;  // 也是ostream类型的也算是重载了运算符
	osf.close();

}