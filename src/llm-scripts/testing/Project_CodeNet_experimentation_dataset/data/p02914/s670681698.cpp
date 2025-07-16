#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

// xorの掃き出し法をするためのクラス
// matに基底たちが入る
// Tはbitsetは無理(minしないといけないから)
template <typename T>
class BitLinearSpace {
    vector<T> bases; // この中身をsortしちゃうと壊れる

public:
    BitLinearSpace() = default;
    BitLinearSpace(vector<T> &matrix) {
        for (auto &mi:matrix) {
            add_val(mi, false);
        }
    }

    // valが張れるように基底を追加する
    // 追加した場合true, しなかった場合false
    // O(N) (ソートするとNlogN)
    // 追加後にソートするかを選ぶ
    bool add_val(T val) {
        if ((val = elementary_opperation(val))) {
            bases.push_back(val);
            return true;
        } else {
            return false;
        }
    }

    // 今のベクトル空間にvalが含まれるか(=basesの要素のxorでvalが作れるかをチェック)
    // O(n)
    bool includes(T val) {
        return elementary_opperation(val) == 0;
    }

    // 行列にvalを追加するていで行基本変形をvalに施す
    // 実際には追加しない
    // O(n)
    T elementary_opperation(T val) {
        for (auto &b:bases) {
            val = min(val, val ^ b);
        }
        return val;
    }

    T &operator[](int i) { return bases[(size_t)i]; }
    const T &operator[](int i) const { return bases[(size_t)i]; }

    auto begin() { return bases.begin(); }
    auto end() { return bases.end(); }
    auto begin() const { return bases.begin(); }
    auto end() const { return bases.end(); }

    int size() { return (int)bases.size(); }
};

int main() {
    int n;
    cin >> n;
    BitLinearSpace<ll> bls;
    ll sum = 0;
    for (int i=0; i<n; i++) {
        ll ai; cin >> ai;
        sum ^= ai;
        bls.add_val(ai);
    }
    vector<ll> bases(bls.begin(), bls.end());
    ll blue = 0, red = sum;
    for (int i=59; i>=0; i--) {
        if ((blue & (1ll << i)) == (red & (1ll << i))) {
            ll used = -1;
            for (auto &bi:bases) {
                if (bi & (1ll << i)) {
                    if (used < 0) {
                        if ((blue & (1ll << i)) == 0)
                            blue ^= bi;
                        used = bi;
                    }
                    bi ^= used;
                }
            }
        }
        red = blue ^ sum;
    }
    cout << blue + red << '\n';
    return 0;
}