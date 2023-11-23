#include <iostream>
static float VAR_PI = 3.14157;
int var_int_pi = 3;
using namespace std;

///如果在其他源文件声明了，该变量 的结果

//int var_int_pi = 500; // 编译报错，已经有源文件声明了 外联静态变量
//static int var_int_pi = 500; // static 将覆盖外联的静态变量 在该文件内使用static 声明的变量

void excuteGlobalVariableScope() {
	cout << " excuteGlobalVariableScope : var_int_pi --> " << var_int_pi << endl;
}


void excuteVariableScope(){
	double var_int_pi = 99.;
	static double var_double_s = 0; // 只初始化一次，然后后续使用之前的值继续处理表达式
	var_double_s += var_int_pi;
	if (var_int_pi == 99) {
		cout << "excuteVariableScope : var_int_pi" << var_int_pi << endl;
	}
		cout << "excuteVariableScope : static double var_double_s --> " << var_double_s << endl;
	excuteGlobalVariableScope();
}



