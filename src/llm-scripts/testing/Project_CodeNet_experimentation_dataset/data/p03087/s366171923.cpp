// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで
// g++ hoge.cpp -std=c++17 -I . でコンパイルできる
// -fsanitize=undefinedでオーバーフロー検出
#include <bits/stdc++.h>
//#include <atcoder/all>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
//using namespace atcoder;
typedef pair<ll,ll> P;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,m,n,k,x,y,maxi=0,f=0,mini=INF,sum=0;
    string str;
    ll q;
    cin>>n>>q;
    cin>>str;
    P p[q];
    rep(i,q){
        cin>>a>>b;
        a--;
        b--;
        p[i]=P(a,b);
    }
    vector<ll> imos(n+1);
    rep(i,n-1){
        if(i!=0)imos[i]=imos[i-1];
        if(str.substr(i,2).compare("AC")==0) {
            imos[i]++;
        }
        //cout<<imos[i]<<" ";
    }
    a=0;b=0;
    rep(i,q){ 
        if(p[i].first!=0)sum=imos[p[i].second-1]-imos[p[i].first-1];
        else sum=imos[p[i].second-1];
        cout<<sum<<endl;
    }

    return 0;
}
