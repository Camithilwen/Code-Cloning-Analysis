#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n, m;
    cin >> n >> m;
    vi s(m), c(m);
    rep(i, m) {
        cin >> s[i] >> c[i];
        s[i]--;
    }
    vi q(n, -1);
    rep(i, m) {
        if (q[s[i]]!=-1 && q[s[i]]!=c[i]) {
            cout << -1 << endl;
            return 0;
        }
        else q[s[i]] = c[i];
    }
    if (n>1 && q[0]==0) {
        cout << -1 << endl;
        return 0;
    }
    int b = 1, e = 10;
    rep(i, n-1) {
        b *= 10; e *= 10;
    }
    if (n == 1) b = 0;
    for (int i=b; i<e; ++i) {
        int i2 = i;
        bool ok = true;
        repr(j, n) {
            if (q[j]!=-1 && i2%10!=q[j]) ok = false;
            i2 /= 10;
        }
        if (ok) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
