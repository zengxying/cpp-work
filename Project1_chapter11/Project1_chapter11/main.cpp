#include "mytime.h";
#include <iostream>;
#include <fstream>;
int main() {

	Time time;
	time.reset(24, 39);

	Time time01 = Time(1, 52);
	time.show();
	time01.show();
	Time sum = time.sum(time01);
	sum.show();

	Time all = sum + time + time01; // ���������
	all.show();
	Time all01 = sum.operator+(time).operator+(time01); // ���������
	all01.show();

	all = 2 * all; // ʹ������Ԫ������  operator * (2, all)
	all.show();
	all01 = all01 * 2; // ʹ����all01.operator *(2) �����������
	all01.show();

	/// �����صĺ���������һ��ostream���͵Ķ��������
	std::cout << "ceshiwenzi " << all << "end \n"; //  << "end \n" �����ټ�����仰�ͱ����� Ӧ�������صķ���û�з���һ��ostream�������Բ�����ʽ����

	std::ofstream osf;
	osf.open("obj.txt");
	osf << time01;  // Ҳ��ostream���͵�Ҳ���������������
	osf.close();

}