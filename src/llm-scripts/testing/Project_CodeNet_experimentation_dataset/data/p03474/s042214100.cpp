#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    bool ans=true;
    rep(0,i,a)if(!(s[i]>='0'&&s[i]<='9'))ans=false;
    if(s[a]!='-')ans=false;
    rep(0,i,b)if(!(s[a+1+i]>='0'&&s[a+1+i]<='9'))ans=false;
    if(ans)cout<<"Yes";
    else cout<<"No";
}
