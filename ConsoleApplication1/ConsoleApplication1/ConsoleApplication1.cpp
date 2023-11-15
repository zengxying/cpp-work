// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*预编译
1. 在C++编译过程中，首先将源代码传递给预处理器。
在这里，#define和#include一样，也是一个预处理器编译指令。
该编译指令告诉预处理器:在程序中查找INT_MAX,并将所有的INT-MAX都替换为32767。
因此#define编译指令的工作方式与文本编辑器或字处理器中的全局搜索并替换命令相似。
*/

/*
* 数据的使用说明
* C++将整型常量存储为int类型。首先来看看后缀。后缀是放在数字常量后面的字母,用于表示类型。
整数后面的1或L后缀表示该整数为long常量, u或U后缀表示unsigned int常量, ul (可以采用任何一
种顺序,大写小写均可)表示unsigned long常量(由于小写1看上去像1,因此应使用大写L作后缀)。例如
，在int为16位、long为32位的系统上，数字22022被存储为int，占16位，数字22022L被存储为long，
占32位。同样，22022LU和22022UL都被存储为unsigned long。 C++11提供了用于表示类型long long的
后缀11和LL,还提供了用于表示类型unsigned long long的后缀ul1、U11、uLL和ULL.接下来考察长度。
在C++中，对十进制整数采用的规则，与十六进制和八进制稍微有些不同。对于不带后缀的十进制整数,
将使用下面几种类型中能够存储该数的最小类型来表示: int、long或long long。在int为16位、long
为32位的计算机系统上, 20000被表示为int类型, 40000被表示为long类型, 3000000000被表示为1ong 1ong类型。
对于不带后缀的十六进制或八进制整数,将使用下面几种类型中能够存储该数的最小类型来表示:
int、 unsigned int long、 unsigned long、 long long或unsigned long long。在将40000表示为long的计算机系统中，
十六进制数0x9C40 (40000)将被表示为unsigned int。这是因为十六进制常用来表示内存地址,而内存地址是没有符号的
,因此, usigned int比long更适合用来表示16位的地址。
*/

#include <iostream>
#include <fstream>
#include <array>
#include <vector>

typedef char* pchar;
typedef clock_t int_c_t, ck_t; // 类型别名
/*
int main()
{
	std::cout << "Hello World!\n";
}
还有就是有运行的调试器后，会影响当前代码修改后的编译，所以养成每次关掉调试器的习惯
*/

using namespace std; // 在方法内部使用using namespace  也可以在最上面声明 这样整个方法里面都可以使用这种简写方式访问
void printfTestUsing1() {
	cout << "printfTestUsing  1!\n" << endl;
}

void printfTestUsing();
void printfTestNumberScope();
void testArray();
void testStruct();
void testPointer();
void testPointerToStruct();
void testInputString();
void testArray02();
void testCodeExucuteEvn();
void testWriteFile();
void testReadFile();
int main()
{
	std::cout << "price:\n";

	int rocs = {}; // set rocs to 0
	int psychics{}; // set psychics to 0
	int emus{ 7 }; // set emus to 7
	int rheas = { 12 }; // set rheas to 12
	int price = 30;
	price++;

	short maxShort = SHRT_MAX;
	unsigned short unMaxShort = 0;

	std::cout << maxShort << std::endl; //32767
	std::cout << unMaxShort << std::endl;//0

	maxShort++;
	unMaxShort--;

	std::cout << maxShort << std::endl;//- 32768
	std::cout << unMaxShort << std::endl;//65535

	/*char inputChar;
	std::cin >> inputChar;
	std::cout << "inputChar :" << inputChar << std::endl; // inputChar = "M"  记录的值却是 77
	*/
	price += INT_MAX;
	std::cout << price << std::endl;//65535


	std::cout << emus << std::endl;
	std::cout << sizeof price << std::endl;
	std::cout << sizeof(int) << std::endl; // 计算类型所占字节数

	std::cout << price;
	std::cout << "\n";
	std::cout << "Hello World!\n";
	printfTestUsing(); // 声明在调用函数之后的函数需要再调用函数之前声明，否则找不到该定义的函数
	printfTestUsing1();
	//for (size_t i = 0; i < 10000000000; i++)
	//{
	//    std::cout << "i = " << i << std::endl; // << std::endl; 和 "\n"的效果一致
	//}
	//
	printfTestNumberScope();
	testArray();
	testStruct();
	testPointer();
	testPointerToStruct();
	testArray02();
	//testWriteFile();
	testReadFile();
	testCodeExucuteEvn();
	return 0;
}

