#include "mytime.h";
#include "ClassTyeTrans.h"
#include <iostream>;
#include <fstream>;
#include <boost/shared_ptr.hpp>

using namespace std;
class Parent;
class Child;

typedef boost::shared_ptr<Parent> parent_ptr;
typedef boost::shared_ptr<Child> child_ptr;

class Child {
public:
	Child() {
		cout << "创建child" << endl;
	}

	~Child() {
		cout << "销毁child" << endl;
	}

	parent_ptr parent;
};

class Parent {
public:
	Parent() {
		cout << "创建parent" << endl;
	}
	~Parent() {

		cout << "销毁parent" << endl;
	}
	child_ptr child;
};

void testBoostSharedCycleRef() {
	parent_ptr parent(new Parent);
	child_ptr child(new Child);
	parent->child = child;
	child->parent = parent;
	cout << "child count:" << child.use_count() << endl;
	cout << "parent count:" << parent.use_count() << endl;
	parent->child.reset(); // 消除循环引用，child count -- 会销毁child，由于child持有了parent，parent count减一，parent这句结束后parentcount再 减一 引用计数为0 销毁
	//parent.get()->child.reset();
}


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

	// 使用 explicit 修饰转换函数后 需要使用强制转换才会走转换函数
	cout << "ctt == operator double : " << (double)ctt << std::endl; // 使用了 转换函数后  ctt被转换成了double类型所以就不会报错了

	ClassType::ClassTypeTrans* ctt01 = new ClassType::ClassTypeTrans(1000);
	ctt01->showClassTT();
	delete ctt01;


	/** 根据引用计数释放new的对象  内部维持一个引用计数器 */
	boost::shared_ptr<ClassType::ClassTypeTrans> ctt02(new ClassType::ClassTypeTrans(250));
	std::cout << "ctt02.use_count() : " << ctt02.use_count() << std::endl;
	boost::shared_ptr<ClassType::ClassTypeTrans> ctt03 = ctt02; 
	std::cout << "ctt03.use_count() : " << ctt03.use_count() << std::endl;
	ctt02.reset();
	std::cout << "ctt03.use_count() : " << ctt03.use_count() << std::endl;
	ctt03.reset();

	testBoostSharedCycleRef();
}