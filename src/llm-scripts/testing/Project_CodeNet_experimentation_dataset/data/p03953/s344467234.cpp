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

int main() {
    int N, M, lK;
    i64 K;
    cin >> N;
    vector<i64> x(N), dx(N - 1), y(N);
    for(i64 &x_ : x) cin >> x_;
    for(int i = 0; i < N - 1; i++) {
        dx[i] = x[i + 1] - x[i];
    }
    cin >> M >> K;
    vector<int> perm_base(N - 1), perm_ans(N - 1), perm_tmp(N - 1);
    for (int i = 0; i < N - 1; i++) {
        perm_base[i] = perm_ans[i] = i;
    }
    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        a--;
        swap(perm_base[a - 1], perm_base[a]);
    }
    // 繰り返し二乗法
    for(int b = 0; (1ll << b) <= K; b++) {
        if (K & (1ll << b)) {
            for (int i = 0; i < N - 1; i++) {
                perm_ans[i] = perm_base[perm_ans[i]];
            }
        }
        for (int i = 0; i < N - 1; i++) perm_tmp[i] = i;
        for (int i = 0; i < N - 1; i++) {
            perm_tmp[i] = perm_base[perm_base[i]];
        }
        swap(perm_tmp, perm_base);
    }
    for(int i = 0; i < N; i++) {
        y[i] = i ? dx[perm_ans[i - 1]] + y[i - 1] : x[0];
        cout << y[i] << endl;
    }
    return 0;
}

