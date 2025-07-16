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

// 基本的な演算
namespace BasicMath {
    // 二つの値の最大値を求める関数
    static Int Max(const Int a, const Int b);
    // 三つの値の最大値を求める関数
    static Int Max(const Int a, const Int b, const Int c);
    // 二つの値の最大値を求める関数
    Int Max(const Int a, const Int b) {
        if (a >= b) {
            return a;
        } else {
            return b;
        }
    }
    // 三つの値の最大値を求める関数
    Int Max(const Int a, const Int b, const Int c) {
        return Max(a, Max(b, c));
    }
}
using namespace BasicMath;

int main(void) {
    Int a, b, c;
    cin >> a >> b >> c;
    cout  << a + b + c - Max(a, b, c) << endl;
    return 0;
}