void printfTestUsing() {
	std::cout << "printfTestUsing!\n" << std::endl;
}


void printfTestNumberScope() {
	using namespace std;

	cout.setf(ios_base::fixed, ios_base::floatfield);
	char vChar = 'M';
	cout << "vChar ->  cout.put";

	cout.put(vChar) << endl; // M

	cout << "vChar -> " << vChar << endl; // M
	cout << "char M -> " << 'M' << endl; // M
	cout << "int M -> " << (int)vChar << endl; // M = 77

	vChar += 100; // 77 + 100 (177 - 127 = 50)  -128 + 50 = -79      char 【-128  127】   
	int vInt = vChar;
	cout << "vInt -> " << vInt << endl; // -793

	float vFloat = 3.4e-37;
	cout << "1e37f/9.0 -> " << 1e37f / 9.0 << endl; //                      1111111103757312517587273218437152768.000000
	cout << "1e37f/9.0f -> " << 1e37f / 9.0f << endl; //                    1111111121363570837693353507038429184.000000
	cout << "float(1e37f/9.0f) -> " << (float)(1e37f / 9.0f) << endl;//     1111111121363570837693353507038429184.000000
	cout << "double(1e37f/9.0f) -> " << (double)(1e37f / 9.0f) << endl; //  1111111121363570837693353507038429184.000000
	cout << "long double(1e37f/9.0f) -> " << (long double)(1e37l / 9.0l) << endl; //  1111111111111111027068305891418701824.000000
	auto vAuto1 = 1e37;
	cout << "vAuto1 -> " << vAuto1 << endl; //   double
	auto vAuto3 = 1e38f;  // fail 1e39f; !! 超过了浮点数的精度范围
	cout << "vAuto3 -> " << vAuto3 << endl; // float


	auto vAuto4 = 1e37f * 1e2f;
	cout << "vAuto4 -> " << vAuto4 << endl; //   
	vAuto4 *= 1e2;
	cout << "vAuto4 -> " << vAuto4 << endl; //  




	auto vAuto2 = 1e37f / 9.0f;
	cout << "vAuto -> " << vAuto2 << endl; //   float 
	/*
	vAuto
	 double(1e37f/9.0) -> 111111111.111111
	 1e37f/9.0f -> 111111112.000000
	 float(1e37f/9.0f) -> 111111112.000000
	 double(1e37f/9.0f) -> 111111112.000000
	 double(1e37f/9.0) -> 111111111.111111
	*/
	cout << "double(1e37f/9.0) -> " << (double)(1e9f / 9.0) << endl; //   111111111.111111
	cout << "1e37f/9.0f -> " << 1e9f / 9.0f << endl; //                    111111112.000000
	cout << "float(1e37f/9.0f) -> " << (float)(1e9f / 9.0f) << endl;//     111111112.000000
	cout << "double(1e37f/9.0f) -> " << (double)(1e9f / 9.0f) << endl; //  111111112.000000
	cout << "double(1e37f/9.0) -> " << (double)(1e9f / 9.0) << endl; //   111111111.111111
	cout << "double(1e37/9.0) -> " << (double)(1e9 / 9.0) << endl; //   111111111.111111


}




