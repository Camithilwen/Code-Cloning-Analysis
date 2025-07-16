#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int n,m=250;
int S[300][300];
vector<P> v;

void plot(ll x,ll y){
    int cnt2=0,cnt5=0;
    while(x%2==0){
        x/=2;
        cnt2+=1;
    }
    while(y%2==0){
        y/=2;
        cnt2-=1;
    }
    while(x%5==0){
        x/=5;
        cnt5+=1;
    }
    while(y%5==0){
        y/=5;
        cnt5-=1;
    }
    S[cnt2+100][cnt5+100]+=1;
    v.push_back(P(cnt2,cnt5));
}

void solve(){
    cin >> n;
    rep(i,n){
        ll a=0,b=1;string s;
        cin >> s;
        bool flag=false;
        rep(i,s.length()){
            if(s[i]=='.') flag=true;
            else{
                if(flag) b*=10;
                a*=10;
                a+=s[i]-'0';
            }
        }
        plot(a,b);
    }
    rep(i,m) rep(j,m) {
        S[i][j+1]=S[i][j]+S[i][j+1];
    }
    rep(j,m+1) rep(i,m) {
        S[i+1][j]=S[i][j]+S[i+1][j];
    }
    ll ans=0;
    rep(i,n){
        int x=v[i].first,y=v[i].second;
        ans+=S[m][m]-S[-x+99][m]-S[m][-y+99]+S[-x+99][-y+99];
        if(x>=0 && y>=0) ans-=1;
    }
    cout << ans/2 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}