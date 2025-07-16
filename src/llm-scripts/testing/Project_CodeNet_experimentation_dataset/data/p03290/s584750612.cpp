#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int d,g;
vin p,c;

bool check(int y){
  
 bool ans=false;
  vin order(d);
  rep(i,0,d)order[i]=i;
  do{
    int x=y;
    int rest=g;
    
    rep(i,0,d){
      int now=order[i];
      if(x>=p[now]){
        rest-=p[now]*(now+1)*100;
        rest-=c[now];
        x-=p[now];
      }
      else{
        rest-=x*(now+1)*100;
        x=0;
        break;
      }
    }
    if(rest<=0)ans=1;
    
  }while(next_permutation(all(order)));
  
  return ans;
}


int main(){cout<<fixed<<setprecision(20);
		   //二分探索かな？
           //順列探索かな？
           //O(10^6*log1000)*10
           cin>>d>>g;
           p.resize(d);c.resize(d);
           rep(i,0,d)cin>>p[i]>>c[i];
           int ng=0,ok=1000;
           while(ok-ng>1){
            int mid=(ok+ng)/2;
             if(check(mid))ok=mid;
             else ng=mid;
           }
           cout<<ok<<endl;
}