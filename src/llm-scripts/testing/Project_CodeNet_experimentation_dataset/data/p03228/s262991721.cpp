#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;

/* --------------------------------------------------- */

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    rep(i, k) {
        if(i % 2 == 0) {
            a /= 2;
            b += a;
        } else {
            b /= 2;
            a += b;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}