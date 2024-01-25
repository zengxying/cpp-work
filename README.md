# cpp-work
用于学习cpp代码



#### 快捷键

ctrl  + d  复制选中内容复制到下一行

| 设置选定内容的格式 | **Ctrl+K、Ctrl+F** [文本编辑器] | 编辑.格式化选定内容 |
| ------------------ | ------------------------------- | ------------------- |
|                    |                                 |                     |





## 类型 内存
#### C++提供了大量的整型,应使用哪种类型呢?
通常, int被设置为对目标计算机而言最为“自然”的长度。
**自然长度(natural size)指的是计算机处理起来效率最高的长度。**如果没有非常有说服力的理由来选择其他类型，则应使用int。
现在来看看可能使用其他类型的原因。如果变量表示的值不可能为负，如文档中的字数,则可以使用无符号类型,这样变量可以表示更大的值。
如果知道变量可能表示的整数值大于16位整数的最大可能值,则使用1ong。即使系统上int为32位,也应这样做。这样,将程序移植到16位系统时,
就不会突然无法正常工作（参见图3.2）。如果要存储的值超过20亿，可使用long long。

#### 内存节省主要是数组这种连续内存结构的数据
如果short比int小,则使用short可以节省内存。通常,仅当有大型整型数组时,才有必要使用short。(数组是一种数据结构,在内存中连续存储同
类型的多个值。)如果节省内存很重要,则应使用short而不是使用int,即使它们的长度是一样的。例如,假设要将程序从int为16位的系统移到int
为32位的系统,则用于存储int数组的内存量将加倍,但short数组不受影响。请记住,节省一点就是赢得一点。


#### 数据的使用说明
C++将整型常量存储为int类型。首先来看看后缀。后缀是放在数字常量后面的字母,用于表示类型。整数后面的1或L后缀表示该整数为long常量, u或U后缀表示unsigned int常量, ul (可以采用任何一种顺序,大写小写均可)表示unsigned long常量(由于小写1看上去像1,因此应使用大写L作后缀)。例如，在int为16位、long为32位的系统上，数字22022被存储为int，占16位，数字22022L被存储为long，占32位。同样，22022LU和22022UL都被存储为unsigned long。 C++11提供了用于表示类型long long的后缀ll和LL,还提供了用于表示类型unsigned long long的后缀ull、Ull、uLL和ULL.接下来考察长度。在C++中，对十进制整数采用的规则，与十六进制和八进制稍微有些不同。对于不带后缀的十进制整数,将使用下面几种类型中能够存储该数的最小类型来表示: int、long或long long。在int为16位、long为32位的计算机系统上, 20000被表示为int类型, 40000被表示为long类型, 3000000000被表示为long long类型。对于不带后缀的十六进制或八进制整数,将使用下面几种类型中能够存储该数的最小类型来表示: int、 unsigned int long、 unsigned long、 long long或unsigned long long。在将40000表示为long的计算机系统中，十六进制数0x9C40 (40000)将被表示为unsigned int。这是因为十六进制常用来表示内存地址,而内存地址是没有符号的,因此, usigned int比long更适合用来表示16位的地址。



#### 数据存储的实质

有趣的是，程序中输入的是M，而不是对应的字符编码77。另外，程序将打印M，而不是77。通过查看内存可以知道, 77是存储在变量ch中的值。这种神奇的力量不是来自char类型,而是来自cin和cout,这些工具为您完成了转换工作。输入时, cin将键盘输入的M转换为77;输出时, cout将值77转换为所显示的字符M; cin和cout的行为都是由变量类型引导的。如果将77存储在int变量中,则cout将把它显示为77 (也就是说, cout显示两个字符7) 。程序清单3.6说明了这一点,该程序还演示了如何在C++中书写字符字面值:将字符用单引号括起,如'M' (注意,示例中没有使用双引号。C++对字符用单引号，对字符串使用双引号。cout对象能够处理这两种情况,但正如第4章将讨论的,这两者有天壤之别) 。最后,程序引入了cout的一项特性—cout. put()函数，该函数显示一个字符。





#### 数据类型提升下面是C++11版本的校验表,编译器将依次查阅该列表。

(1)如果有一个操作数的类型是long double,则将另一个操作数转换为long double。

(2)否则,如果有一个操作数的类型是double,则将另一个操作数转换为double.

(3)否则,如果有一个操作数的类型是float,则将另一个操作数转换为float。

(4)否则,说明操作数都是整型,因此执行整型提升。

(5)在这种情况下，如果两个操作数都是有符号或无符号的，且其中一个操作数的级别比另一个低,则转换为级别高的类型。

(6)如果一个操作数为有符号的,另一个操作数为无符号的,且无符号操作数的级别比有符号操作数高,则将有符号操作数转换为无符号操作数所属的类型。

(7)否则,如果有符号类型可表示无符号类型的所有可能取值,则将无符号操作数转换为有符号操作数所属的类型。

(8)否则，将两个操作数都转换为有符号类型的无符号版本。ANSI C遵循的规则与ISO 2003 C++相同,这与前述规则稍有不同;而传统K&R C的规则又与ANSI C稍有不同。例如，传统C语言总是将float提升为double，即使两个操作数都是float。

前面的列表谈到了整型级别的概念。简单地说,有符号整型按级别从高到低依次为1ong long、long、 int、 short和signed char。无符号整型的排列顺序与有符号整型相同。类型char、 signed char和unsigned char的级别相同。类型bool的级别最低。wchar_t、char16_t和char32_t的级别与其底层类型相同。



#### 传递参数时的转换
正如第7章将介绍的，传递参数时的类型转换通常由C++函数原型控制。然而，也可以取消原型对参数传递的控制，尽管这样做并不明智。在这种情况下，C++将对char和short类型（signed和unsigned）应用整型提升。另外，为保持与传统C语言中大量代码的兼容性，在将参数传递给取消原型对参数传递控制的函数时，C++将float参数提升为double。



这里有两点需要说明。首先，string类定义了一种char *到string的转换功能，这使得可以使用C-风格字符串来初始化string对象。其次是本章前面讨论过的类型为const引用的形参的一个属性。假设实参的类型与引用参数类型不匹配，但可被转换为引用类型，程序将创建一个正确类型的临时变量，使用转换后的实参值来初始化它，然后传递一个指向该临时变量的引用。例如，在本章前面，将int实参传递给const double &形参时，就是以这种方式进行处理的。同样，也可以将实参char *或const char *传递给形参const string &。



