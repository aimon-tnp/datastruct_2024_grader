#include <iostream>
#include <iomanip>

int main(){
    int hour, minute;
    int extraMinute, extraHour;

    std::cin >> hour >> minute;
    std::cin >> extraMinute;

    minute += extraMinute;
    extraHour = minute / 60;
    minute %= 60;
    hour += extraHour;
    hour %= 24;

    std::cout << std::setw(2) << std::setfill('0')  << hour << " ";
    std::cout << std::setw(2) << std::setfill('0')  << minute << std::endl;
    return 0;
}