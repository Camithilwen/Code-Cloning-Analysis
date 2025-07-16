#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    ans += n/11*2;
    if(n%11 != 0) ans += (n%11-1)/6 + 1;
    cout << ans << endl;
    return 0;
}