#### 参数使用指针，引用，还是值传递？

使用引用参数的主要原因有两个。

1. 程序员能够修改调用函数中的数据对象。
2. 通过传递引用而不是整个数据对象，可以提高程序的运行速度。

当数据对象较大时（如结构和类对象），第二个原因最重要。这些也是使用指针参数的原因。这是有道理的，因为引用参数实际上是基于指针的代码的另一个接口。那么，什么时候应使用引用、什么时候应使用指针呢？什么时候应按值传递呢？下面是一些指导原则：

1. 对于使用传递的值而不作修改的函数。
2. 如果数据对象很小，如内置数据类型或小型结构，则按值传递。
3. 如果数据对象是数组，则使用指针，因为这是唯一的选择，并将指针声明为指向const的指针。
4. 如果数据对象是较大的结构，则使用const指针或const引用，以提高程序的效率。这样可以节省复制结构所需的时间和空间。
5. 如果数据对象是类对象，则使用const引用。类设计的语义常常要求使用引用，这是C++新增这项特性的主要原因。因此，传递类对象参数的标准方式是按引用传递。
6. 如果数据对象是数组，则只能使用指针。
7. 如果数据对象是结构，则使用引用或指针。
8. 如果数据对象是类对象，则使用引用。



#### 强制类型转换
C++还允许通过强制类型转换机制显式地进行类型转换。（C++认识到，必须有类型



#### string char arr

使用strlen()函数计算字符串的长度，并对len成员进行初始化。接着，使用new分配足够的空间来保存字符串，然后将新内存的地址赋给str成员。（**strlen()返回字符串长度，但不包括末尾的空字符，因此构造函数将len加1，使分配的内存能够存储包含空字符的字符串。**）



#### 指针地址

![image-20231109181815368](D:\cpp_work\mdImg\image-20231109181815368.png)

```c++
double *varAddress = &bChar;  //note: 必须以对应的类型来声明 *varAddress的类型，因为*varAddress指的是 double类型的值  varAddress指的是一个变量的地址 

cout << "*varAddress " << *varAddress << endl; // 值
cout << "varAddress " << varAddress << endl; // 地址
```

顺便说一句, *运算符两边的空格是可选的。

传统上,C程序员使用这种格式：

```
int *ptr;
```

这强调\*ptr是一个int类型的值。

而很多C++程序员使用这种格式：

```
int* ptr;
```

这强调的是：int\*是一种类型一指向int的指针。在哪里添加空格对于编译器来说没有任何区别，

您甚至可以这样做：

```
int*ptr;
```

但要知道的是，下面的声明创建一个指针（p1）和一个int变量（p2）：

```
int* p1, p2;
```

对每个指针变量名，都需要使用一个。

![image-20231116173907464](D:\cpp_work\mdImg\image-20231116173907464.png)



**对于指针，需要指出的另一点是，new分配的内存块通常与常规变量声明分配的内存块不同。变量nights和pd的值都存储在被称为栈（stack）的内存区域中，而new从被称为堆（heap）或自由存储区（free store）的内存区域分配内存。第9章将更详细地讨论这一点。**



##### 数组的指针



**int( * pArrAYInt)[6] = &arrInt; // arrInt是一个int数组**

arrInt 可以看成是数组的第一个元素的地址

arrInt[1]  == *(arrInt + 1)  // 访问第二个元素的值，其实执行的操作是等价的

现在来看一看数组表达式stacks[1]。C++编译器将该表达式看作是*（stacks + 1），这意味着先计算数组第2个元素的地址，然后找到存储在那里的值。最后的结果便是stacks [1]的含义（运算符优先级要求使用括号，如果不使用括号，将给*stacks加1，而不是给stacks加1）。
从该程序的输出可知，*（stacks + 1）和stacks[1]是等价的。同样，*（stacks + 2）和stacks[2]也是等价的。

如果使用的是指针，而不是数组名，则C++也将执行同样的转换

```
arrayname[i] becomes *(arrayname + i)
```

在cout和多数C++表达式中，char数组名、char指针以及用引号括起的字符串常量都被解释为字符串第一个字符的地址。

字符串字面值是常量，这就是为什么代码在声明中使用关键字const的原因。



二维数组：

```
ar2 [r] [c]== * (* (ar2 + r) + c)     // same thing
```

```
** &pa == *pa == pa [0] // pa 是一个数组
```

**由于C++将“taco”解释为第一个元素的地址，因此它将“taco”[2]解释为第二个元素的值，即字符c。换句话来说，字符串常量的行为与数组名相同。**



#### 引用变量

```
int rats = 101;

int & rodents = rats;

int * prats = &rats;
```

达式rodents和\*prats都可以同rats互换，而表达式&rodents和prats都可以同&rats互换。从这一点来说，引用看上去很像伪装表示的指针（其中，*解除引用运算符被隐式理解）。除了表示法不同外，还有其他的差别。例如，差别之一是，必须在声明引用时将其初始化，而不能像指针那样，先声明，再赋值：

------



##### 生成临时变量

如果引用参数是const，则编译器将在下面两种情况下生成临时变量：
实参的类型正确，但不是左值；
实参的类型不正确，但可以转换为正确的类型。
左值是什么呢？左值参数是可被引用的数据对象，例如，变量、数组元素、结构成员、引用和解除引用的指针都是左值。非左值包括字面常量（用引号括起的字符串除外，它们由其地址表示）和包含多项的表达式。

##### 右值引用

C++11新增了另一种引用——右值引用（rvalue reference）。这种引用可指向右值，是使用&&声明的：

```
double && rref = std::sgrt(36.00); // not allowed for double &
double j = 15.0;
double && jref = 2.0* j + 18.5;// not allowed for double &
std::cout << rref << '\n';// display 6.0
std::cout << jref << \n';// display 48.5;
```

#### 函数

##### 返回值为引用的好处

如果accumulate()返回一个结构，而不是指向结构的引用，将把整个结构复制到一个临时位置，再将这个拷贝复制给dup。但在返回值为引用时，将直接把team复制到dup，其效率更高。



