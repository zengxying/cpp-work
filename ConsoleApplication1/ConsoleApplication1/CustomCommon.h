#ifndef CPP_H_CustomCommon
#define CPP_H_CustomCommon
struct FuncStruct
{
	int  id;
	double time;
	double price;
};
//template <class AnyType01> // ����ģ�壬���ڲ������Զ��������ͣ����Դ�������͵Ĳ����ṩͬһ���߼�
//template <typename AnyType> // ����ģ�壬���ڲ������Զ��������ͣ����Դ�������͵Ĳ����ṩͬһ���߼�

//
/// <summary>
/// ���������� ����һ������ƽ��
/// </summary>
/// <param name="a"></param>
/// <returns></returns>
/// 
/// 
inline int customePower(int a) { return a * a; };

#endif // CustomCommon



