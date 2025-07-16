#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

int main(void) {
    string week[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    string s;
    cin >> s;
    for (Int i = 0; i < 7; ++i) {
        if (week[i] == s) {
            cout << 7 - i << endl;
        }
    }
    return 0;
}
