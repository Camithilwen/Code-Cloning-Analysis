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
    // 問題番号, 正解したかどうか, WAの個数
    map<Int, pair<Int, Int> > mp;
    Int n, m;
    cin >> n >> m;

    for (Int i = 0; i < m; ++i) {
        Int p;
        string s;
        cin >> p >> s;
        --p;
        if (mp[p].first == 0) { 
            if (s == "AC") {
                mp[p].first = 1;
            } else {
                ++mp[p].second;
            }
        }
    }

    Int ac_num = 0;
    Int penalty_num = 0;
    for (Int i = 0; i < n; ++i) {
        if (mp[i].first != 0) {
            ac_num += mp[i].first;
            penalty_num += mp[i].second;
        }
    }
    cout << ac_num << " " << penalty_num << endl;

    return 0;
}

