#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int n;string s;

ll solve(int k){
    ll d=0,m=0,dm=0,ret=0;
    rep(i,k){
        if(s[i]=='D')d++;
        if(s[i]=='M'){
            dm+=d;
            m++;
        }
        if(s[i]=='C')ret+=dm;
    }
    for(int i=k;i<n;i++){
        if(s[i-k]=='D'){
            dm-=m;d--;
        }
        if(s[i-k]=='M')m--;
        
        if(s[i]=='D') d++;
        if(s[i]=='M'){
            dm+=d;
            m++;
        }
        if(s[i]=='C')ret+=dm;
    }
    return ret;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin>>n;
    cin>>s;

    vector<ll> ans;
    int q;cin>>q;
    while(q--){
        int k;cin>>k;
        ans.push_back(solve(k));
    }
    for(auto x:ans){
        cout<<x<<endl;
    }
    return 0;
}
