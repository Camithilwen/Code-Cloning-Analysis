#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll x, y;
  cin>>x>>y;
  priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll> >, greater<tuple<ll, ll, ll> > >que;
  que.push(make_tuple(0, x, y));
  tuple<ll, ll, ll> state;
  ll path, xx, yy;
  ll ans;
  map<pair<ll, ll>, int> amap;
  while(!que.empty()){
    state = que.top();que.pop();
    path = get<0>(state);
    xx = get<1>(state);
    yy = get<2>(state);
    if(xx==yy){
      ans = path;
      break;
    }
    if(amap[mp(xx, yy)]>0) continue;
    amap[mp(xx, yy)]++;
    if(amap[mp(-xx, yy)]==0){
      que.push(make_tuple(path+1, -xx, yy));
    }
    if(xx<yy){
      if(amap[mp(yy, yy)]==0){
        que.push(make_tuple(path+yy-xx, yy, yy));
      }
    }
    if(xx<-yy){
      if(amap[mp(-yy, yy)]==0){
        que.push(make_tuple(path-yy-xx, -yy, yy));
      }
    }
  }
  cout<<ans<<endl;
}

