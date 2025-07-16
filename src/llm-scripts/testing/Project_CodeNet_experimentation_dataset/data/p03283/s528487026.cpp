
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

int cnt[550][550];
ll sum[110*5][110*5];

int main(){cout<<fixed<<setprecision(10);
		   //O(m+nq)
           int n,m,Q;
           cin>>n>>m>>Q;
           int r,l;
           rep(i,0,m){
             cin>>l>>r;
             
             cnt[l][r]++;
           }
           rep(i,1,n+1){
            rep(j,1,n+1){
              sum[i][j]=sum[i][j-1]+cnt[i][j];
              //cout<<sum[i][j]<<" ";
            }
            // cout<<endl;
           }
           int p,q;
           ll ans;
           rep(i,0,Q){
             cin>>p>>q;
             ans=0;
             rep(j,p,n+1){
              ans+=sum[j][q]; 
               
             }
             cout<<ans<<endl;
           }
}