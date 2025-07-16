#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;

int main(){
  int n;cin>>n;
  vin x(0),y(0),xx(n),yy(n);
  set<int> s1,s2;
  vvb g(8,vb(8,false));
  rep(i,0,n){
    int x1,y1;cin>>x1>>y1;
    s1.insert(x1+y1);s2.insert(x1-y1);
    g[x1][y1]=true;
    xx[i]=x1;yy[i]=y1;
  }
  rep(i,0,8){
      if(find(xx.begin(),xx.end(),i)==xx.end()){x.push_back(i);}
      if(find(yy.begin(),yy.end(),i)==yy.end()){y.push_back(i);}
    }
  
  do{
      bool ok=true;
      set<int> ss1=s1,ss2=s2;
      rep(i,0,8-n){
        if(find(ss1.begin(),ss1.end(),x[i]+y[i])!=ss1.end()){ok=false;break;}
        else{ss1.insert(x[i]+y[i]);}
        if(find(ss2.begin(),ss2.end(),x[i]-y[i])!=ss2.end()){ok=false;break;}
        else{ss2.insert(x[i]-y[i]);}
      }
      if(ok){
        rep(i,0,8-n){
          g[x[i]][y[i]]=true;
        }
        rep(i,0,8){
          rep(j,0,8){
            if(g[i][j]){cout<<'Q';}
            else{cout<<'.';}
          }
          cout<<endl;
        }
        break;
      }
  }while(next_permutation(x.begin(),x.end()));
  
}

