#include "mytime.h";
#include <iostream>;


using namespace std;
Time::Time() {
	_hour = 0;
	_minute = 0;
}

Time::Time(int hour, int minute) {
	this->_hour = hour;
	this->_minute = minute;
}

Time::~Time() {
	cout << "����time����" << endl;
}

void Time::reset(int hour, int minute) {
	this->_hour = hour;
	this->_minute = minute;
}

void Time::addHour(int hour) {
	_hour += hour;
}

void Time::addMinute(int minute) {
	_minute += minute;
}

/// <summary>
/// ����һ��Sum( )�����Ĵ��롣ע����������ã�����������ȴ�������á�����������Ϊ���õ�Ŀ����Ϊ�����Ч
/// �ʡ������ֵ����Time���󣬴���Ĺ��ܽ���ͬ�����������ã��ٶȽ����죬ʹ�õ��ڴ潫���١�
/// Ȼ��������ֵ���������á���Ϊ����������һ���µ�Time����sum��������ʾ��������Time����ĺ͡����ض���
/// �����������������������������ĸ����������ú�������ʹ������Ȼ���������������ΪTime& �������õĽ�
/// ��sum���󡣵�����sum�����Ǿֲ��������ں�������ʱ����ɾ����������ý�ָ��һ�������ڵĶ���ʹ�÷���
/// ����Time��ζ�ų�����ɾ��sum֮ǰ�������Ŀ��������ú������õ��ÿ�����
/// </summary>
/// <param name="time">����ʱ�����</param>
/// <returns></returns>
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


void Time::show() {
	cout << "this.time.hour:" << _hour << "  this.time.minute:" << _minute << endl;
}