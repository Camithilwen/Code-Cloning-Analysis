#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    ll ans=1;
    map<char,int>mp;
    rep(i,n){
        mp[s[i]]++;
        ans+=i+1-mp[s[i]];
    }
    cout<<ans<<endl;
}