##### 返回引用时需要注意的问题

返回引用时最重要的一点是，**应避免返回函数终止时不再存在的内存单元引用**。您应避免编写下面这样的代码：

```c++
const free_throws & clone2 (free_throws & ft)
{
	free_throws newguy;//first step to big error
	newguy = ft;// copy info
	return newguy; //return reference to copy
}
```



#### 

##### 函数模板

//template <class AnyType01> // 函数模板，用于参数的自动分配类型，可以传入多类型的参数提供同一种逻辑
template <typename AnyType> // 函数模板，用于参数的自动分配类型，可以传入多类型的参数提供同一种逻辑



##### 定义复杂的函数类型

```c++
/// <summary>
///  定义复杂的函数类型
/// </summary>
typedef const int* (*funcType)(int*, int*); // 定义类型别名
```



#### 头文件中常包含的内容

请不要将函数定义或变量声明放到头文件中。这样做对于简单的情况可能是可行的，但通常会引来麻烦。例如，如果在头文件包含一个函数定义，然后在其他两个文件（属于同一个程序）中包含该头文件，则同一个程序中将包含同一个函数的两个定义，除非函数是内联的，否则这将出错。下面列出了头文件中常包含的内容。

1. 函数原型。
2. 使用#define或const定义的符号常量。
3. 结构声明。
4. 类声明。
5. 模板声明。
6. 内联函数。



##### 注意

，在包含头文件时，我们使用“coordin.h”，而不是<coodin.h>。如果文件名包含在尖括号中，则C++编译器将在存储标准头文件的主机系统的文件系统中查找；但如果文件名包含在双引号中，则编译器将首先查找当前的工作目录或源代码目录（或其他目录，这取决于编译器）。如果没有在那里找到头文件，则将在标准位置查找。**因此在包含自己的头文件时，应使用引号而不是尖括号。**

##### 警告：

在IDE中，不要将头文件加入到项目列表中，也不要在源代码文件中使用#include来包含其他源代码文件。



![image-20231123143927632](D:\PrivateData\document\md图片资源\image-20231123143927632.png)





拒绝多次包含头文件： 多次包含编译时也可能报错

#ifndef CustomCommon
#define CustomCommon

#endif // CustomCommon

在不同的头文件使用不同的宏定义即可减少该错误的出现，比如说改该头文件被其他头文件引用，或者已经被源文件引用



#### 数据保留在内存中的时间

C++使用三种（在C++11中是四种）不同的方案来存储数据，这些方案的区别就在于**数据保留在内存中的时间。**

1. 自动存储持续性：在函数定义中声明的变量（包括函数参数）的存储持续性为自动的。它们在程序开始执行其所属的函数或代码块时被创建，在执行完函数或代码块时，它们使用的内存被释放。C++有两种存储持续性为自动的变量。
2. 静态存储持续性：在函数定义外定义的变量和使用关键字static定义的变量的存储持续性都为静态。它们在程序整个运行过程中都存在。C++有3种存储持续性为静态的变量。
3. 线程存储持续性（C++11）：当前，多核处理器很常见，这些CPU可同时处理多个执行任务。这让程序能够将计算放在可并行处理的不同线程中。如果变量是使用关键字thread_local声明的，则其生命周期与所属的线程一样长。本书不探讨并行编程。
4. 动态存储持续性：用new运算符分配的内存将一直存在，直到使用delete运算符将其释放或程序结束为止。这种内存的存储持续性为动态，有时被称为自由存储（free store）或堆（heap）。



#### 作用域和链接

**作用域（scope）描述了名称在文件（翻译单元）的多大范围内可见。**例如，函数中定义的变量可在该函数中使用，但不能在其他函数中使用；而在文件中的函数定义之前定义的变量则可在所有函数中使用。链接性（linkage）描述了名称如何在不同单元间共享。链接性为外部的名称可在文件间共享，链接性为内部的名称只能由一个文件中的函数共享。自动变量的名称没有链接性，因为它们不能共享。

**C++变量的作用域有多种。作用域为局部的变量只在定义它的代码块中可用。代码块是由花括号括起的一系列语句**。例如函数体就是代码块，但可以在函数体中嵌入其他代码块。**作用域为全局（也叫文件作用域）的变量在定义位置到文件结尾之间都可用**。自动变量的作用域为局部，静态变量的作用域是全局还是局部取决于它是如何被定义的。在函数原型作用域（function prototype scope）中使用的名称只在包含参数列表的括号内可用（这就是为什么这些名称是什么以及是否出现都不重要的原因）。在类中声明的成员的作用域为整个类（参见第10章）。**在名称空间中声明的变量的作用域为整个名称空间（由于名称空间已经引入到C++语言中，因此全局作用域是名称空间作用域的特例）。**



在函数中 声明一个块级作用域中声明和函数中声明同名的一个变量他们的作用域时机和范围

![image-20231123162035641](D:\PrivateData\document\md图片资源\image-20231123162035641.png)



函数调用数据栈

![image-20231123162814002](D:\PrivateData\document\md图片资源\image-20231123162814002.png)

#### 关键字

下面是存储说明符：
auto（在C++11中不再是说明符）；
register；
static；
extern；
thread_local（C++11新增的）；
mutable。

cv限定符：
const；
volatile。



const veep 是一个结构常量

veep的const限定符禁止程序修改veep的成员，但access成员的mutable说明符使得access不受这种限制。

本书不使用volatile或mutable，但将进一步介绍const。



##### typedef

`typedef` 是 C++ 中用于为数据类型定义新名称的关键字。它的主要作用是提高代码的可读性和可维护性，通过为一些复杂的类型或者长名称引入更简洁的别名。下面是 `typedef` 的一些基本用法：

###### 1. 简单别名

```c++
typedef int Number;  // 将 int 定义为 Number
Number x = 5;
```

###### 2. 复杂类型别名

```c++
typedef std::vector<int> IntVector;  // 将 std::vector<int> 定义为 IntVector
IntVector numbers = {1, 2, 3, 4};
```

###### 3. 结构体和类别名

```c++
struct Point {
    int x;
    int y;
};

typedef Point Coordinates;  // 将 struct Point 定义为 Coordinates
Coordinates origin = {0, 0};
```

###### 4. 函数指针类型别名

