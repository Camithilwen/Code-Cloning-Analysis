#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    vector <ll> a(5);
    cin >> n >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    vector <ll> z(6,0);
    z[0]=n;
    rep(i,4){
        a[i+1]=min(a[i],a[i+1]);
    }

    ll ans;
    if(n%a[4]==0){
    ans=n/a[4];
    }
    else{
        ans=n/a[4]+1;
    }
    ans+=4;

    cout << ans << endl;

    

    return 0;
}