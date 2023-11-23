#ifndef CustomCommon
#define CustomCommon
struct FuncStruct
{
	int  id;
	double time;
	double price;
};
//template <class AnyType01> // 函数模板，用于参数的自动分配类型，可以传入多类型的参数提供同一种逻辑
template <typename AnyType> // 函数模板，用于参数的自动分配类型，可以传入多类型的参数提供同一种逻辑

AnyType& change(AnyType& source01, AnyType& source02);
/// <summary>
/// 内联函数， 计算一个数的平方
/// </summary>
/// <param name="a"></param>
/// <returns></returns>
/// 
/// 
inline int customePower(int a) { return a * a; };

#endif // CustomCommon



