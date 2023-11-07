// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//



#include <iostream>
/*
int main()
{
    std::cout << "Hello World!\n";
}
还有就是有运行的调试器后，会影响当前代码修改后的编译，所以养成每次关掉调试器的习惯
*/

void printfTestUsing1() {
    std::cout << "printfTestUsing  1!\n" << std::endl;
}

void printfTestUsing();
int main()
{
    std::cout << "price:\n";
    
    int price = 30;
    price++;
    std::cout << price;
    std::cout << "\n";
    std::cout << "Hello World!\n";
    printfTestUsing(); // 声明在调用函数之后的函数需要再调用函数之前声明，否则找不到该定义的函数
    printfTestUsing1();
    for (size_t i = 0; i < 10000000000; i++)
    {
        std::cout << "i = " << i << std::endl; // << std::endl; 和 "\n"的效果一致
    }
    
    return 0;
}

void printfTestUsing() {
    std::cout << "printfTestUsing!\n" << std::endl;
}