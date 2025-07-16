#include <bits/stdc++.h>

#define rep(i,n) for(ll i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int n = s.length();  
    if(s.length()==2){
        if(s[0]==s[1]) cout<<"1 2";
        else cout<<"-1 -1";
        return 0;
    }
    bool f = false;
    for(int i=0; i+1<n; i++){
        if(s[i]==s[i+1]) {
            cout<<i+1<<" "<<i+2;
            f = true;
            break;
        }
    }
    for(int i=0; i+2<n && f!=true; i++){
        if(s[i]==s[i+1] || s[i+2]==s[i+1] || s[i]==s[i+2]) {
            cout<<i+1<<" "<<i+3;
            f = true;
            break;
        }
    }
    if(!f) cout<<"-1 -1";
    return 0;
}