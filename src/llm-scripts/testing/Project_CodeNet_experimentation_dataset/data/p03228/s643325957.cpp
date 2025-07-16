#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
    ll a, b, k;
    cin >> a >> b >> k;

    rep (i, k) {
        if (i % 2 == 0) {
            if (a % 2 == 1) {
                a--;
            }
            a /= 2;
            b += a;
        }
        else {
            if ( b % 2) {
                b--;
            }
            b /= 2;
            a += b;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}