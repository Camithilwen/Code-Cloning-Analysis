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
    int x, y;
    cin >> x >> y;
    int ans = 0;
    if(x == 1) ans += 300000;
    if(x == 2) ans += 200000;
    if(x == 3) ans += 100000;
    if(y == 1) ans += 300000;
    if(y == 2) ans += 200000;
    if(y == 3) ans += 100000;
    if(x == 1 && y == 1) ans += 400000;

    cout << ans << endl;

    return 0;
}