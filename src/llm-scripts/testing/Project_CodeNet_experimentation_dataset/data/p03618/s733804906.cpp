             

#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const long double pi=acos(-1);

int main(){cout<<fixed<<setprecision(10);
		   string s;
           cin>>s;
           ll n=s.size();
           //abjka 両端が同じなら数えない
           ll ans=1;
           map<char,ll> cnt;
           rep(i,0,n)cnt[s[i]]++;
           ans+=n*(n-1)/2;
           ll c;
           for(auto v:cnt){
              c=v.second;
            ans-=c*(c-1)/2;
           }
           cout<<ans<<endl;
}
