#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a,ans=1;cin >> a;
    const ll p=1000000007;
    vector<ll> v(a,0);
    for (ll i=1;i<=a;i++){
        int cur=i;
        for (int b=2;b<=i;b++){
            while(cur%b==0){
                cur/=b;
                v[b-1]++;
            }
        }
    }
    for (int i=1;i<a;i++){
        ans=ans*(v[i]+1ll);
        ans%=p;
    }
    cout << ans;
    // D:
    // D:
    // D:
    // D:
    // D:
    // D:
    // D:
    // D:
    // D:
    // D:
    // :D
}