```c++
typedef void (*FunctionPointer)();  // 将 void (*)() 类型定义为 FunctionPointer
FunctionPointer myFunction = &someFunction;
```

###### 5. 使用 using 代替 typedef（C++11 及更新版本）

```c++
using Number = int;  // 使用 using 也可以定义别名
Number x = 5;
```

`using` 是 C++11 引入的关键字，它可以替代 `typedef` 并且在某些方面更灵活。

使用 `typedef` 或 `using` 的选择通常是个人偏好。`using` 在一些场景下更灵活，并且更容易阅读，但 `typedef` 仍然是有效的。

在 C++17 中，`using` 还可以用于模板别名，使得创建模板别名更加清晰。例如：

```c++
template <typename T>
using Vector = std::vector<T>;

Vector<int> numbers = {1, 2, 3, 4};
```

总体来说，`typedef` 和 `using` 都是为了提高代码的可读性和可维护性而设计的。选择其中之一通常取决于你个人或团队的编程风格和偏好。



##### explicit

在C++98中，关键字explicit不能用于转换函数，但C++11消除了这种限制。

`explicit` 是 C++ 中的关键字，用于修饰类构造函数。使用 `explicit` 关键字可以防止隐式类型转换，强制要求显式调用构造函数。

考虑以下情况：

```c++
cppCopy codeclass MyClass {
public:
    MyClass(int value) {
        // 构造函数实现
    }
};

void someFunction(MyClass obj) {
    // 函数实现
}

int main() {
    someFunction(42);  // 隐式类型转换，调用 MyClass(int value) 构造函数
    return 0;
}
```

上面的代码中，`someFunction` 接受一个 `MyClass` 对象作为参数。在 `main` 函数中，我们调用 `someFunction(42)`，实际上进行了隐式类型转换，将整数 `42` 转换为 `MyClass` 对象。这种情况下，编译器会调用 `MyClass` 的构造函数，生成一个临时对象传递给 `someFunction`。

如果我们在 `MyClass` 的构造函数前加上 `explicit`：

```c++
cppCopy codeclass MyClass {
public:
    explicit MyClass(int value) {
        // 构造函数实现
    }
};

void someFunction(MyClass obj) {
    // 函数实现
}

int main() {
    someFunction(42);  // 编译错误，禁止隐式类型转换
    return 0;
}
```

现在，调用 `someFunction(42)` 将会导致编译错误，因为我们禁止了隐式类型转换。要调用构造函数，必须显式地创建一个 `MyClass` 对象。

使用 `explicit` 关键字可以帮助避免一些潜在的错误，提高代码的清晰性和安全性。





------



其中的大部分已经介绍过了，在同一个声明中不能使用多个说明符，但thread_local除外，它可与static或extern结合使用。前面讲过，在C++11之前，可以在声明中使用关键字auto指出变量为自动变量；但在C++11中，auto用于自动类型推断。关键字register用于在声明中指示寄存器存储，而在C++11中，它只是显式地指出变量是自动的。关键字static被用在作用域为整个文件的声明中时，表示内部链接性；被用于局部声明中，表示局部变量的存储持续性为静态的。关键字extern表明是引用声明，即声明引用在其他地方定义的变量。关键字thread_local指出变量的持续性与其所属线程的持续性相同。**thread_local变量之于线程，犹如常规静态变量之于整个程序。关键字mutable的含义将根据const来解释，因此先来介绍cv-限定符，然后再解释它。**



##### 静态持续变量

和C语言一样，C++也为静态存储持续性变量提供了3种链接性：外部链接性（可在其他文件中访问）、内部链接性（只能在当前文件中访问）和无链接性（只能在当前函数或代码块中访问）。这3种链接性都在整个程序执行期间存在，与自动变量相比，它们的寿命更长。由于静态变量的数目在程序运行期间是不变的，因此程序不需要使用特殊的装置（如栈）来管理它们。编译器将分配固定的内存块来存储所有的静态变量，这些变量在整个程序执行期间一直存在。另外，如果没有显式地初始化静态变量，编译器将把它设置为0。在默认情况下，静态数组和结构将每个元素或成员的所有位都设置为0。

![image-20231123163609311](D:\PrivateData\document\md图片资源\image-20231123163609311.png)

正如前面指出的，所有静态持续变量（上述示例中的global、one_file和count）在整个程序执行期间都存在。在funct1( )中声明的变量count的作用域为局部，没有链接性，**这意味着只能在funct1( )函数中使用它，就像自动变量llama一样。然而，与llama不同的是，即使在funct1( )函数没有被执行时，count也留在内存中**.

由于one_file的链接性为内部，因此只能在包含上述代码的文件中使用它；由于global的链接性为外部，因此可以在程序的其他文件中使用它。



##### 再谈const

在C++（但不是在C语言）中，const限定符对默认存储类型稍有影响。在默认情况下全局变量的链接性为外部的，但const全局变量的链接性为内部的。也就是说，在C++看来，全局const定义（如下述代码段所示）就像使用了static说明符一样。



**C++修改了常量类型的规则，让程序员更轻松。例如，假设将一组常量放在头文件中，并在同一个程序的多个文件中使用该头文件**。那么，预处理器将头文件的内容包含到每个源文件中后，所有的源文件都将包含类似下面这样的定义



> 头文件中定义 const 常量 == 在一个源文件里面使用 const常量 并初始化，其他源文件中使用extern 声明 const 变量 那么使用的也是同一个const变量



在这种情况下，必须在所有使用该常量的文件中使用extern关键字来声明它。**这与常规外部变量不同，定义常规外部变量时，不必使用extern关键字，但在使用该变量的其他文件中必须使用extern。**然而，请记住，鉴于单个const在多个文件之间共享，**因此只有一个文件可对其进行初始化。**
在函数或代码块中声明const时，其作用域为代码块，即仅当程序执行该代码块中的代码时，该常量才是可用的。这意味着在函数或代码块中创建常量时，不必担心其名称与其他地方定义的常量发生冲突。

##### constexpr是C++11新添加的特性

constexpr是C++11新添加的特性，目的是将运算尽量放在编译阶段，而不是运行阶段。constexpr可以修饰变量、函数、结构体等，使它们可以在编译时被求值，从而提高运行时的效率。constexpr的使用有一些限制和要求，例如：

