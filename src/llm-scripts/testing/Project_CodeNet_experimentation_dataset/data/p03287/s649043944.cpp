#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    map<ll,ll> mp;
    ll N, MOD;
    cin >> N >> MOD;
    ll sum[N+1];
    sum[0] =0;
    mp[0]++;
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        sum[i+1] = sum[i] + a;
        sum[i+1] %=MOD;
        mp[sum[i+1]]++;
    }
    ll ans =0;
    for(auto itr = mp.begin();itr != mp.end();++itr){
        ll n = itr->second;
        ans += (n*(n-1))/2;
    }
    cout << ans << endl;

    return 0;
}