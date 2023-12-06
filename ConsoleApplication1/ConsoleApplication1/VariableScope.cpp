#include <iostream>
static float VAR_PI = 3.14157;
int var_int_pi = 3;
using namespace std;


void requestMemory();
///如果在其他源文件声明了，该变量 的结果

//int var_int_pi = 500; // 编译报错，已经有源文件声明了 外联静态变量
//static int var_int_pi = 500; // static 将覆盖外联的静态变量 在该文件内使用static 声明的变量

void excuteGlobalVariableScope() {
	cout << " excuteGlobalVariableScope : var_int_pi --> " << var_int_pi << endl;
}


void excuteVariableScope() {
	double var_int_pi = 99.;
	static double var_double_s = 0; // 只初始化一次，然后后续使用之前的值继续处理表达式
	var_double_s += var_int_pi;
	if (var_int_pi == 99) {
		cout << "excuteVariableScope : var_int_pi" << var_int_pi << endl;
	}
	cout << "excuteVariableScope : static double var_double_s --> " << var_double_s << endl;
	excuteGlobalVariableScope();
	requestMemory();
}

/// <summary>
/// 函数使用堆叠的“32000068”字节。请考虑将一些数据移动到堆。
/// </summary>
void requestMemory() {


	int* variable_int_01 = new int(20);
	double* variable_double_01 = new double(0.5);

	int* variable_int_02 = new int{ 20 };
	double* variable_double_02 = new double{ 2.0 };

	// 等价的但是不能按照注释里面的写
	int* variable_int_03 = new int; // == int* variable_int_03 = new (sizeof(int))
	int* variable_int_arr = new int[40]; // == int* variable_int_arr = new(40 * sizeof(int));

	struct custom_memory_test {
		int id;
		//char names[20]; // 数组需要声明长度不然编译时不好分配对应的内存空间
	};

	const int arrLenght = 10000;
	custom_memory_test testArr[arrLenght];
	custom_memory_test* testArr02 = new custom_memory_test[arrLenght]; // 指针的声明方式

	for (size_t i = 0; i < arrLenght; i++)
	{
		testArr[i].id = i;
		testArr02[i].id = i * i;
		cout << "创建struct :" << i << endl;
	}
	//,{'x','x','x','x','x','x' }
	custom_memory_test* struct_test_01 = new custom_memory_test{ 5 };// 结构体不能使用new() custom_memory_test* struct_test_02 = new custom_memory_test(5, { 'x','x','x','x','x','x' });

	delete[] testArr02;
	delete variable_int_01;
	delete variable_double_01;
	delete variable_int_02;
	delete variable_double_02;
	delete variable_int_03;
	delete[] variable_int_arr;
	delete struct_test_01;

}