- constexpr变量必须是字面类型（LiteralType），并且必须立即初始化，初始化表达式必须是常量表达式。
- constexpr函数必须只包含一个return语句，不能引用非全局常量，不能调用非constexpr函数，不能有虚函数，不能为void类型，不能有前缀操作符（v++）。
- constexpr结构体的构造函数必须满足constexpr函数的要求，结构体的成员变量必须是字面类型。



```cpp
// 用constexpr修饰一个变量，表示该变量是一个编译时常量
constexpr int x = 10; // OK
constexpr int y = x + 5; // OK
constexpr int z = y * 2; // OK

// 用constexpr修饰一个函数，表示该函数可以在编译时被求值
constexpr int square(int n) {
    return n * n; // 只能包含一个return语句
}

constexpr int a = square(3); // OK，a的值在编译时就被计算为9
int b = 4;
int c = square(b); // OK，但是c的值在运行时才被计算
constexpr int d = square(b); // 错误，b不是一个常量表达式

// 用constexpr修饰一个结构体，表示该结构体可以在编译时被实例化
struct Point {
    int x, y;
    constexpr Point(int x, int y) : x(x), y(y) {} // 构造函数必须是constexpr
    constexpr int dist() { return x * x + y * y; } // 成员函数也可以是constexpr
};

constexpr Point p(3, 4); // OK，p是一个编译时常量
constexpr int e = p.dist(); // OK，e的值在编译时就被计算为25
```

既然可以选择使用全局变量或局部变量，那么到底应使用哪种呢？首先，全局变量很有吸引力——因为所有的函数能访问全局变量，因此不用传递参数。但易于访问的代价很大——程序不可靠。

而，全局变量也有它们的用处。例如，可以让多个函数可以使用同一个数据块（如月份名数组或原子量数组）。外部存储尤其适于表示常量数据，因为这样可以使用关键字const来防止数据被修改。



另外，如果初始化了静态局部变量，则程序只在启动时进行一次初始化。以后再调用函数时，将不会像自动变量那样再次被初始化。



#### 

##### 关键字volatile

表明，即使程序代码没有对内存单元进行修改，其值也可能发生变化。听起来似乎很神秘，实际上并非如此。例如，可以将一个指针指向某个硬件位置，其中包含了来自串行端口的时间或信息。在这种情况下，硬件（而不是程序）可能修改其中的内容。或者两个程序可能互相影响，共享数据。该关键字的作用是为了改善编译器的优化能力。例如，假设编译器发现，程序在几条语句中两次使用了某个变量的值，则编译器可能不是让程序查找这个值两次，而是将这个值缓存到寄存器中。这种优化假设变量的值在这两次使用之间不会变化。如果不将变量声明为volatile，则编译器将进行这种优化；将变量声明为volatile，相当于告诉编译器，不要进行这种优化。





注意：
在程序结束时，由new分配的内存通常都将被释放，不过情况也并不总是这样。例如，在不那么健壮的操作系统中，在某些情况下，请求大型内存块将导致该代码块在程序结束不会被自动释放。最佳的做法是，使用delete来释放new分配的内存。



##### new  

通常，new负责在堆（heap）中找到一个足以能够满足要求的内存块。new运算符还有另一种变体，被称为定位（placement）new运算符，它让您能够指定要使用的位置。程序员可能使用这种特性来设置其内存管理规程、处理需要通过特定地址进行访问的硬件或在特定位置创建对象。
要使用定位new特性，首先需要包含头文件new，它提供了这种版本的new运算符的原型；然后将new运算符用于提供了所需地址的参数。除需要指定参数外，句法与常规new运算符相同。具体地说，使用定位new运算符时，变量后面可以有方括号，也可以没有。下面的代码段演示了new运算符的4种用法：

```c++
double* p01, *p02, * p03, * p04; // 一行声明多个同类型变量， 如果是地址就需要添加地址标识，否则就是声明的double类型的数据

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
//operatorMemoryAddress  运行结果
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
```



#### 命名空间



当随着项目的增大，名称相互冲突的可能性也将增加。使用多个厂商的类库时，可能导致名称冲突。例如，两个库可能都定义了名为List、Tree和Node的类，但定义的方式不兼容。用户可能希望使用一个库的List类，而使用另一个库的Tree类。这种冲突被称为名称空间问题。



第一个需要知道的术语是声明区域（declaration region）。声明区域是可以在其中进行声明的区域。例如，可以在函数外面声明全局变量，对于这种变量，其声明区域为其声明所在的文件。对于在函数中声明的变量，其声明区域为其声明所在的代码块。
第二个需要知道的术语是潜在作用域（potential scope）。变量的潜在作用域从声明点开始，到其声明区域的结尾。因此潜在作用域比声明区域小，这是由于变量必须定义后才能使用。
然而，变量并非在其潜在作用域内的任何位置都是可见的。

```c++
namespace  HiSpace {
	int id;
	char* name;
	void test(int id) {
		cout << "测试命名空间" << id << endl;
	}
}

void testNameSpace() {
	cout << "test name testNameSpace" << endl;
	using HiSpace::id;
	using HiSpace::test;
	id = 500;
	//int id = 300; // 编译不通过，这种方式能够很好的防止重复使用变量名导致的问题
	cout << id << endl;
	test(0);
}

void testNameSpace01() {
	cout << "test name testNameSpace01" << endl;
	using namespace HiSpace;
	id = 500;
	int id = 300; // 编译通过，下方使用的id都是局部变量声明的那个id
	cout << id << endl;
	test(1);
}
```

[假设名称空间和声明区域定义了相同的名称。如果试图使用using声明将名称空间的名称导入该声明区域，则这两个名称会发生冲突，从而出错。如果使用using编译指令将该名称空间的名称导入该声明区域，则局部版本将隐藏名称空间版本。]: 



##### 命名空间的一些使用规范

1. 随着程序员逐渐熟悉名称空间，将出现统一的编程理念。下面是当前的一些指导原则。

2. 使用在已命名的名称空间中声明的变量，而不是使用外部全局变量。

3. 使用在已命名的名称空间中声明的变量，而不是使用静态全局变量。

