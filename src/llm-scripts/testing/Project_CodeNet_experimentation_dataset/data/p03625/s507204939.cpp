#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n; cin >> n;
    map<ll,ll> mp; rep(i,n){
        ll tmp;
        cin >> tmp;
        mp[tmp]++;
    }

    ll m1 = 0, m2 = 0;
    for(auto x:mp){
        if(x.second > 1 && (x.first > m1 || x.first > m2)){
            if(m1 < m2){
                m1 = x.first;
            }else{
                m2 = x.first;
            }
        }
        if(x.second > 3){
            if(x.first > m1){
                m1 = x.first;
            }
            if(x.first > m2){
                m2 = x.first;
            }
        }
    }
    
    put(m1 * m2);
}