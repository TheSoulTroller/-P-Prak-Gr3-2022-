#include "Time.h"

void Time::setHour(int hour)
{
    try
    {
        if (hour < 0 || hour > 23)
        {
            throw "Invalid hour!";
        }
        this->hour = hour;
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
}
void Time::setMinute(int minute)
{
    try
    {
        if (minute < 0 || minute > 59)
        {
            throw "Invalid minutes!";
        }
        this->minute = minute;
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
}

int Time::getHour() const
{
    return this->hour;
}
int Time::getMinute() const
{
    return this->minute;
}

Time::Time()
{
    this->hour = -1;
    this->minute = -1;
}
Time::Time(int hour, int minute)
{
    setHour(hour);
    setMinute(minute);
}
Time::Time(const Time& other)
{
    setHour(other.getHour());
    setMinute(other.getMinute());
}
Time& Time::operator=(const Time& other)
{
    if(this != &other)
    {
        setHour(other.getHour());
        setMinute(other.getMinute());
    }
    return *this;
}

const char* Time::returnTime()const
{
    
    char *time = new char[6];
    sprintf(time, "%02d:%02d", this->hour, this->minute);
    // %02d means an integer, left padded with zeros up to 2 digits.

    // %02d performs decimal integer conversion d , formatted with 
    // zero padding ( 0 flag), with width 2 . Thus, an int argument 
    // whose value is say 7 , will be formatted into "07" as a String.

    return time;
}

const char* Time::getTimeOfDay()const
{
    if(this->hour >= 5 && this->hour <= 11) return "Morning!";
    if(this->hour == 12 && this->minute == 0) return "Exactly Noon!";
    if(this->hour == 0 && this->minute == 0) return "Exactly Midnight!";
    if(this->hour >= 18 && this->hour <= 23) return "Evening!";
    if(this->hour >= 0 && this->hour <= 4) return "Night!";
    if(this->hour >= 12 && this->hour <= 17) return "Afternoon!";
}
void Time::addMinutes(int minutes)
{
    int newMinute = this->minute + minutes;
    int newHour = this->hour;
    while (newMinute >= 60)
    {
        newMinute -= 60;
        newHour++;
    }
    while (newHour >= 24)
    {
        newHour -= 24;
    }

    setHour(newHour);
    setMinute(newMinute);
}
int Time::minutesSinceMidnight() const
{
    char buffer[128];
    sprintf(buffer, "\n%d hours are %d minutes then we add %d more minutes and we get ", this->hour, this->hour*60, this->minute);
    cout << buffer;
    return (hour * 60) + minute;
}

int main()
{
    Time t1(10, 0);
    Time t2(0, 0);
    Time t3(17, 59);
    Time t4(8, 45);

    cout << "t1: " << t1.returnTime() << " -> " << t1.getTimeOfDay() << endl;
    cout << "t2: " << t2.returnTime() << " -> " << t2.getTimeOfDay() << endl;
    cout << "t3: " << t3.returnTime() << " -> " << t3.getTimeOfDay() << endl;
    cout << "t4: " << t4.returnTime() << " -> " << t4.getTimeOfDay() << endl;

    cout << "\nt1: " << t1.returnTime();
    t1.addMinutes(256);
    cout << "\tNew t1: " << t1.returnTime();
    cout << t1.minutesSinceMidnight() << endl;
    
    return 0;
}