4. 如果开发了一个函数库或类库，将其放在一个名称空间中。事实上，C++当前提倡将标准函数库放在名称空间std中，这种做法扩展到了来自C语言中的函数。例如，头文件math.h是与C语言兼容的，没有使用名称空间，但C++头文件cmath应将各种数学库函数放在名称空间std中。实际上，并非所有的编译器都完成了这种过渡。

5. 仅将编译指令using作为一种将旧代码转换为使用名称空间的权宜之计。

6. 不要在头文件中使用using编译指令。首先，这样做掩盖了要让哪些名称可用；另外，包含头文件的顺序可能影响程序的行为。如果非要使用编译指令using，应将其放在所有预处理器编译指令#include之后。

7. **导入名称时，首选使用作用域解析运算符或using声明的方法。**

8. 对于using声明，首选将其作用域设置为局部而不是全局。	

   

别忘了，使用名称空间的主旨是简化大型编程项目的管理工作。对于只有一个文件的简单程序，使用using编译指令并非什么大逆不道的事。



#### class 

不必在类声明中使用关键字private，因为这是类对象的默认访问控制：

.h  文件

```c++
#ifndef CPP_H_CustomClass
#define CPP_H_CustomClass

#include <string>
#include <iostream>
class Stock {

private:
	std::string name;
	double price;
	int count;
	void printInfo() { std::cout << "name:" << name << "	price:" << price << " count:" << count << std::endl; };

public:
	bool buy();
	bool shop();
	void update();
	void show();
    void show01() const;
};

#endif // !CPP_H_CustomClass

```

.cpp文件

```c++
#include <iostream>
#include "CustomClass.h"

bool Stock::buy() {
	return true;
}
bool Stock::shop() {
	return true;
}
void Stock::show() {}

void Stock::update() {}
void Stock::show01() const {}
```

##### const 成员函数

当const修饰的不可修改的对象时，该对象只能调用const修饰的成员函数，代表了不会修改对象的成员变量的值 

同样,函数定义的开头应像这样:

```c ++
void stock::show () const// promises not to change invoking object
```

以这种方式声明和定义的类函数被称为const成员函数。就像应尽可能将const引用和指针用作函数形参一样，只要类方法不修改调用对象，就应将其声明为const。从现在开始，我们将遵守这一规则。



##### 类和结构

​	类描述看上去很像是包含成员函数以及public和private可见性标签的结构声明。实际上，C++对结构进行了扩展，使之具有与类相同的特性。它们之间唯一的区别是，**结构的默认访问类型是public，而类为private。** **C++程序员通常使用类来实现类描述，而把结构限制为只表示纯粹的数据对象**（常被称为普通老式数据（POD，Plain Old Data）结构）。

##### 析构函数

如果创建的是静态存储类对象，则其析构函数将在程序结束时自动被调用。如果创建的是自动存储类对象（就像前面的示例中那样），则其析构函数将在程序执行完代码块时（该对象是在其中定义的）自动被调用。如果对象是通过new创建的，则它将驻留在栈内存或自由存储区中，当使用delete来释放内存时，其析构函数将自动被调用。最后，程序可以创建临时对象来完成特定的操作，在这种情况下，程序将在结束对该对象的使用时自动调用其析构函数。

```c++
Stock::~Stock() {
	using namespace std;
	cout << "Stock::~Stock()" << endl;
}
```





##### 类对象的赋值

下面的语句表明可以将一个对象赋给同类型的另一个对象：stock2 = stock1;// object assignment

与给结构赋值一样，在默认情况下，给类对象赋值时，**将把一个对象的成员复制给另一个**。在这个例子中，stock2原来的内容将被覆盖。
注意：
	在默认情况下，将一个对象赋给同类型的另一个对象时，C++将源对象的每个数据成员的内容复制到目标对象中相应的数据成员中。

构造函数不仅仅可用于初始化新对象。例如，该程序的main( )中包含下面的语句：

```c++
stock1 = Stock("Nifty Foods", 10, 50.0);
```

stock1对象已经存在，因此这条语句不是对stock1进行初始化，而是将新值赋给它。这是通过让构造程序创建一个新的、临时的对象，然后将其内容复制给stock1来实现的。随后程序调用析构函数，以删除该临时对象

```c++
void testClassFunc() {
    Stock stock = Stock("jiujiujiu", 0.0); // 
    stock.buy();
    stock.shop();
    stock.update();
    stock.show();

    Stock stock01 = { "jiujiujiu01" };
    const Stock stock02{ "但是" };
    //Stock stock01;//类"Stock"不存在默认构造函数
    // 
    // 
    //DefaultConstructorClass  *cls01; // no valid
    DefaultConstructorClass  cls01;
    DefaultConstructorClass  cls02;
    DefaultConstructorClass* cls03 = new DefaultConstructorClass();
    const DefaultConstructorClass cls04{};

    //cls01->test();
    cls02 = cls01; // 把cls01的成员的值赋值到cls02
    cls02.test();
    cls03->test();
    cls02 = DefaultConstructorClass(); // DefaultConstructorClass()声明了一个临时对象，赋值后就被销毁了

    stock02.show01();
    //stock02.show(); // const 修饰的对象只能调用const修饰的成员函数，代表该函数不会修改对象的成员的值

    cout << "测试引用赋值修改" << endl;
    Stock& stock05 = stock;
    cout << "测试引用赋值修改 over!!!"<< "   &stock05:" << &stock05 << "	&stock02:" << &stock02 << "		&stock:" << &stock << endl;
    stock05.show01();
    stock05 = stock02; // 把stock02的值赋值给了 stock，因为stock05是stock的引用所以他们的地址和值是一致的，最终他们的name属性的值都是 但是
    stock05.show01();
    stock.show01();
    cout << "测试引用赋值修改 over!!!"<< "   &stock05:" << &stock05 << "	&stock02:" << &stock02 << "		&stock:" << &stock << endl;


    cout << "excute testClassFunc over!!!" << endl;
}
```



##### 使用引用类型进行赋值操作：

```c++
 Stock& stock05 = stock;
    cout << "测试引用赋值修改 over!!!"<< "   &stock05:" << &stock05 << "	&stock02:" << &stock02 << "		&stock:" << &stock << endl;
    stock05.show01();
    stock05 = stock02; // 把stock02的值赋值给了 stock，因为stock05是stock的引用所以他们的地址和值是一致的，最终他们的name属性的值都是 但是
    stock05.show01();
    stock.show01();
    cout << "测试引用赋值修改 over!!!"<< "   &stock05:" << &stock05 << "	&stock02:" << &stock02 << "		&stock:" << &stock << endl;

```

