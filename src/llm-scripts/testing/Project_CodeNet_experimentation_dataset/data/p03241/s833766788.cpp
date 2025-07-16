// 7/12
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    ll M;
    cin >> N >> M;
    // int M2 = M;

    // map<int, int> mp;  // 素因数、個数
    // for (int i = 2; i * i <= 1000000000; i++) {
    //     while (M % i == 0) {
    //         mp[i]++;
    //         M /= i;
    //     }
    // }
    // if (M != 1) mp[M]++;

    // int res = 1;
    // for (auto p : mp) {
    //     int prime = p.first;
    //     int num = p.second;
    //     printf("prime, num = %d, %d\n", prime, num);
    //     // while (num >= N) {
    //     //     res *= prime;
    //     //     num -= N;
    //     // }
    //     for (int i = 0; i < num; i++) {
    //         int now = res * prime;
    //         if ((M2 / now) >= N) {
    //             res *= prime;
    //         }
    //         else {
    //             break;
    //         }
    //     }
    // }

    vector<ll> div;
    div.push_back(1);
    for (int i = 2; i * i <= M; i++) {
        if (M % i == 0) {
            div.push_back(i);
            if (i != (M/i)) {
                div.push_back(M/i);
            }
        }
    }
    div.push_back(M);

    sort(div.rbegin(), div.rend());

    ll res = 0;
    // for (int i = div.size() - 1; i >= 0; i--) {
    rep(i, div.size()) {
        if ((M / div[i]) >= N) {
            res = div[i];
            break;
        }
    }

    cout << res << endl;
    return 0;
}