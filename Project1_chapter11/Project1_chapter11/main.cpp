#include "mytime.h";
#include "ClassTyeTrans.h"
#include <iostream>;
#include <fstream>;
int main() {

	using std::cout;

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
	/*
	std::ofstream osf;
	osf.open("obj.txt");
	osf << time01;  // 也是ostream类型的也算是重载了运算符
	osf.close();*/

	char cs[] = { 'a','b','\n' };

	// 使用双重大括号初始化数组，指定维度
	char csarr[][3] = { 
		{'a','b','\n'},
	};
	std::cout << cs << std::endl;




	char* csp = cs;
	char** csparr = &csp;
	std::cout << *cs << std::endl; //  数组第一个索引的指针 的*解 就是指针的值
	std::cout << csp << std::endl;
	std::cout << csparr << std::endl;

	ClassType::ClassTypeTrans ctt = 10; // 直接类型转换, 通过构造函数进行类型转换

	cout << "ctt == operator double : " << ctt << std::endl; // 使用了 转换函数后  ctt被转换成了double类型所以就不会报错了


}