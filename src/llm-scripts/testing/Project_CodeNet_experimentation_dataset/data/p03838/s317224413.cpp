#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    ll x,y;
    cin >> x >> y;
    ll ans;
    // 1回目に符号を反転させる場合
    ll A = 1 + y - (-x);
    // 最後に符号を反転させる場合
    ll B = (-y) - x + 1;
    // 最初と最後に符号を反転させる場合
    ll C = 2 + (-y) - (-x);
    // 反転させない場合
    ll D = y - x;
    if(A<0) A = INF;
    if(B<0) B = INF;
    if(C<0) C = INF;
    if(D<0) D = INF;
    ans = min(min(A,B),min(C,D));
    cout << ans << endl;
    return 0;
}