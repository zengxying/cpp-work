#ifndef CPP_H_MY_TIME
#define CPP_H_MY_TIME
#include <iostream>;
class Time {
private:
	int _hour;
	int _minute;
public:
	Time();
	~Time();
	Time(int hour, int minute = 0);
	// Time(int hour = 0, int minute = 0); �����������ᵼ�º�û�в����Ĺ��캯����ͻ����ʹ��ʱ�ᱨ����ʾû�ж�Ӧ�Ĺ��캯��
	void addHour(int hour);
	void addMinute(int minute);
	void reset(int hour, int minute);
	void show();
	Time operator +(const Time& time) const;
	Time sum(const Time& time) const;
	
	friend std::ostream& operator << (std::ostream& os, Time& time);
	/// <summary>
	/// ��Ԫ����
	/// </summary>
	friend Time operator*(double mul, Time& time);

	Time operator *(double mul) const;  // time * mul valid / mul * time invalid


};
#endif

