#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    map<string, int> day;
    day["SUN"] = 7;
    day["MON"] = 6;
    day["TUE"] = 5;
    day["WED"] = 4;
    day["THU"] = 3;
    day["FRI"] = 2;
    day["SAT"] = 1;

    string s;
    cin >> s;
    cout << day[s] << endl;
    return 0;
}
