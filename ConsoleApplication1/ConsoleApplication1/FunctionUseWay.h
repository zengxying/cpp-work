#ifndef CPP_H_FunctionUseWay
#define CPP_H_FunctionUseWay
#include "CustomCommon.h"
/*  �����Щ����û�����ⲿʹ�ÿ��Բ���ͷ�ļ���������
FuncStruct& clone(FuncStruct source);
void testFuncOverload(const double& x);
void testFuncOverload(double& x);
void testFuncOverload01(const FuncStruct& fs);
void testFuncOverload01(FuncStruct& fs);

//void testFuncOverload02(const FuncStruct fs);
//void testFuncOverload02(FuncStruct fs);
const FuncStruct & clone01(const FuncStruct & source); 
void test_2dimensional_array_params2(int(*arr)[4], int size);
void test_2dimensional_array_params(int arr[][4], int size);
void testFuncConstParams(const int arr[], int size);
void testFuncParamsToFunc(int (*func)(int*, int*));


int testFuncArrStartPointerToEndPointer(int* start, int* end);
int calculateNumPower(int value, int power = 2); // �������Ĭ�ϲ�����ֵ �����ts����
*/
template <typename AnyType>
AnyType& change(AnyType& source01, AnyType& source02);
void excuteFunctionUseWayMain();

#endif