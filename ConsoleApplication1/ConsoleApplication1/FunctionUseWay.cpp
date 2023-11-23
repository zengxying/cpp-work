#include <iostream>
#include "CustomCommon.h"
using namespace std;

void testFuncConstParams(const int arr[], int size) {
	// const ���α�ʾ��ֻ�����ɸ���������
	// arr[0] += 10; // ʹ�� const���εĲ�����ʹ�õ��ǳ�����ַ�������޸���ֵ�����������java ���� ts���ԾͲ�һ���ˣ�
	const int count = 0;
	// int* cp = &count; // invalid  ��Ҫ������ָ������������Ч
	const int* cp = &count;
	const int* cpp = cp; // ���� const int* �������һ�����ͣ� cp === cpp ����ȵ�

	int test_value = 1;
	int* tvp = &test_value;
	const int* tvpp = tvp;

	int tv = 100;

	int* tf = &tv;
	int** tvppp = &tf;
	cout << "1*tvppp -- >" << *tvppp << endl;
	cout << "1**tvppp -- >" << **tvppp << endl;
	cout << "1tvppp -- >" << tvppp << endl;
	*tvppp = &tv;
	cout << "2*tvppp -- >" << *tvppp << endl;
	cout << "2**tvppp -- >" << **tvppp << endl;
	cout << "2tvppp -- >" << tvppp << endl;

	const int* t_ppp = &tv;
	t_ppp = &test_value; // ���Ըı�ָ��ָ��
	//*t_ppp = 5;//invalid ��Ч���� �����޸�ָ��ָ���ֵ

	int* const tc_ppp = &tv;
	*tc_ppp = 5;  // �����޸�ָ��ָ���ֵ
	// tc_ppp = &test_value; //invalid ��Ч���� 

	const int* const cc_tc_ppp = &tv;
	//*cc_tc_ppp = 5;//invalid ��Ч���� 
	//cc_tc_ppp = &test_value;//invalid ��Ч���� 
}


void testFuncParamsToStruct00(const FuncStruct* funcStruct, FuncStruct* outfs)
{

	funcStruct->id;
	outfs->price = rand();


}

// const �����������͵Ľṹ����
void testFuncParamsToStructReference(const FuncStruct& funcStruct, FuncStruct& outfs) {
	// funcStruct.id = 50; // invalid ����ͨ���������޸�const���ε�������������
	outfs.id = funcStruct.id + 1;

}
// const �����������͵Ľṹ����
FuncStruct& testFuncParamsToStructReference01(const FuncStruct& funcStruct, FuncStruct& outfs) {
	// funcStruct.id = 50; // invalid ����ͨ���������޸�const���ε�������������
	outfs.id = funcStruct.id + 1;
	FuncStruct fs01;
	//TODO 
	return fs01;
}

FuncStruct& clone(FuncStruct source)
{
	FuncStruct fs = source;
	return fs;
}

void testFuncOverload(double& x)
{

}
void testFuncOverload(const double& x)
{

}
const FuncStruct& clone01(const FuncStruct& source)
{
	FuncStruct fs = source;
	return fs;
}


/// <summary>
/// 
/// </summary>
/// <param name="start"></param>
/// <param name="end"></param>
/// <returns></returns>
int testFuncArrStartPointerToEndPointer(int* start, int* end) {
	int total = 0;
	int* pointer = start;
	for (; pointer != end; pointer++)
	{
		total += *pointer;
	}
	return total;
}
// ����������Ϊ����ָ������
void testFuncParamsToFunc(int (*func)(int*, int*))
{
	int id = 0;
	int id01 = 0;
	func(&id, &id01);
	(*func)(&id, &id01); // ���ַ�ʽ��ָ�뺯�����ö��������
}

