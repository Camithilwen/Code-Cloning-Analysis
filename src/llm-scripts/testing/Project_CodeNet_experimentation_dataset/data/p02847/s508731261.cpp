#include<iostream>
#include<map>
using namespace std;

int main(){
    map<string, int> weekday;
    weekday["SUN"] = 0;
    weekday["MON"] = 1;
    weekday["TUE"] = 2;
    weekday["WED"] = 3;
    weekday["THU"] = 4;
    weekday["FRI"] = 5;
    weekday["SAT"] = 6;

    string day;
    std::cin >> day;

    std::cout << 7 - weekday[day];

}