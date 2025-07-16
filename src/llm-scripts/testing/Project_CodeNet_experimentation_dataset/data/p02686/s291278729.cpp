#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) \
    for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) \
    for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
#define ALL(v) v.begin(), v.end()
//#define endl "\n"
#define ciosup  \
    cin.tie(0); \
    ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e15 + 7LL;
constexpr ll MOD = 998244353LL;

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (int i = 0; i < v.size(); ++i) {
        is >> v[i];
    }
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        os << v[i] << " ";
    }
    if (v.size() > 0) {
        os << v[v.size() - 1] << endl;
    }
    return os;
}

int main() {
    ll n;
    cin >> n;
    priority_queue<pint> pque_plus;
    priority_queue<pint> pque_nplus;
    ll max_memo = 0;
    REP(i, n) {
        string s;
        cin >> s;
        pint cur{0, 0};
        ll now = 0, minval = 0, maxval = 0;
        REP(j, s.size()) {
            now += (s[j] == '(' ? 1 : -1);
            minval = min(minval, now);
            maxval = max(maxval, now);
        }
        cur.SE = now;
        if (cur.SE > 0){
            cur.FI = minval;
            pque_plus.push(cur);
        } else if (cur.SE < 0) {
            now = minval = maxval = 0;
            IREP(j, s.size()) {
                now += (s[j] == ')' ? 1 : -1);
                minval = min(minval, now);
            }
            cur.FI = minval;
            cur.SE = now;
            pque_nplus.push(cur);
        } else {
            max_memo = max(max_memo, abs(minval));
            now = minval = maxval = 0;
            IREP(j, s.size()) {
                now += (s[j] == ')' ? 1 : -1);
                minval = min(minval, now);
            }
            max_memo = max(max_memo, abs(minval));
        }
    }

    ll now = 0;
    while (pque_plus.size()){
        pint cur_val = pque_plus.top();
        pque_plus.pop();
        if (now + cur_val.FI < 0){
            cout << "No" << endl;
            return 0;
        }
        now += cur_val.SE;
    }

    ll now2 = 0;
    while (pque_nplus.size()) {
        pint cur_val = pque_nplus.top();
        pque_nplus.pop();
        if (now2 + cur_val.FI < 0) {
            cout << "No" << endl;
            return 0;
        }
        now2 += cur_val.SE;
    }

    if (now != now2) {
        cout << "No" << endl;
        return 0;
    }
    if (now < abs(max_memo)) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}
