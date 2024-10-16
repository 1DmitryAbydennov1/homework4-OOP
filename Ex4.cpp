#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

class Time 
{
private:
    int mHours, mMinutes, mSeconds;

    void normalize() 
    {
        mMinutes += mSeconds / 60;
        mSeconds %= 60;
        mHours += mMinutes / 60;
        mMinutes %= 60;
        mHours %= 24;
    }

public:
    Time(int hours = 0, int minutes = 0, int seconds = 0)
        : mHours(hours), mMinutes(minutes), mSeconds(seconds) 
    {
        normalize();
    }

    Time(const std::string& s) 
    {
        std::stringstream ss(s);
        char colon;
        ss >> mHours >> colon >> mMinutes >> colon >> mSeconds;
        normalize();
    }

    Time operator+(Time b) const 
    {
        return Time(mHours + b.mHours, mMinutes + b.mMinutes, mSeconds + b.mSeconds);
    }

    int hours() const { return mHours; }
    int minutes() const { return mMinutes; }
    int seconds() const { return mSeconds; }

    friend std::ostream& operator<<(std::ostream& out, Time t) 
    {
        out << std::setw(2) << std::setfill('0') << t.mHours << ":"
            << std::setw(2) << std::setfill('0') << t.mMinutes << ":"
            << std::setw(2) << std::setfill('0') << t.mSeconds;
        return out;
    }
};

std::vector<Time> getTimesFromString(const std::string& s) 
{
    std::vector<Time> times;
    std::stringstream ss(s);
    std::string timeStr;
    while (ss >> timeStr) 
    {
        times.push_back(Time(timeStr));
    }
    return times;
}

Time sumTimes(const std::vector<Time>& v) 
{
    Time total;
    for (const auto& t : v) 
    {
        total = total + t;
    }
    return total;
}

int main() 
{
    std::vector<Time> v = getTimesFromString("11:20:05 05:45:30 22:10:45");
    v.push_back(Time("01:10:30"));
    Time s = sumTimes(v);
    std::cout << s << std::endl;
    return 0;
}
