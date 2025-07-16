#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;


int main(){
    ll n;cin >>n;
    ll o;cin >>o;
    bool flg=true;
    if(o!=0){
        flg=false;
    }
    map<ll,ll>co;
    co[0]++;
    for (int i = 0; i < n - 1; ++i) {
        ll d;
        cin >> d;
        co[d]++;
    }
    ll ans=1;
    ll c=1;
    for(int i=1;;i++){
        if(co[i]==0)break;
        c+=co[i];
        for (int j = 0; j < co[i]; ++j) {
            ans*=co[i-1];
            ans%=998244353;
        }
       // cout <<ans <<endl;
    }
    if(c!=n)flg=false;
    if(co[0]>1)flg=false;
    if(flg){
        cout <<ans<<endl;
    }
    else {
        cout <<0<<endl;
    }
    return 0;
}