/*
整数类型：

bool：

存储大小：通常占用一个字节
可能的值：true 或 false
char：

存储大小：通常占用一个字节
范围： - 128 到 127 或 0 到 255（取决于是否有符号）
unsigned char：

存储大小：通常占用一个字节
范围：0 到 255
short（也称为 short int）：

存储大小：通常占用两个字节
范围： - 32, 768 到 32, 767
unsigned short（也称为 unsigned short int）：

存储大小：通常占用两个字节
范围：0 到 65, 535
int：

存储大小：通常占用四个字节
范围： - 2, 147, 483, 648 到 2, 147, 483, 647
unsigned int：

存储大小：通常占用四个字节
范围：0 到 4, 294, 967, 295
long（通常是32位系统）：

存储大小：通常占用四个字节
范围： - 2, 147, 483, 648 到 2, 147, 483, 647
unsigned long（通常是32位系统）：

存储大小：通常占用四个字节
范围：0 到 4, 294, 967, 295
long long（通常是64位系统）：

存储大小：通常占用八个字节
范围： - 9, 223, 372, 036, 854, 775, 808 到 9, 223, 372, 036, 854, 775, 807
unsigned long long（通常是64位系统）：

存储大小：通常占用八个字节
范围：0 到 18, 446, 744, 073, 709, 551, 615
浮点数类型：

float：

存储大小：通常占用四个字节
范围：约±3.4e-38 到 ±3.4e38
精度：通常为6到9位有效数字
double：

存储大小：通常占用八个字节
范围：约±1.7e-308 到 ±1.7e308
精度：通常为15到18位有效数字
long double：

存储大小：通常占用十二个字节或更多
范围：取决于系统
精度：通常高于 double*/



void testArray() {

	// vIntArr[13]; 编译不通过
	//std::cout << vIntArr[13] << std::endl;
	//int vIntArr[len];  声明的长度必须是常量，不可修改的数值

	char cats[10]{ 'i','h','a','v','e','a','c','a','t','\0' };
	std::cout << "char arr  string - >" << cats << std::endl;

	char dogs[]{ 'i','h','a','v','e','a','d','o','g' };
	std::cout << "dogs arr  char - >" << dogs << std::endl;//

	char autoDogArr[] = "i have a lot of dogs!!!!"; // 这种声明方式默认末尾跟了一个 \0
	std::cout << "autoDogArr - >" << autoDogArr << std::endl;//

	std::string  vString = "这是一个字符串的声明"; // 更安全 可以随意改变长度
	vString += "jjjjjjjj";

}

void testStruct() {
	struct MyStruct  // 结构体
	{
		string name;
		int age;
		double price;
	};

	MyStruct myStruct{ "zhang_san", 18, 99999.22222 };
	MyStruct none{};

	struct SpecialStruct
	{
		string name;
		int sssss;
	};

	SpecialStruct sp01;

	SpecialStruct ssArr[]{
		{"sp", 1},
		{"sp", 1}
	};

	union MyUnion // 共用体，只能有一个属性生效，最后一次赋值会修改其他属性的值
	{
		int id_int;
		double id_double;
		char id_char;
	};

	MyUnion myunion;
	myunion.id_char = 'j';
	myunion.id_int = 'j';
	myunion.id_double = 55.5;

	cout << "myunion >" << myunion.id_char << endl; // 空字符
	cout << "myunion >" << myunion.id_int << endl;  // 0
	cout << "myunion >" << myunion.id_double << endl; // 55.5
	union MyUnion02 {
		long id_long;
		int id_int;
		float id_float;
	};

	struct MyStruct02 {
		int price;

		union {
			long id_long;
			int id_int;
			float id_float; // 不能填string类型，应该是转换问题
		};

	};
	MyStruct02 myStruct03;


	enum MyEnum { RED = 3, ORONGE, BLUE, GREEN, WHITE = 9, BLACK, PEEK }; // 定义枚举 

	MyEnum myEnum;
	myEnum = RED;
	int red = MyEnum::RED;
	myEnum = MyEnum(red); // 需要枚举强制转换 int类型

	cout << "&myEnum === >" << &myEnum << endl;


	double aChar = 10000.0;
	cout << "&aChar === >" << &aChar << endl;
	cout << "&bChar - &aChar === >" << int(long(&aChar) - long(&myEnum)) << endl;  // 8 字节？？  相减为8

	double bChar = 1000.0;

	cout << "&bChar === >" << &bChar << endl;
	cout << "&bChar - &aChar === >" << int(&bChar - &aChar) << endl;  // double 4字节  int 8 字节？？  神奇

	double* varAddress = &bChar;  //note: 必须以对应的类型来声明 *varAddress的类型，因为*varAddress指的是 double类型的值  varAddress指的是一个变量的引用

	cout << "*varAddress " << *varAddress << endl; // 值
	cout << "varAddress " << varAddress << endl; // 地址
}

