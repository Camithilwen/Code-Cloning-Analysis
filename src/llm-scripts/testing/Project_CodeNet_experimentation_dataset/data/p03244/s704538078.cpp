#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define MOD 1000000007
#define INF 1e9
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T GCD(T a, T b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
    return (a * b) / GCD(a, b);
}

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    vector<int> odd;
    vector<int> even;
    rep(i, n) {
        if (i % 2)
            odd.push_back(v[i]);
        else
            even.push_back(v[i]);
    }
    map<int, int> o;
    map<int, int> e;
    rep(i, n / 2) o[odd[i]]++;
    rep(i, n / 2) e[even[i]]++;
    int ofreq = 0, osfreq = 0;
    int efreq = 0, esfreq = 0;
    int o1, e1, o2, e2;
    for (auto c : o) {
        if (c.second > ofreq) {
            o2 = o1;
            o1 = c.first;
            osfreq = ofreq;
            ofreq = c.second;
        }
        else if (c.second > osfreq) {
            osfreq = c.second;
            o2 = c.first;
        }
    }
    for (auto c : e) {
        if (c.second > efreq) {
            e2 = e1;
            e1 = c.first;
            esfreq = efreq;
            efreq = c.second;
        }
        else if (c.second > esfreq) {
            esfreq = c.second;
            e2 = c.first;
        }
    }
    if (o1 != e1)
        cout << n - ofreq - efreq;
    else
        cout << n - max(ofreq + esfreq, osfreq + efreq);

    cout << endl;
}