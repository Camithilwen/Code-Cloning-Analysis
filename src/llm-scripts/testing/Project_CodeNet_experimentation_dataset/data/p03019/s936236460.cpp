#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int p;fixprec(int p):p(p){}};
ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.p);}

/*!* [binsearch] *!*/
/*+* 二分探索 *+*/
// judge を満たすような(l,r]内の下限を求める
// l:[X] 定義域の下限
// r:[X] 定義域の上限
// judge:[F = X -> bool] 値 X を評価する関数
// lower:[bool] false にすると代わりに[l,r)内の上限を求める
// eps:[X] 終了距離

template <typename X, typename F>
X BinSearch(X l, X r, F judge, bool lower = true, X eps = 1) {
    while (r - l > eps) {
        X m = (r + l) / 2;
        if (judge(m) == lower) {
            r = m;
        } else {
            l = m;
        }
    }
    return lower ? r : l;
}

struct Data {
    i64 b, l, u;
    bool operator<(const Data &x) const {
        return make_tuple(b, l, u) < make_tuple(x.b, x.l, x.u);
    }
};

int main() {
    const i64 INF = 1e14;
    i64 N, X;
    cin >> N >> X;
    vector<pair<i64, Data>> data(N);
    i64 S_N = 0;

    for(int i = 0; i < N; i++) {
        i64 b, l, u;
        cin >> b >> l >> u;
        data[i] = {u * (X - b) + l * b, {b, l, u}};
        S_N += l * b;
    }

    // O(N log N)
    sort(REV_WHOLE(data));

    vector<i64> S(N);
    for(int i = 0; i < N; i++) {
        S[i] = data[i].first + (i ? S[i - 1] : 0);
    }

    // O(N log NX)
    i64 ans = BinSearch<i64>(-1, N * X, [&](i64 A) -> bool {
        // O(N)
        // (sum of a_i) <= A ?

        i64 m = A / X;
        i64 r = A - m * X;
        for(int j = 0; j < N; j++) {
            i64 e = 0;
            i64 x;
            Data d;
            tie(x, d) = data[j];
            e += max(d.l * (r - d.b), d.u * (r - d.b)) + d.l * d.b;
            if(m > 0) {
                e += j < m ? S[m] - x : S[m - 1];
            }
            e -= S_N;
            if(e >= 0) return true;
        }
        return false;
    });
    cout << ans << endl;
    return 0;
}