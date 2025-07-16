#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define all(a) a.begin(),a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n; string s; cin>>n>>s;
    map<pair<string,string>,int> mp;
    rep(i,1<<n){
        string t="",u="";
        rep(j,n){
            if((1<<j)&i)t=s[j+n]+t;
            else u=s[j+n]+u;
        }
        mp[pair<string,string>(t,u)]++;
    }
    int ans=0;
    rep(i,1<<n){
        string t="",u="";
        rep(j,n){
            if((1<<j)&i)t+=s[j];
            else u+=s[j];
        }
        ans+=mp[pair<string,string>(t,u)];
    }
    cout<<ans<<endl;

}