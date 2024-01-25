#include "mytime.h";
#include "ClassTyeTrans.h"
#include <iostream>;
#include <fstream>;
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/scoped_ptr.hpp>

using namespace std;
class Child;
class Parent;
class ParentWeak;

typedef boost::shared_ptr<Parent> parent_ptr;
typedef boost::shared_ptr<ParentWeak> parent_weak_ptr;
typedef boost::shared_ptr<Child> child_ptr;
typedef boost::weak_ptr<Child> child_weak_ptr; // 需要引入 weak_ptr.hpp 文件，不然会报错

class Child {
public:
	Child() {
		cout << "创建child" << endl;
	}

	~Child() {
		cout << "销毁child" << endl;
	}
	
	parent_ptr parent;
	parent_weak_ptr parent01;
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

class ParentWeak {
public:
	ParentWeak() {
		cout << "创建ParentWeak" << endl;
	}
	~ParentWeak() {

		cout << "销毁ParentWeak" << endl;
	}
	child_weak_ptr child; // 使用弱引用来处理循环引用，这里child的引用计数不会增加
};



/// <summary>
/// 测试boost::shared_ptr的循环引用问题
/// </summary>
void testBoostSharedCycleRef() {
	parent_ptr parent(new Parent);
	child_ptr child(new Child);
	parent->child = child;
	child->parent = parent;
	cout << "child count:" << child.use_count() << endl;
	cout << "parent count:" << parent.use_count() << endl;
	parent->child.reset(); // 消除循环引用，child count -- 会销毁child，由于child持有了parent，parent count减一，parent这句结束后parentcount再 减一 引用计数为0 销毁
	//parent.get()->child.reset();

	parent_weak_ptr pwp(new ParentWeak);
	pwp.get()->child = child;
	child.get()->parent01 = pwp;
	cout << "pwp.use_count()" << pwp.use_count() << endl;
	cout << "child.use_count()" << child.use_count() << endl;
}

void testWeakLock() {
	boost::weak_ptr<ClassType::ClassTypeTrans> wp_cct;
	{
		boost::shared_ptr<ClassType::ClassTypeTrans> sp_ctt(new ClassType::ClassTypeTrans(2000));
		cout << "sp_ctt.use_count()" << sp_ctt.use_count() << endl;
		wp_cct = sp_ctt;
		cout << "sp_ctt.use_count()" << sp_ctt.use_count() << endl;
		boost::shared_ptr<ClassType::ClassTypeTrans> sp_ctt01 = wp_cct.lock(); // 提升到shared_ptr
		if (sp_ctt01)
		{
			sp_ctt01.get()->showClassTT();
		}
		else
		{
			cout << "sp_cct01 wp_ctt.lock fail" << endl;
		}

	}
	boost::shared_ptr<ClassType::ClassTypeTrans> sp_cct02 = wp_cct.lock(); // 提升失败，在上一个作用域中已经被shared_ptr销毁了
	
	if (sp_cct02)
	{
		sp_cct02.get()->showClassTT();
	}
	else
	{
		cout << "sp_cct02 wp_ctt.lock fail" << endl;
	}
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

	{
		cout << "在main作用域中------------------------{}" << endl;
		boost::scoped_ptr<ClassType::ClassTypeTrans> spctt(new ClassType::ClassTypeTrans(101314));
		boost::scoped_ptr<ClassType::ClassTypeTrans> spctt01(new ClassType::ClassTypeTrans(101315));
		boost::scoped_ptr<ClassType::ClassTypeTrans> spctt02(new ClassType::ClassTypeTrans(101316));
		boost::scoped_ptr<ClassType::ClassTypeTrans> spctt03(new ClassType::ClassTypeTrans(101317));
		
		cout << "在main作用域中------------------------{} over" << endl; // 离开作用域就会销毁scoped_ptr 从下往上销毁，应该是用到了队列的先进后出
	}


	/** 根据引用计数释放new的对象  内部维持一个引用计数器 */
	boost::shared_ptr<ClassType::ClassTypeTrans> ctt02(new ClassType::ClassTypeTrans(250));
	std::cout << "ctt02.use_count() : " << ctt02.use_count() << std::endl;
	boost::shared_ptr<ClassType::ClassTypeTrans> ctt03 = ctt02; 
	std::cout << "ctt03.use_count() : " << ctt03.use_count() << std::endl;
	ctt02.reset();
	std::cout << "ctt03.use_count() : " << ctt03.use_count() << std::endl;
	ctt03.reset();

	testBoostSharedCycleRef();
	testWeakLock();
}