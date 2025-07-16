#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i != 0) {
            continue; 
        }
        long long ex = 0; // 指数
        // 割れるだけ割る
        while (N % i == 0) {
            ++ex;
            N /= i;
        }
        // 結果を push
        res.push_back({i, ex});
    }

    // 残った数はそのまま push
    if (N != 1) {
        res.push_back({N, 1});
    } else {
        res.push_back({1, 1});
    }

    return res;
}


int main() {
    long long N, target = 1, ans = 1, num = 1000000007;
    cin >> N;

    vector<long long> ex(N+1, 0); //指数情報を格納していく
    for (int i = 1; i <= N; ++i) {
        const auto &res = prime_factorize(i);
        for (auto p : res) {
            ex[p.first] += p.second;
        }
    }

    for (long long i = 2; i <= N; ++i) {
        ans *= ex[i] + 1 ;
        ans %= num;
    }

    cout << ans << endl;

    return 0;
}
