#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define mod 1000000007
using ll=long long;
const int INF=1000000000;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}
 
struct IOSetup{
    IOSetup(){
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout<<fixed<<setprecision(12);
    }
} iosetup;
 
template<typename T1,typename T2>
ostream &operator<<(ostream &os,const pair<T1,T2>&p){
    os<<p.first<<" "<<p.second;
    return os;
}
 
template<typename T>
ostream &operator<<(ostream &os,const vector<T>&v){
    for(int i=0;i<(int)v.size();i++) os<<v[i]<<(i+1==(int)v.size()?"":" ");
    return os;
}

template<typename T1,typename T2>
istream &operator>>(istream &is,pair<T1,T2>&p){
    is>>p.first>>p.second;
    return is;
}

template<typename T>
istream &operator>>(istream &is,vector<T>&v){
    for(T &x:v)is>>x;
    return is;
}


int dp[310][310][610];
signed main(){
    string s;cin>>s;
    int m;cin>>m;
    int n=(int)s.size();
    if(m>=n){
        cout<<n<<endl;
        return 0;
    }
    string t=s;
    reverse(ALL(t));

    rep(i,n)rep(j,n)rep(k,m+1){
        chmax(dp[i+1][j+1][k],dp[i][j][k]+(s[i]==t[j]));
        chmax(dp[i+1][j+1][k],dp[i][j+1][k]);
        chmax(dp[i+1][j+1][k],dp[i+1][j][k]);
        chmax(dp[i+1][j+1][k+1],dp[i][j][k]+1);
    }
    int res=0;
    // t=rev(s)
    // s = [a   ][b     ]
    // t = [rb    ][ra  ]
    // LCS(a,rb)=LCS(b,ra)
    // 文字同士をマッチングさせることを考えるとそれはそう
    rep(i,n+1)chmax(res,2*dp[i][n-i][m]);
    rep(i,n)  chmax(res,2*dp[i][n-1-i][m]+1);
    cout<<res<<endl;
    return 0;
}
