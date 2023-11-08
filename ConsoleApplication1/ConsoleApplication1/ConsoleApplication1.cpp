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
/*
int main()
{
    std::cout << "Hello World!\n";
}
还有就是有运行的调试器后，会影响当前代码修改后的编译，所以养成每次关掉调试器的习惯
*/

void printfTestUsing1() {
    using namespace std; // 在方法内部使用using namespace  也可以在最上面声明 这样整个方法里面都可以使用这种简写方式访问
    cout << "printfTestUsing  1!\n" << endl;
}

void printfTestUsing();
void printfTestNumberScope();
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
    

    auto vAuto4 = 1e9;
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