![image-20231206181057532](D:\cpp_work\mdImg\image-20231206181057532.png)



##### const Stock* tempStock 地址使用const修饰

在 `const Stock* tempStock` 中，`const` 关键字用于表示指针指向的对象是常量，即不能通过该指针修改对象的值。这种修饰常用于指示函数中参数的只读性，或者用于确保在函数中不会意外地修改传入的对象。

在你的代码中，`const Stock* tempStock` 表示 `tempStock` 是一个指向 `Stock` 对象的常量指针。这意味着你不能通过 `tempStock` 指针修改指向的 `Stock` 对象的值。

例如，在下面的函数中：

```c++
void someFunction(const Stock* tempStock) {
    // 不能通过 tempStock 修改 Stock 对象的值
    // 但可以使用 tempStock 访问 Stock 对象的成员（如果它们是 const 方法的话）
}
```



##### this

每个成员函数（包括构造函数和析构函数）都有一个this指针。this指针指向调用对象。如果方法需要引用整个调用对象，则可以使用表达式 * this。在函数的括号后面使用const限定符将this限定为const，这样将不能使用this来修改对象的值。
然而，要返回的并不是this，因为this是对象的地址，而是对象本身，即 * this（将解除引用运算符*用于指针，将得到指针指向的值）。现在，可以将 * this作为调用对象的别名来完成前面的方法定义。



##### enum class

C++11作用域内枚举的底层类型为int。另外，还提供了一种语法，可用于做出不同的选择：

```c++
// underlying type for pizza is short 
enum class : short pizza (Small, Medium, Large, XLarge);
```

:short将底层类型指定为short。底层类型必须为整型。在C++11中，也可使用这种语法来指定常规枚举的底层类型，但如果没有指定，编译器选择的底层类型将随实现而异。





#### 运算符重载

例如，operator +( )重载+运算符，operator *( )重载*运算符。op必须是有效的C++运算符，不能虚构一个新的符号。例如，不能有operator@( )这样的函数，因为C++中没有@运算符。然而，operator 函数将重载[ ]运算符，因为[ ]是数组索引运算符。例如，假设有一个Salesperson类，并为它定义了一个operator +( )成员函数，以重载+运算符，以便能够将两个Saleperson对象的销售额相加，则如果district2、sid和sara都是Salesperson类对象，便可以编写这样的等式：

```c++
district2 = sid + sara;
```

编译器发现，操作数是Salesperson类对象，因此使用相应的运算符函数替换上述运算符：

```c++
district2 = sid.operator+ (sara);
```

示例

```c++
Time Time::sum(const Time& time) const {
	Time sumTime = Time();
	sumTime._minute = time._minute + _minute;
	sumTime._hour = time._hour + _hour + sumTime._minute / 60;
	sumTime._minute %= 60;
	return sumTime;
}

Time Time::operator +(const Time& time) const {
	return sum(time);
}
```

```c++
Time time;
time.reset(24, 39);

Time time01 = Time(1, 52);
time.show();
time01.show();
Time sum = time.sum(time01);
sum.show();

Time all = sum + time + time01; // 运算符重载
all.show();
Time all01 = sum.operator+(time).operator+(time01); // 运算符重载
all01.show();
```

1．重载后的运算符必须至少有一个操作数是用户定义的类型，这将防止用户为标准类型重载运算符。因此，不能将减法运算符（−）重载为计算两个double值的和，而不是它们的差。虽然这种限制将对创造性有所影响，但可以确保程序正常运行。
2．使用运算符时不能违反运算符原来的句法规则。例如，不能将求模运算符（%）重载成使用一个操作数：
同样，不能修改运算符的优先级。因此，如果将加号运算符重载成将两个类相加，则新的运算符与原来的加号具有相同的优先级。
3．不能创建新运算符。例如，不能定义operator ** ( )函数来表示求幂。

4．**不能重载下面的运算符。**
sizeof：sizeof运算符。
.：成员运算符。
. *：成员指针运算符。

::：作用域解析运算符。
?:：条件运算符。
typeid：一个RTTI运算符。
const_cast：强制类型转换运算符。
dynamic_cast：强制类型转换运算符。
reinterpret_cast：强制类型转换运算符。
static_cast：强制类型转换运算符。

**5．表11.1中的大多数运算符都可以通过成员或非成员函数进行重载，但下面的运算符只能通过成员函数进行重载。**
=：赋值运算符。
( )：函数调用运算符。
[ ]：下标运算符。
->：通过指针访问类成员的运算符。



在 C++ 中，重载运算符 `=`, `()`, `[]`, 和 `->` 时，有一些限制和规定。下面是一些通用的注意事项和示例：

### 1. `=` 运算符：

- **限制：** 重载 `=` 运算符的返回类型通常应该是引用，并且参数列表应该是相同类的引用或者相应的类型。

- **示例：**

  ```c++
  cppCopy codeclass MyClass {
  public:
      int data;
  
      // 重载 = 运算符
      MyClass& operator=(const MyClass& other) {
          if (this != &other) {
              data = other.data;
          }
          return *this;
      }
  };
  
  int main() {
      MyClass obj1, obj2;
      obj1.data = 42;
      obj2.data = 24;
  
      // 使用重载后的 =
      obj1 = obj2;
  
      return 0;
  }
  ```

### 2. `()` 运算符：

- **限制：** 重载 `()` 运算符使对象可以像函数一样被调用，返回值和参数列表可以根据需要定义。

- **示例：**

  ```c++
  cppCopy codeclass MyFunction {
  public:
      int operator()(int x, int y) {
          return x + y;
      }
  };
  
  int main() {
      MyFunction addFunction;
  
      // 使用重载后的 ()
      int result = addFunction(3, 4);
  
      return 0;
  }
  ```

### 3. `[]` 运算符：

- **限制：** 重载 `[]` 运算符用于类对象的索引访问，通常返回引用，参数列表可以是整数或其他合适的类型。

