#include<iostream>
#include<iomanip>
#include<stdexcept>

using namespace std;

class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		setTime(hour, minute, second);
	}
	void setTime(int h, int m, int s)
	{
		setHour(h);
		setMinute(m);
		setSecond(s);
	}
	void setHour(int h)
	{
		if (h >= 0 && h < 24)
			hour = h;
		else
			throw invalid_argument("hour must be 0-23");
	}
	void setMinute(int m)
	{
		if (m >= 0 && m < 60)
			minute = m;
		else
			throw invalid_argument("minute must be 0-59");
	}
	void setSecond(int s)
	{
		if (s >= 0 && s < 60)
			second = s;
		else
			throw invalid_argument("second must be 0-59");
	}
	unsigned int getHour() const
	{
		return hour;
	}
	unsigned int getMinute() const
	{
		return minute;
	}
	unsigned int getSecond() const
	{
		return second;
	}
	void printUniversal() const
	{
		cout << setfill('0') << setw(2) << getHour() << ":" << setw(2) << getMinute() << ":" << setw(2) << getSecond() << endl;
	}
	void printStandard() const
	{
		cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << setfill('0') << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2) << getSecond() << (hour < 12 ? "AM" : "PM") << endl;
	}
	void tick()
	{
		if (second == 59)
		{
			second = 0;
			if (minute == 59)
			{
				minute = 0;
				if (hour = 23)
				{
					hour = 0;
				}
				else
					hour += 1;
			}
			else
				minute += 1;
		}
		else
			second += 1;
	}
private:
	unsigned int hour;
	unsigned int minute;
	unsigned int second;
};

int main()
{
	Time a(9, 29, 56);
	Time b(11, 59, 56);
	Time c(23, 59, 56);

	for (int i = 0; i < 9; i++)
	{
		a.printStandard();
		a.tick();
	}
	cout << endl;
	for (int i = 0; i < 9; i++)
	{
		b.printStandard();
		b.tick();
	}
	cout << endl;
	for (int i = 0; i < 9; i++)
	{
		c.printStandard();
		c.tick();
	}
	cout << endl;

	return 0;
}