#pragma once

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

class Time
{
private:
    int hour;
    int minute;

public:
    void setHour(int hour);
    void setMinute(int minute);

    int getHour()const;
    int getMinute()const;

    Time();
    Time(int hour, int minute);
    Time(const Time &other);
    Time &operator=(const Time &other);

    const char* returnTime()const;
    
    const char* getTimeOfDay()const;
    void addMinutes(int addMinutes);
    int minutesSinceMidnight()const;
};