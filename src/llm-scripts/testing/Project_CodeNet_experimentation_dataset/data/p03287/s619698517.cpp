#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;
ll m;
template <typename T>
T zero_sum_ranges(vector<T> A) {
    T n = A.size();
    T sum[n + 1] = {};
    sum[1] = A[0];
    map<T, T> mp;
    for(size_t i = 0; i < n; i++) {
        sum[i + 1] = (sum[i] + A[i]) % m;
    }
    T ret = 0;
    for(size_t i = 0; i <= n; i++) {
        if(mp.count(sum[i])) ret += mp[sum[i]];
        mp[sum[i]]++;
    }
    cout << ret << endl;
}

int main() {
    ll n, i, j, k;
    cin >> n >> m;
    vector<ll> v(n);
    for(auto &x:v)cin >> x;
    zero_sum_ranges(v);
    return 0;
}