//用于测试指针
void testPointer() {
	// note : 在cout和多数C++表达式中，char数组名、char指针以及用引号括起的字符串常量都被解释为字符串第一个字符的地址。


	double vDouble = 2.0;
	double* pDouble = &vDouble;
	vDouble = NULL;
	//delete pDouble; //内存有东西不能释放   不是new分配的内存不能释放
	int* pSome = new int[1000]; // 创建数组的地址
	pSome[0] = 1;
	pSome[1] = 2;
	pSome[2] = 3;
	pSome[3] = 4;
	cout << "pSome[0]" << pSome[0] << endl;// 1
	cout << "*pSome" << *pSome << endl;  // 1 表示的也是第一个元素，这是和声明数组的变量是不同的地方
	pSome++;  // 这里是指针地址向前移动一个地址
	cout << "pSome++ *pSome" << *pSome << endl;  // 2 表示的也是第一个元素，这是和声明数组的变量是不同的地方
	cout << "pSome++ pSome[0]" << pSome[0] << endl;  // 2 表示的也是第一个元素，这是和声明数组的变量是不同的地方
	pSome--; // ！！ 需要还原指针才能删除
	delete[] pSome;

	int arrInt[]{ 1,2,3,4,5,6 };
	// int* pArrInt = &arrInt; // FIAL  数组类型好像变量自身就是一个地址。。。。。
	int* pArrInt = arrInt;
	cout << "arrInt[0]" << arrInt[0] << endl;

	// 下面三个都表示数组元素第一个元素的地址
	cout << "arrInt -- >" << arrInt << endl;
	cout << "pArrInt -- >" << pArrInt << endl;
	cout << "pArrInt -- >" << &arrInt[0] << endl;
	cout << "&arrInt -- >" << &arrInt << endl; // 地址和第一个元素的地址一致，但是 &arrInt ++ 是加了一个arrInt内存长度的数量级 即 int * 6 = 4 * 6  int 四字节 

	// 这样就可以赋值arrInt数组的地址
	int(*pArrAYInt)[6] = &arrInt;

	cout << "sizeOf(arrInt) -- >" << sizeof(arrInt) << endl;  // 计算了整个数组的空间占用  24
	cout << "sizeOf(pArrInt) -- >" << sizeof(pArrInt) << endl; // 8 计算的是地址的空间占用 （指针的长度）

	const char* pString = "iamstring"; // 字符串字面值是常量，这就是为什么代码在声明中使用关键字const的原因。
	char* pChar;
	char vString[20] = "youarestring";
	pChar = vString;

	cout << "pChar --- > " << pChar << endl; // 传入的是地址而不是字符串的值，"pChar --- > " 这个也是转换成常量地址传入进去的
	cout << "vString --- > " << vString << endl;
	cout << "pString --- > " << pString << endl;
	cout << "(char *)pString --- > " << (char*)pString << endl; // 还是字符串
	cout << "(int *)pString --- > " << (int*)pString << endl;  // 打印出来是地址了, 运行时传入的是地址了，所以打印了地址

	auto ssss = (int*)pString;

	/*
	*
	for (size_t i = 0; i < INT64_MAX; i++)  // 由于没有删除指针 会造成内存一直存在，没有被重复使用，内存持续升高
	{
		delete []pSome;
		pSome = new int[i]; // 这样就可以动态创建数组的内存占用对应的地址
		cout << "pSome address : " << pSome << endl;
	}

	//testInputString();
	int* vInt = new int;
	for (size_t i = 0; i < INT64_MAX; i++)  // 由于没有删除指针 会造成内存一直存在，没有被重复使用，内存持续升高
	{
		delete vInt; // 删除再重新分配内存就不会出现该问题了
		vInt = new int;
		cout << "vInt address : " << vInt << endl;
	}

	delete vInt;
	*/

}

