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
	cout << "销毁time对象" << endl;
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
/// 来看一下Sum( )函数的代码。注意参数是引用，但返回类型却不是引用。将参数声明为引用的目的是为了提高效
/// 率。如果按值传递Time对象，代码的功能将相同，但传递引用，速度将更快，使用的内存将更少。
/// 然而，返回值不能是引用。因为函数将创建一个新的Time对象（sum），来表示另外两个Time对象的和。返回对象
/// （如代码所做的那样）将创建对象的副本，而调用函数可以使用它。然而，如果返回类型为Time& ，则引用的将
/// 是sum对象。但由于sum对象是局部变量，在函数结束时将被删除，因此引用将指向一个不存在的对象。使用返回
/// 类型Time意味着程序将在删除sum之前构造它的拷贝，调用函数将得到该拷贝。
/// </summary>
/// <param name="time">其他时间对象</param>
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