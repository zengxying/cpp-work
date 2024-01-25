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
		cout << "����child" << endl;
	}

	~Child() {
		cout << "����child" << endl;
	}

	parent_ptr parent;
};

class Parent {
public:
	Parent() {
		cout << "����parent" << endl;
	}
	~Parent() {

		cout << "����parent" << endl;
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
	parent->child.reset(); // ����ѭ�����ã�child count -- ������child������child������parent��parent count��һ��parent��������parentcount�� ��һ ���ü���Ϊ0 ����
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

	Time all = sum + time + time01; // ���������
	all.show();
	Time all01 = sum.operator+(time).operator+(time01); // ���������
	all01.show();

	all = 2 * all; // ʹ������Ԫ������  operator * (2, all)
	all.show();
	all01 = all01 * 2; // ʹ����all01.operator *(2) �����������
	all01.show();

	/// �����صĺ���������һ��ostream���͵Ķ��������
	std::cout << "ceshiwenzi " << all << "end \n"; //  << "end \n" �����ټ�����仰�ͱ����� Ӧ�������صķ���û�з���һ��ostream�������Բ�����ʽ����
	/*
	std::ofstream osf;
	osf.open("obj.txt");
	osf << time01;  // Ҳ��ostream���͵�Ҳ���������������
	osf.close();*/

	char cs[] = { 'a','b','\n' };

	// ʹ��˫�ش����ų�ʼ�����飬ָ��ά��
	char csarr[][3] = { 
		{'a','b','\n'},
	};
	std::cout << cs << std::endl;




	char* csp = cs;
	char** csparr = &csp;
	std::cout << *cs << std::endl; //  �����һ��������ָ�� ��*�� ����ָ���ֵ
	std::cout << csp << std::endl;
	std::cout << csparr << std::endl;

	ClassType::ClassTypeTrans ctt = 10; // ֱ������ת��, ͨ�����캯����������ת��

	// ʹ�� explicit ����ת�������� ��Ҫʹ��ǿ��ת���Ż���ת������
	cout << "ctt == operator double : " << (double)ctt << std::endl; // ʹ���� ת��������  ctt��ת������double�������ԾͲ��ᱨ����

	ClassType::ClassTypeTrans* ctt01 = new ClassType::ClassTypeTrans(1000);
	ctt01->showClassTT();
	delete ctt01;


	/** �������ü����ͷ�new�Ķ���  �ڲ�ά��һ�����ü����� */
	boost::shared_ptr<ClassType::ClassTypeTrans> ctt02(new ClassType::ClassTypeTrans(250));
	std::cout << "ctt02.use_count() : " << ctt02.use_count() << std::endl;
	boost::shared_ptr<ClassType::ClassTypeTrans> ctt03 = ctt02; 
	std::cout << "ctt03.use_count() : " << ctt03.use_count() << std::endl;
	ctt02.reset();
	std::cout << "ctt03.use_count() : " << ctt03.use_count() << std::endl;
	ctt03.reset();

	testBoostSharedCycleRef();
}