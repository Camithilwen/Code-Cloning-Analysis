#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    set<ll> num;
    ll t = 1;
    while(t<ll(1e9)+5){
        t*=2;
        num.insert(t);
    }
    ll N;
    cin >> N;
    map<ll,ll> mp;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
        mp[A[i]]++;
    }
    sort(A.rbegin(),A.rend());
    ll ans =0;
    for(int i=0;i<N;i++){
        if(mp[A[i]] ==0){
            continue;
        }
        ll n = A[i];
        ll t = *num.upper_bound(n);
        t-=n;
        mp[n]--;
        if(mp.find(t) == mp.end()|| mp[t] ==0){
            continue;
        }
        ans++;
        mp[t]--;
    }
   
    cout << ans << endl;
    return 0;
}