- **示例：**

  ```c++
  cppCopy codeclass MyArray {
  private:
      int data[5];
  
  public:
      // 重载 [] 运算符
      int& operator[](int index) {
          return data[index];
      }
  };
  
  int main() {
      MyArray arr;
      arr[2] = 42;
  
      // 使用重载后的 []
      int value = arr[2];
  
      return 0;
  }
  ```

### 4. `->` 运算符：

- **限制：** 重载 `->` 运算符通常用于自定义智能指针等场景，返回值应该是指向类对象的指针。

- **示例：**

  ```c++
  cppCopy codeclass MySmartPointer {
  private:
      MyClass* ptr;
  
  public:
      MySmartPointer(MyClass* obj) : ptr(obj) {}
  
      // 重载 -> 运算符
      MyClass* operator->() {
          return ptr;
      }
  };
  
  int main() {
      MyClass obj;
      obj.data = 42;
  
      MySmartPointer smartPtr(&obj);
  
      // 使用重载后的 ->
      int value = smartPtr->data;
  
      return 0;
  }
  ```

这些示例只是简单的演示，并根据具体情况可能需要更复杂的实现。在实际应用中，需要根据类的设计和需求来灵活地选择如何重载这些运算符。



#### 友元

在C++中，`friend` 关键字用于声明一个函数或类是另一个类的友元。友元函数或友元类具有访问其它类的私有成员的权限，即使这些成员在一般情况下是不可访问的。

`friend` 关键字可以应用于以下情况：

1. **友元函数：** 一个非成员函数可以被声明为某个类的友元函数，从而允许该函数访问类的私有成员。

   ```c++
   cppCopy codeclass MyClass {
   private:
       int privateData;
   
   public:
       MyClass(int value) : privateData(value) {}
   
       // 友元函数声明
       friend void displayPrivateData(const MyClass& obj);
   };
   
   // 友元函数定义
   void displayPrivateData(const MyClass& obj) {
       std::cout << "Private Data: " << obj.privateData << std::endl;
   }
   ```

2. **友元类：** 一个类可以被声明为另一个类的友元，这样它就能够访问另一个类的私有成员。

   ```c++
   cppCopy codeclass FriendClass {
   public:
       void accessPrivateMember(const MyClass& obj) {
           std::cout << "Private Data from FriendClass: " << obj.privateData << std::endl;
       }
   };
   
   class MyClass {
   private:
       int privateData;
   
       // 友元类声明
       friend class FriendClass;
   
   public:
       MyClass(int value) : privateData(value) {}
   };
   ```



**请注意，滥用友元机制可能会破坏封装性，因此应该谨慎使用。友元的主要作用是在某些特殊情况下提供对私有成员的访问权限，而不是作为一种常规设计模式。**

您知道，C++控制对类对象私有部分的访问。通常，公有类方法提供唯一的访问途径，但是有时候这种限制太严格，以致于不适合特定的编程问题。在这种情况下，C++提供了另外一种形式的访问权限：友元。友元有3种：

##### 友元函数；

原型中使用 （即.h 头文件）friend 修饰声明

```c++
std::ostream& operator << (std::ostream& os, Time& time) {
	os << time._hour << " -->hour     " << time._minute << "  --> minute \n";
	return os;
}

// 成员函数重载运算符
Time Time::operator *(double mul) const {
	Time result;
	result._minute = _minute * mul;
	result._hour = _hour * mul + result._minute / 60;
	result._minute %= 60;
	return result;
}

// 非成员函数实现重载运算符，由于要访问私有属性，所以该函数是友元函数
Time operator*(double mul, Time& time) {
	Time result;
	result._minute = time._minute * mul;
	result._hour = time._hour * mul + result._minute / 60;
	result._minute %= 60;
	return result;
}
```

**非成员版本的重载运算符函数所需的形参数目与运算符使用的操作数数目相同；而成员版本所需的参数数目少一个，因为其中的一个操作数是被隐式地传递的调用对象。**



友元类；
友元成员函数。



#### 类转换

类转换一种方式是通过构造函数自动类型转换

```c++
namespace ClassType {
	class ClassTypeTrans {
	private:
		double value;
	public :
		ClassTypeTrans();
		ClassTypeTrans(int temp);

		operator double() const;
		~ClassTypeTrans();

	};
}

ClassType::ClassTypeTrans ctt = 10;
```

转换函数自动类型转换

```c++
ClassType::ClassTypeTrans::operator double() const {
	return value;
}
std::cout << "ctt == operator double : " << ctt << std::endl; // 使用了 转换函数后  ctt被转换成了double类型所以就不会报错了
```



在C++中，int和double值都可以被赋给long变量，所以编译器使用任意一个转换函数都是合法的。编译器不想承担选择转换函数的责任。然而，如果删除了这两个转换函数之一，编译器将接受这条语句。例如，假设省略了double定义，则编译器将使用int转换，将poppins转换为一个int类型的值。然后在将它赋给gone时，将int类型值转换为long类型。
当类定义了两种或更多的转换时，仍可以用显式强制类型转换来指出要使用哪个转换函数。可以使用下面任何一种强制类型转换表示法：

```c++
long gone = (double) poppins; //use double conversion
long gone = int (poppins);// use int conversion
```







### boost

关于boost库的引入 暂时只有一种方式其他的csdn上的方案尝试了没能实现

1. 去官网下载boost库 https://boostorg.jfrog.io/artifactory/main/release/1.84.0/source/

2. 解压文件
3. vs中在选择 项目-> 属性-> vc++目录 -> 包含目录 -> 填入解压的目录路径即可
4. #include <boost/xxx>

![image-20240124170528977](D:\cpp_work\mdImg\image-20240124170528977.png)



```c++
/** 根据引用计数释放new的对象  内部维持一个引用计数器 */
boost::shared_ptr<ClassType::ClassTypeTrans> ctt02(new ClassType::ClassTypeTrans(250));
std::cout << "ctt02.use_count() : " << ctt02.use_count() << std::endl;
boost::shared_ptr<ClassType::ClassTypeTrans> ctt03 = ctt02; 
std::cout << "ctt03.use_count() : " << ctt03.use_count() << std::endl;
ctt02.reset();
std::cout << "ctt03.use_count() : " << ctt03.use_count() << std::endl;
ctt03.reset();
```

![image-20240125144722665](D:\cpp_work\mdImg\image-20240125144722665.png)