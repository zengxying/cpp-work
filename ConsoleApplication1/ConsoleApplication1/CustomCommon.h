#ifndef CustomCommon
#define CustomCommon
struct FuncStruct
{
	int  id;
	double time;
	double price;
};
//template <class AnyType01> // ����ģ�壬���ڲ������Զ��������ͣ����Դ�������͵Ĳ����ṩͬһ���߼�
template <typename AnyType> // ����ģ�壬���ڲ������Զ��������ͣ����Դ�������͵Ĳ����ṩͬһ���߼�

AnyType& change(AnyType& source01, AnyType& source02);
/// <summary>
/// ���������� ����һ������ƽ��
/// </summary>
/// <param name="a"></param>
/// <returns></returns>
/// 
/// 
inline int customePower(int a) { return a * a; };

#endif // CustomCommon



