#include <iostream>
static float VAR_PI = 3.14157;
int var_int_pi = 3;
using namespace std;


void requestMemory();
///���������Դ�ļ������ˣ��ñ��� �Ľ��

//int var_int_pi = 500; // ���뱨���Ѿ���Դ�ļ������� ������̬����
//static int var_int_pi = 500; // static �����������ľ�̬���� �ڸ��ļ���ʹ��static �����ı���

void excuteGlobalVariableScope() {
	cout << " excuteGlobalVariableScope : var_int_pi --> " << var_int_pi << endl;
}


void excuteVariableScope() {
	double var_int_pi = 99.;
	static double var_double_s = 0; // ֻ��ʼ��һ�Σ�Ȼ�����ʹ��֮ǰ��ֵ����������ʽ
	var_double_s += var_int_pi;
	if (var_int_pi == 99) {
		cout << "excuteVariableScope : var_int_pi" << var_int_pi << endl;
	}
	cout << "excuteVariableScope : static double var_double_s --> " << var_double_s << endl;
	excuteGlobalVariableScope();
	requestMemory();
}

/// <summary>
/// ����ʹ�öѵ��ġ�32000068���ֽڡ��뿼�ǽ�һЩ�����ƶ����ѡ�
/// </summary>
void requestMemory() {


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

}


