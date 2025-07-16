
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    ll n, t;
    cin >> n >> t;
    ll ans=0;
    ll pre=0;
    ll push=0;
    cin >> pre;
    for(int i=0; i<n-1; i++){
        pre = push;
        cin >> push;
        if(push-pre < t) ans += push-pre;
        else ans += t;
    }
    ans += t; //最後の一回
    cout << ans << endl;
}