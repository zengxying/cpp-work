#include <iostream>
static float VAR_PI = 3.14157;
int var_int_pi = 3;
using namespace std;

///���������Դ�ļ������ˣ��ñ��� �Ľ��

//int var_int_pi = 500; // ���뱨���Ѿ���Դ�ļ������� ������̬����
//static int var_int_pi = 500; // static �����������ľ�̬���� �ڸ��ļ���ʹ��static �����ı���

void excuteGlobalVariableScope() {
	cout << " excuteGlobalVariableScope : var_int_pi --> " << var_int_pi << endl;
}


void excuteVariableScope(){
	double var_int_pi = 99.;
	static double var_double_s = 0; // ֻ��ʼ��һ�Σ�Ȼ�����ʹ��֮ǰ��ֵ����������ʽ
	var_double_s += var_int_pi;
	if (var_int_pi == 99) {
		cout << "excuteVariableScope : var_int_pi" << var_int_pi << endl;
	}
		cout << "excuteVariableScope : static double var_double_s --> " << var_double_s << endl;
	excuteGlobalVariableScope();
}



