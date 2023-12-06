#include <iostream>

//operatorMemoryAddress  ���н��
//address: heap-->00000239395AFDE0         static-->00007FF732D37740
//p01:  value-- > 1020.000000     address-- > 00000239395AFDE0              p02 : value-- > 1020.000000    address-- > 00007FF732D37740
//p01 : value-- > 1020.100000     address-- > 00000239395AFDE8              p02 : value-- > 1020.100000    address-- > 00007FF732D37748
//p01 : value-- > 1020.200000     address-- > 00000239395AFDF0              p02 : value-- > 1020.200000    address-- > 00007FF732D37750
//p01 : value-- > 1020.300000     address-- > 00000239395AFDF8              p02 : value-- > 1020.300000    address-- > 00007FF732D37758
//p01 : value-- > 1020.400000     address-- > 00000239395AFE00              p02 : value-- > 1020.400000    address-- > 00007FF732D37760
//======================================== = delet p01 address================================ =
//p03:  value-- > 1040.000000     address-- > 00000239395AFAD0              p04 : value-- > 1040.000000    address-- > 00007FF732D37740               p02 : value-- > 1040.000000     address-- > 00007FF732D37740
//p03 : value-- > 1040.100000     address-- > 00000239395AFAD8              p04 : value-- > 1040.100000    address-- > 00007FF732D37748               p02 : value-- > 1040.100000     address-- > 00007FF732D37748
//p03 : value-- > 1040.200000     address-- > 00000239395AFAE0              p04 : value-- > 1040.200000    address-- > 00007FF732D37750               p02 : value-- > 1040.200000     address-- > 00007FF732D37750
//p03 : value-- > 1040.300000     address-- > 00000239395AFAE8              p04 : value-- > 1040.300000    address-- > 00007FF732D37758               p02 : value-- > 1040.300000     address-- > 00007FF732D37758
//p03 : value-- > 1040.400000     address-- > 00000239395AFAF0              p04 : value-- > 1040.400000    address-- > 00007FF732D37760               p02 : value-- > 1040.400000     address-- > 00007FF732D37760
//======================================== = delet p03 address================================ =
//p01:  value-- > 1060.000000     address-- > 00000239395AFFA0              p04 : value-- > 1040.000000    address-- > 00007FF732D37740               p02 : value-- > 1060.000000     address-- > 00007FF732D37768
//p01 : value-- > 1060.100000     address-- > 00000239395AFFA8              p04 : value-- > 1040.100000    address-- > 00007FF732D37748               p02 : value-- > 1060.100000     address-- > 00007FF732D37770
//p01 : value-- > 1060.200000     address-- > 00000239395AFFB0              p04 : value-- > 1040.200000    address-- > 00007FF732D37750               p02 : value-- > 1060.200000     address-- > 00007FF732D37778
//p01 : value-- > 1060.300000     address-- > 00000239395AFFB8              p04 : value-- > 1040.300000    address-- > 00007FF732D37758               p02 : value-- > 1060.300000     address-- > 00007FF732D37780
//p01 : value-- > 1060.400000     address-- > 00000239395AFFC0              p04 : value-- > 1040.400000    address-- > 00007FF732D37760               p02 : value-- > 1060.400000     address-- > 00007FF732D37788
//---------------------- - over--------------------------
using namespace std;


/// <summary>
/// ����ʹ�öѵ��ġ�32000068���ֽڡ��뿼�ǽ�һЩ�����ƶ����ѡ�
/// </summary>
/*void requestMemory() {


	int* variable_int_01 = new int(20);
	double* variable_double_01 = new double(0.5);

	int* variable_int_02 = new int{ 20 };
	double* variable_double_02 = new double{ 2.0 };

	// �ȼ۵ĵ��ǲ��ܰ���ע�������д
	int* variable_int_03 = new int; // == int* variable_int_03 = new (sizeof(int))
	int* variable_int_arr = new int[40]; // == int* variable_int_arr = new(40 * sizeof(int));

	struct custom_memory_test {
		int id;
		//char names[20]; // ������Ҫ�������Ȳ�Ȼ����ʱ���÷����Ӧ���ڴ�ռ�
	};

	const int arrLenght = 10000;
	custom_memory_test testArr[arrLenght];
	custom_memory_test* testArr02 = new custom_memory_test[arrLenght]; // ָ���������ʽ

	for (size_t i = 0; i < arrLenght; i++)
	{
		testArr[i].id = i;
		testArr02[i].id = i * i;
		cout << "����struct :" << i << endl;
	}
	//,{'x','x','x','x','x','x' }
	custom_memory_test* struct_test_01 = new custom_memory_test{ 5 };// �ṹ�岻��ʹ��new() custom_memory_test* struct_test_02 = new custom_memory_test(5, { 'x','x','x','x','x','x' });

	delete[] testArr02;
	delete variable_int_01;
	delete variable_double_01;
	delete variable_int_02;
	delete variable_double_02;
	delete variable_int_03;
	delete[] variable_int_arr;
	delete struct_test_01;

}*/

