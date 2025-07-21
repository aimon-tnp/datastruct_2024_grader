#include <iostream>

using namespace std;

int main(){
    string input;
    getline(cin, input);

    size_t spacebar = input.find(" "); // find spaceBar's index (ex. 0 30 -> [0,1] & [2::])
    int hour = stoi(input.substr(0,spacebar));
    int minute = stoi(input.substr(spacebar + 1));

    int extraMinute, extraHour;
    cin >> extraMinute;

    minute += extraMinute;
    if (minute >= 60){ // coverting extra minutes into hours
        extraHour = minute / 60;
        minute %= 60;
        hour += extraHour;
    }
    
    hour %= 24; // if more than 24 hours -> %

    if (hour < 10){
        cout << "0" << hour << " ";
    } else {
        cout << hour << " ";
    }

    if (minute < 10){
        cout << "0" << minute << endl;
    } else {
        cout << minute << endl;
    }

    return 0;
}