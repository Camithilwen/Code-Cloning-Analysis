#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    Int a, b, c, d, e, k;
    cin >> a >> b >> c >> d >> e >> k;
    if (e - a <= k) {
        cout << "Yay!" << endl;
    } else {
        cout << ":(" << endl;
    }
    return 0;
}