const int MAX_LEN = 5;
const int MAX_BUFFER_LEN = 512;
char* buff = new char[MAX_BUFFER_LEN];


/// <summary>
/// ͨ��ʹ��buff�����ľ�̬��ַ���洢���ݣ� ��ͨ��new��ͨ��ϵͳ�����ڴ��ַ
/// </summary>
/// 

void operatorMemoryAddress() {
	double* p01, *p02, * p03, * p04; // һ���������ͬ���ͱ����� ����ǵ�ַ����Ҫ��ӵ�ַ��ʶ���������������double���͵�����

	p01 = new double[MAX_LEN];
	p02 = new (buff) double[MAX_LEN];

	for (int i = 0; i < MAX_LEN; i++)
	{
		p01[i] = p02[i] = 1000 + 20.0 + 0.1 * i;
	}

	cout << "Memory address: heap-->" << p01 << "		static-->" << (void*)buff << endl;

	for (int i = 0; i < MAX_LEN; i++)
	{
		cout << "p01:" << "		value-->" << p01[i] << "	address-->" << &p01[i] << "		";
		cout << "p02:" << "		value-->" << p02[i] << "	address-->" << &p02[i] << endl;
	}

	delete[] p01;
	cout << "=========================================delet p01 address=================================" << endl;
	p03 = new double[MAX_LEN];
	p04 = new (buff) double[MAX_LEN];

	for (int i = 0; i < MAX_LEN; i++)
	{
		p03[i] = p04[i] = 1000 + 40.0 + 0.1 * i;
	}
	for (int i = 0; i < MAX_LEN; i++)
	{
		cout << "p03:" << "		value-->" << p03[i] << "	address-->" << &p03[i] << "		";
		cout << "p04:" << "		value-->" << p04[i] << "	address-->" << &p04[i] << "		";
		cout << "p02:" << "		value-->" << p02[i] << "	address-->" << &p02[i] << endl;
	}

	delete[] p03;
	cout << "=========================================delet p03 address=================================" << endl;
	p01 = new double[MAX_LEN];
	p02 = new (buff + MAX_LEN * sizeof(double)) double[MAX_LEN];
	for (int i = 0; i < MAX_LEN; i++)
	{
		p01[i] = p02[i] = 1000 + 60.0 + 0.1 * i;
	}
	for (int i = 0; i < MAX_LEN; i++)
	{
		cout << "p01:" << "		value-->" << p01[i] << "	address-->" << &p01[i] << "		";
		cout << "p04:" << "		value-->" << p04[i] << "	address-->" << &p04[i] << "		";
		cout << "p02:" << "		value-->" << p02[i] << "	address-->" << &p02[i] << endl;
	}
	delete[] p01;
	delete[] buff;
	cout << "-----------------------over--------------------------";
	
}

namespace  HiSpace {
	int id;
	char* name;
	void test(int id) {
		cout << "���������ռ�" << id << endl;
	}

	void testDynamic();
}
void HiSpace::testDynamic() {
	cout << "��̬�����ĺ����ӿ�testDynamic" << endl;
}
namespace NestNameSpace {

	int gid;
	static int GID = 0;

	namespace HiNestNameSpace {
		char* name;
		double price;
		void buy() {
			gid = GID ++;
			cout << "buy hi nest name space" << gid << endl;
		}
	}

}

void testNameSpace() {
	cout << "test name testNameSpace" << endl;
	using HiSpace::id;
	using HiSpace::test;
	id = 500;
	//int id = 300; // ���벻ͨ�������ַ�ʽ�ܹ��ܺõķ�ֹ�ظ�ʹ�ñ��������µ�����
	cout << id << endl;
	test(0);
}

void testNameSpace01() {
	HiSpace::testDynamic();
	cout << "test name testNameSpace01" << endl;
	using namespace HiSpace;
	id = 500;
	int id = 300; // ����ͨ�����·�ʹ�õ�id���Ǿֲ������������Ǹ�id
	cout << id << endl;
	test(1);
}

void testNameSpace03() {
	using HiSpace::test;
	test(3);
	NestNameSpace::HiNestNameSpace::buy();
	namespace nestns = NestNameSpace::HiNestNameSpace; // ������ʹ��
	nestns::buy();
}


void excuteNewOperator() {
	testNameSpace();
	testNameSpace01();
	testNameSpace03();
	//requestMemory();
	operatorMemoryAddress();
}
