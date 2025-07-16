#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using P = pair<int, int>;

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& v) {
    os << "(" << v.first << ", " << v.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    for (int i = 0; i < v.size(); i++) {
        if (i) os << ", ";
        os << v[i];
    }
    os << "}";
    return os;
}

int main()
{
    ll mod = TEN(9) + 7;
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    ll a_max = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a_max = max(a_max, a[i]);
    }

    ll y = 1; int log_a_max = 0;
    while (y < a_max) {
        y *= 2;
        log_a_max++;
    }

    vector<vector<bool>> p(n, vector<bool>(log_a_max, 0));
    vector<int> s(log_a_max, 0);
    for (int i = 0; i < n; i++) {
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < log_a_max; j++) {
            s[j] += (a[i] >> j) & 1;
        }
    }

    ll sum = 0;
    ll x = 1;
    for (int j = 0; j < log_a_max; j++) {
        for (int i = 0; i < n; i++) {
            if (a[i] >> j & 1) {
                sum += x * (n - s[j]);
            } else {
                sum += x * s[j];
            }
            sum %= mod;
        }
        x *= 2;
        x %= mod;
    }
    cout << sum * ((mod + 1) / 2) % mod << endl;
    return 0;
}
