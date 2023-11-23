#include <iostream>
#include "CustomCommon.h"
using namespace std;

void testFuncConstParams(const int arr[], int size) {
	// const 修饰表示了只读不可更改其数据
	// arr[0] += 10; // 使用 const修饰的参数，使用的是常量地址，不能修改其值，这个和其他java 或者 ts语言就不一样了，
	const int count = 0;
	// int* cp = &count; // invalid  需要常量的指针声明才能有效
	const int* cp = &count;
	const int* cpp = cp; // 所以 const int* 代表的是一种类型， cp === cpp 是相等的

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
	t_ppp = &test_value; // 可以改变指针指向
	//*t_ppp = 5;//invalid 无效代码 不能修改指针指向的值

	int* const tc_ppp = &tv;
	*tc_ppp = 5;  // 可以修改指针指向的值
	// tc_ppp = &test_value; //invalid 无效代码 

	const int* const cc_tc_ppp = &tv;
	//*cc_tc_ppp = 5;//invalid 无效代码 
	//cc_tc_ppp = &test_value;//invalid 无效代码 
}


void testFuncParamsToStruct00(const FuncStruct* funcStruct, FuncStruct* outfs)
{

	funcStruct->id;
	outfs->price = rand();


}

// const 修饰引用类型的结构数据
void testFuncParamsToStructReference(const FuncStruct& funcStruct, FuncStruct& outfs) {
	// funcStruct.id = 50; // invalid 不能通过，不能修改const修饰的引用类型数据
	outfs.id = funcStruct.id + 1;

}
// const 修饰引用类型的结构数据
FuncStruct& testFuncParamsToStructReference01(const FuncStruct& funcStruct, FuncStruct& outfs) {
	// funcStruct.id = 50; // invalid 不能通过，不能修改const修饰的引用类型数据
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
// 将参数设置为函数指针类型
void testFuncParamsToFunc(int (*func)(int*, int*))
{
	int id = 0;
	int id01 = 0;
	func(&id, &id01);
	(*func)(&id, &id01); // 两种方式的指针函数调用都是允许的
}

void testFuncParamsToStruct01(const FuncStruct funcStruct, FuncStruct outfs) // 克隆了一份传入的参数的数据到 funcStruct中，会增加一定的时间和空间成本
{

	testFuncParamsToFunc(testFuncArrStartPointerToEndPointer); // 传入函数指针
}





/// <summary>
///  定义复杂的函数类型
/// </summary>
typedef const int* (*funcType)(int*, int*); // 定义类型别名
int* testFuncArrStartPointerToEndPointer01(int* start, int* end) {
	int total = 0;
	int* pointer = start;
	for (; pointer != end; pointer++)
	{
		total += *pointer;
	}
	return &total;
}


// 只能接受二维数组 列数为4的数组 参数是地址 比如  int arr[2][4]   int arr[200][4]
void test_2dimensional_array_params2(int(*arr)[4], int size)
{
}
// 只能接受二维数组 列数为4的数组 参数是变量名
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
/// 计算一个数字的次方， 默认是平方  在原型上声明默认参数值就可以了，不要在声明函数的地方使用，否则编译报错
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

template <typename AnyType> // 函数模板，用于参数的自动分配类型，可以传入多类型的参数提供同一种逻辑

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
	FuncStruct& copyFs = clone(fs); // 使用内部临时变量返回的值，是克隆出来的一份数据给了copyFs，所以两个数据的地址是不一样的
	FuncStruct copyFs01 = clone01(fs); // 使用内部临时变量返回的值，是克隆出来的一份数据给了copyFs，所以两个数据的地址是不一样的,const 修饰需要很多注意事项
	cout << "source fs : " << &fs << endl;
	cout << "clone source copyFs : " << &copyFs << endl;

	testFuncOverload(5);
	const double doubleConst = 10;
	testFuncOverload(doubleConst); // 通过const修饰重载

	testFuncOverload01(fs);
	testFuncOverload01(copyFs01); // 引

	//testFuncOverload02(fs);
	//testFuncOverload02(copyFs01); // 引用类型可以通过const重载，但是值类型好像不行呢 再试一下试试 非引用类型无效
	cout << "10 的平方" << calculateNumPower(10) << endl;

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