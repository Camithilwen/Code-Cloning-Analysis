#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

int main(){
    ll x; cin >> x;
    ll y=x%11;
    ll ans=0;
    ans+=(x/11)*2;
    if(y>6){
        ans+=2;
    }else if(y>0){
        ans++;
    }
    cout << ans << endl;
}