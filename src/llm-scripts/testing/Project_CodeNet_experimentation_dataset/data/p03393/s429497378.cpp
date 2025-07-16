#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    string s;cin >> s;
    if("zyxwvutsrqponmlkjihgfedcba"==s)cout << -1 <<endl,exit(0);
    if(s.size()==26){
        set<char> st;
        char x;
        per(i,25){
            st.ins(s[i+1]);
            if(s[i]>s[i+1])s.erase(i+1);
            else{
                x=s[i];
                s.erase(i);
                break;
            } 
        }
        x=*st.upper_bound(x);
        cout << s<<x <<endl;
        return 0;
    }
    set<char> st;
    rep(i,s.size())st.ins(s[i]);
    rep(i,26){
        if(!st.count('a'+i)){
            //cout << i <<endl;
            char x='a'+i;
            cout << s <<x<<endl;
            return 0;
        }
    }
}