void testCodeExucuteEvn() {

	int test0 = 100;

	//每个{} 算一个语句块 内部定义的变量在外部就会被销毁，出了语句块就被销毁了 不管外层是否存在同名变量

	if (test0 > 50) {
		int test0 = 20;
		cout << "code to function if(){}  int test0 = " << test0 << endl;
	}

	{
		int test0 = 120;
		cout << "code to function {}  int test0 = " << test0 << endl;
	}
	cout << "code to function int test0 = " << test0 << endl;

	clock_t start = clock();
	int_c_t daley = CLOCKS_PER_SEC;
	int count = 0;
	while (clock() - start < daley)
	{
		cout << "wait !!!" << ++count << endl; // 919/ 1000
	}
	cout << "wait over !!!" << endl;

	const int maxLen = 20;
	int arr01[maxLen];
	for (int i = 0; i < maxLen; i++)
	{
		arr01[i] = i * 2;
	}

	for (int x : arr01) {
		cout << "arr01--->" << x << endl;
	}
	for (int& x : arr01) { // &表明是引用类型，可以修改对应数组的值
		x *= 10;
	}
	for (int x : arr01) {
		cout << "arr01--->" << x << endl;
	}
	/*
	char ch;
	count = 0;
	cin >> ch;
	while (ch != '#')
	{
		cout << ch;
		count++;
		cin >> ch; // 每次取出输入的char 如果没有值 就需要继续输入，如果有很长的char输入，则每次读取一个char字符到ch, 会跳过空格、换行符
	}
	*/

	char chineseChar = '酒';

	char ch;
	count = 0;
	cin >> ch;
	while (ch != '#')
	{
		if (ch < 0) {

			cout << "特殊符号:";
		}
		else {

			if (ispunct(ch)) {

				cout << "是标点符号:";
			}
			if (isspace(ch)) {

				cout << "是空格:";
			}
			if (isalpha(ch)) { // 是否是 字母
				cout << "是字母:";
			}
			if (isdigit(ch)) {

				cout << "是数字:";
			}
		}

		cout << ch << endl;
		count++;
		cin.get(ch); // 成员函数cin.get(ch)读取输入中的下一个字符（即使它是空格），并将其赋给变量ch
	}
}


void testArray02() {
	const int maxLen = 3;
	vector <int> intVect(maxLen);
	array <double, maxLen> doubleArr{ 1,2,3 };
	double dArr[maxLen] = { 4,5,6 };

	intVect[0] = 7;
	intVect[1] = 8;
	intVect[2] = 9;

	dArr[-2] = 10; // intVect[-2] 运行时报错     *(dArr -2) = 10
	*(dArr - 2) = 22; // 这两句是等同的，且只有数组 double dArr[] 可以使用该操作

	cout << "doubleArr" << doubleArr[0] << endl;
	cout << "intVect" << intVect[0] << endl;

	double* pDArr = dArr;
	(*++pDArr)++;
	cout << "pDArr" << pDArr << endl;

	*pDArr--;
	cout << "pDArr" << pDArr << endl;

}


