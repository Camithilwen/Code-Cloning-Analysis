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

// ビット演算
namespace Bits {
    // 整数 x を左に i ビットシフトした値を返す
    static Int LeftBitShift(Int x, Int i);
    // 整数 x を右に i ビットシフトした値を返す
    static Int RightBitShift(Int x, Int i);
    // 整数x の 下から i 桁目が1かどうかを返す
    static bool IsFlagUp(Int x, Int i);
    // 整数x の 下から i 桁目が0かどうかを返す
    static bool IsFlagDown(Int x, Int i);

    // 整数 x を左に i ビットシフトした値を返す
    Int LeftBitShift(Int x, Int i) {
        return (x << i);
    }
    // 整数 x を右に i ビットシフトした値を返す
    Int RightBitShift(Int x, Int i) {
        return (x >> i);
    }
    // 整数x の 下から i 桁目が1かどうかを返す
    bool IsFlagUp(Int x, Int i) {
        return ((x & (1 << i)) != 0);
    }
    // 整数x の 下から i 桁目が0かどうかを返す
    bool IsFlagDown(Int x, Int i) {
        return ((x & (1 << i)) == 0);
    }
}
using namespace Bits;

// 二つの値の最大値を求める関数
Int Max(const Int a, const Int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    Int n;
    cin >> n;
    VI a(n);
    VVI table(n, VI(n, -1)); // -1 不明, 0 不親切, 1 正直者
    Int x, y;
    for (Int i = 0; i < n; ++i) {
        cin >> a[i];
        for (Int j = 0; j < a[i]; ++j) {
            cin >> x >> y;
            --x;
            table[i][x] = y;
        }
    }
    Int result = 0;
    for (Int i = 0; i < pow(2, n); ++i) {
        // cout << "I = " << i << endl;
        bool correct = true;
        Int rank = 0;
        // ビット列が1の人のみの証言に矛盾がないかを調べる
        for (Int j = 0; j < n; ++j) {
            if (IsFlagUp(i, j)) {
                rank++;
                for (Int k = 0; k < n; ++k) {
                    if (table[j][k] == 0 && IsFlagUp(i, k)) {
                        correct = false;
                    } else if (table[j][k] == 1 && IsFlagDown(i, k)) {
                        correct = false;
                    }
                }
            }
        }
        if (correct) {
            // cout << "CORRECT" << endl;
            result = Max(result, rank);
        } else {
            // cout << "INCORRECT" << endl;
        }
    }
    cout << result << endl;

    /*
    for (Int i = 0; i < n; ++i) {
        for (Int j = 0; j < n; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    */
    return 0;
}
