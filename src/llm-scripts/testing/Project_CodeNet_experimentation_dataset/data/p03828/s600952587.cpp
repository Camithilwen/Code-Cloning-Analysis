#include <bits/stdc++.h>
using namespace std;

template <class T>
vector<pair<T, T>> prime_factorization(T n) {
    vector<pair<T, T>> ret;
    for (T i = 2; i * i <= n; i++) {
        T cnt = 0;
        while(n % i == 0) {
            n /= i; cnt++;
        }
        if(cnt != 0) ret.emplace_back(i, cnt);
    }
    if (n != 1) ret.emplace_back(n, 1);
    return ret;
}

int main(){
    int n; cin >> n;

    map<int64_t, int64_t> f;
    for (auto i = 2; i <= n; i++) {
        auto p = prime_factorization(i);
        for (auto & elm : p) f[elm.first] += elm.second;
    }

    int64_t ans = 1;
    const int64_t mod = 1e9 + 7;
    for (auto & elm : f) ans = ((elm.second + 1) * ans) % mod;

    cout << ans << endl;
    return 0;
}