void testPointerToStruct() {

	struct PointerStruct {
		int id;
		int byteCount;
	};

	PointerStruct ps{ 1,100 };
	PointerStruct* pps = &ps;

	cout << "ps.id  = " << ps.id << endl;
	cout << "pps->id  = " << pps->id << endl; // 地址访问成员的方式方法
	cout << "pps->id  = " << (*pps).id << endl; // 地址访问成员的方式方法

	PointerStruct ps0;
	PointerStruct ps1;
	PointerStruct* psArr[] = { &ps0, &ps1 };  // psArr 是一个指针数组

	// psArr 指向的是数组第一个元素的地址， 然后数组第一元素是一个结构的地址， 因此 psArrP是结构地址的指针 （指针和地址一个意思）
	PointerStruct** psArrP = psArr;
	//PointerStruct(*psArrP01)[] = &psArr;  fail 因为psArr不是一个声明变量 而是一个地址数组
	//PointerStruct*** ppps = psArrP;

	cout << "*psArr  psArr[0]->id" << psArr[0]->id << endl;
	auto ss = psArrP;
	cout << "PointerStruct** psArrP ： " << psArrP << endl; // 数组第一个指针的指针  打印出来是一个地址
	cout << "PointerStruct** psArrP  (* psArrP)->id  ：" << (*psArrP)->id << endl;

}

void testWriteFile() {
	char mobile[50];
	int year;
	double price;
	 
	ofstream osf;
	osf.open("info.txt");

	cout << "请输入手机号:" << endl;
	cin.getline(mobile, 50);
	cout << "请输入年龄:" << endl;
	cin >> year;
	cout << "请输入价格:" << endl;
	cin >> price;

	cout << "请输入手机号:" << mobile << endl;
	cout << "请输入年龄:" << year << endl;
	cout << "请输入价格:" << price << endl;
	/*
	osf << "----------------------这是代码生成的文件----------------------" << endl;
	osf << "请输入手机号:" << mobile << endl;
	osf << "请输入年龄:" << year << endl;
	osf << "请输入价格:" << price << endl;
	*/
	osf << year << endl;
	cout << "请输入年龄:" << endl;
	cin >> year;
	osf << year << endl;

	cout << "请输入年龄:" << endl;
	cin >> year;
	osf << year << endl;

	cout << "请输入年龄:" << endl;
	cin >> year;
	osf << year << endl;
	osf.close();
}

void testReadFile() {
	ifstream ifs;
	ifs.open("info.txt");
	if (! ifs.is_open()) {
		exit(EXIT_FAILURE);
	}
	int value;
	int sum = 0;
	ifs >> value;
	while (ifs.good()) { // ifs.is_open 不好使 ， good查看读取操作是否成功
		sum += value;
		ifs >> value;
	}

	if (ifs.eof()) {

		cout << "read file over!!!" << endl;
	}
	else if (ifs.fail()) {

		cout << "read file fail!!!" << endl;
	}
	else {
		cout << "read file other error code!!!" << endl;
	}
	cout << "calculate addtion result : " << sum << endl;
	ifs.close();
}


int testArrFunc(int arr[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count += arr[i];
	}
	return count;
}

int testArrFunc(int* arr, int n) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count += arr[i];
	}
	return count;
}


void testInputString() {
	char* charArr[1000];
	int i = 0, charLen = 0;
	const int maxLineLength = 80;
	while (true)
	{
		char* charTemp = new char[maxLineLength];
		cin.getline(charTemp, maxLineLength);
		size_t charLen = strlen(charTemp) + 1;
		charArr[i] = new char[charLen];
		//strcpy(charArr[i], charTemp);
		strcpy_s(charArr[i], charLen, charTemp);

		delete[] charTemp;
		int count = i;
		while (count >= 0)
		{
			cout << "第" << count << "行：" << charArr[count] << endl;
			count--;
		}
		if (strcmp(charArr[i], "exit") == 0) {
			for (int j = 0; j <= i; j++) {
				delete[] charArr[j];
			}
			break;
		}
		i++;
	}
}