void testFuncParamsToStruct01(const FuncStruct funcStruct, FuncStruct outfs) // ��¡��һ�ݴ���Ĳ��������ݵ� funcStruct�У�������һ����ʱ��Ϳռ�ɱ�
{

	testFuncParamsToFunc(testFuncArrStartPointerToEndPointer); // ���뺯��ָ��
}





/// <summary>
///  ���帴�ӵĺ�������
/// </summary>
typedef const int* (*funcType)(int*, int*); // �������ͱ���
int* testFuncArrStartPointerToEndPointer01(int* start, int* end) {
	int total = 0;
	int* pointer = start;
	for (; pointer != end; pointer++)
	{
		total += *pointer;
	}
	return &total;
}


// ֻ�ܽ��ܶ�ά���� ����Ϊ4������ �����ǵ�ַ ����  int arr[2][4]   int arr[200][4]
void test_2dimensional_array_params2(int(*arr)[4], int size)
{
}
// ֻ�ܽ��ܶ�ά���� ����Ϊ4������ �����Ǳ�����
void test_2dimensional_array_params(int arr[][4], int size)
{
	int arrTest[2][4]{};
	//test_2dimensional_array_params(arrTest, 1);
	//test_2dimensional_array_params2(arrTest, 1);
}


int testArrFunc(int arr[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count += arr[i];
	}
	return count;
}

int testArrFunc1(int* arr, int n) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count += arr[i];
	}
	return count;
}



/// <summary>
/// ����һ�����ֵĴη��� Ĭ����ƽ��  ��ԭ��������Ĭ�ϲ���ֵ�Ϳ����ˣ���Ҫ�����������ĵط�ʹ�ã�������뱨��
int calculateNumPower(int value, int power = 2) {
	int temp = value;

	if (power == 0) return 1;
	if (power < 0) {
		power = -1 * power;
		temp = value = 1 / value;
	}

	for (int i = 1; i < power; i++)
	{
		temp *= value;
	}

	return temp;
}

template <typename AnyType> // ����ģ�壬���ڲ������Զ��������ͣ����Դ�������͵Ĳ����ṩͬһ���߼�

AnyType& change(AnyType& source01, AnyType& source02)
{
	AnyType temp = source01;
	source01 = source02;
	source02 = temp;
	return temp;
}

void testFuncOverload01(const FuncStruct& fs)
{

}
void testFuncOverload01(FuncStruct& fs)
{

}

void excuteFunctionUseWayMain()
{
	int i_arr[]{ 1,2,3 };
	testFuncConstParams(i_arr, 0);
	cout << "inline pow = " << customePower(12) << endl;

	const FuncStruct fs{ 5,100.0,200.0 };
	FuncStruct& copyFs = clone(fs); // ʹ���ڲ���ʱ�������ص�ֵ���ǿ�¡������һ�����ݸ���copyFs�������������ݵĵ�ַ�ǲ�һ����
	FuncStruct copyFs01 = clone01(fs); // ʹ���ڲ���ʱ�������ص�ֵ���ǿ�¡������һ�����ݸ���copyFs�������������ݵĵ�ַ�ǲ�һ����,const ������Ҫ�ܶ�ע������
	cout << "source fs : " << &fs << endl;
	cout << "clone source copyFs : " << &copyFs << endl;

	testFuncOverload(5);
	const double doubleConst = 10;
	testFuncOverload(doubleConst); // ͨ��const��������

	testFuncOverload01(fs);
	testFuncOverload01(copyFs01); // ��

	//testFuncOverload02(fs);
	//testFuncOverload02(copyFs01); // �������Ϳ���ͨ��const���أ�����ֵ���ͺ������� ����һ������ ������������Ч
	cout << "10 ��ƽ��" << calculateNumPower(10) << endl;

	int test001 = 100;
	int test002 = 200;
	change(test001, test002);
	cout << "test001, test002 --> " << test001 << " , " << test002 << endl;
}

/*
void testFuncOverload02(const FuncStruct fs)
{

}
void testFuncOverload02(FuncStruct fs)
{

}*/