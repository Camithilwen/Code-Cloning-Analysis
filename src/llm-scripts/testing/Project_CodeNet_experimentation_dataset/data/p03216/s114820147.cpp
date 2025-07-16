#include <bits/stdc++.h>
using namespace std;using ll=int_fast64_t;using ld=long double;using pll=pair<ll,ll>;using pld=pair<ld,ld>;
const ll INF=1LL<<60;void solve();int main(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(10);solve();}
#define foreach(i,a) for(auto &i:a)
#define SELECTOR(_1,_2,_3,_4,SELECT,...) SELECT
#define rep(...) SELECTOR(__VA_ARGS__,_rep2,_rep1,_rep0)(__VA_ARGS__)
#define _rep0(i,n) for(ll i=0;i<n;++i)
#define _rep1(i,k,n) for(ll i=k;i<n;++i)
#define _rep2(i,k,n,d) for(ll i=k;d!=0&&d>0?i<n:i>n;i+=d)
template<class T> vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<class... Ts> auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<class T> inline bool chmax(T &a,const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a,const T &b){if(a>b){a=b; return 1;} return 0;}

void solve(){
  ll n; cin>>n;
  string S; cin>>S;
  ll q; cin>>q;
  rep(_,q){
    ll k; cin>>k;
    vector<ll> DMC(3);
    ll cnt=0;
    ll ans=0;
    queue<char> Q;
    foreach(s,S){
      // push
      if(s=='D'){
        DMC[0]++;
      }else if(s=='M'){
        DMC[1]++;
        cnt+=DMC[0];
      }else if(s=='C'){
        DMC[2]++;
        ans+=cnt;
      }
      Q.push(s);

      // pop
      if(Q.size()<k) continue;
      char t=Q.front(); Q.pop();
      if(t=='D'){
        DMC[0]--;
        cnt-=DMC[1];
      }else if(t=='M'){
        DMC[1]--;
      }else if(t=='C'){
        DMC[2]--;
      }
    }
    cout<<ans<<"\n";
  }
}