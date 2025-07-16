#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

//read_kaisetsu
int main() {
    string s;cin>>s;
    ll n = s.size();

    ll ans = n*(n-1)/2 + 1;
    
    ll a[27];rep(i,27)a[i]=0;
//    memset(a,0,sizeof(a));

    rep(i,n){
    ll tmp = s[i]-'a';
//      cout<<tmp<<endl;
    ++a[tmp];
    }
    rep(i,27)if(a[i]>=2)ans-=a[i]*(a[i]-1)/2;

    cout<<ans<<endl;
	return 0;
}