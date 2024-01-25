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
typedef boost::weak_ptr<Child> child_weak_ptr; // ��Ҫ���� weak_ptr.hpp �ļ�����Ȼ�ᱨ��

class Child {
public:
	Child() {
		cout << "����child" << endl;
	}

	~Child() {
		cout << "����child" << endl;
	}
	
	parent_ptr parent;
	parent_weak_ptr parent01;
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

class ParentWeak {
public:
	ParentWeak() {
		cout << "����ParentWeak" << endl;
	}
	~ParentWeak() {

		cout << "����ParentWeak" << endl;
	}
	child_weak_ptr child; // ʹ��������������ѭ�����ã�����child�����ü�����������
};



/// <summary>
/// ����boost::shared_ptr��ѭ����������
/// </summary>
void testBoostSharedCycleRef() {
	parent_ptr parent(new Parent);
	child_ptr child(new Child);
	parent->child = child;
	child->parent = parent;
	cout << "child count:" << child.use_count() << endl;
	cout << "parent count:" << parent.use_count() << endl;
	parent->child.reset(); // ����ѭ�����ã�child count -- ������child������child������parent��parent count��һ��parent��������parentcount�� ��һ ���ü���Ϊ0 ����
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
		boost::shared_ptr<ClassType::ClassTypeTrans> sp_ctt01 = wp_cct.lock(); // ������shared_ptr
		if (sp_ctt01)
		{
			sp_ctt01.get()->showClassTT();
		}
		else
		{
			cout << "sp_cct01 wp_ctt.lock fail" << endl;
		}

	}
	boost::shared_ptr<ClassType::ClassTypeTrans> sp_cct02 = wp_cct.lock(); // ����ʧ�ܣ�����һ�����������Ѿ���shared_ptr������
	
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

	{
		cout << "��main��������------------------------{}" << endl;
		boost::scoped_ptr<ClassType::ClassTypeTrans> spctt(new ClassType::ClassTypeTrans(101314));
		boost::scoped_ptr<ClassType::ClassTypeTrans> spctt01(new ClassType::ClassTypeTrans(101315));
		boost::scoped_ptr<ClassType::ClassTypeTrans> spctt02(new ClassType::ClassTypeTrans(101316));
		boost::scoped_ptr<ClassType::ClassTypeTrans> spctt03(new ClassType::ClassTypeTrans(101317));
		
		cout << "��main��������------------------------{} over" << endl; // �뿪������ͻ�����scoped_ptr �����������٣�Ӧ�����õ��˶��е��Ƚ����
	}


	/** �������ü����ͷ�new�Ķ���  �ڲ�ά��һ�����ü����� */
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