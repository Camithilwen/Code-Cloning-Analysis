#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <utility>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    Int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<Int> v(n);
    v[0] = 0;
    for (Int i = 1; i < n; ++i) {
        if (s[i - 1] == 'A' && s[i] == 'C') {
            v[i] = v[i - 1] + 1;
        } else {
            v[i] = v[i - 1];
        }
    }
    for (Int i = 0; i < q; ++i) {
        Int l, r;
        cin >> l >> r;
        cout << v[r - 1] - v[l - 1] << endl;
    }
    return 0;
}

