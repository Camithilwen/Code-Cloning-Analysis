#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#define lol(i,n) for(ll i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;

using namespace std;
#define X 610
ll n;
class Con{
  public:
  vector<pair<ll,ll> > g[X][X];
  ll s[X][X];
  void dfs(ll x,ll y,ll c){
    if(~s[x][y])return;
    s[x][y]=c;
    for(auto t:g[x][y]){
      dfs(t.first,t.second,1^c);
    }
  }
  void main(ll d){
    vector<ll> x,y;
    for(int i=-X;i<X;i++)for(int j=-X;j<X;j++){
      if(i*i+j*j==d){
	x.push_back(i); y.push_back(j);
      }
    }
    lol(i,n)lol(j,n){
      for(int k=0;k<x.size();k++){
	ll xx=i+x[k],yy=j+y[k];
	if(xx<0||yy<0||xx>=n||yy>=n)continue;
	g[i][j].push_back(make_pair(xx,yy));
      }
    }
    lol(i,n)lol(j,n)s[i][j]=-1;
    lol(i,n)lol(j,n)dfs(i,j,0);
  }
};Con co[2];
int main(){
    cin>>n;n*=2;
    lol(i,2){
      ll d;
      cin>>d;
      co[i].main(d);
    }
    vector<pair<ll,ll> >v[2][2];
    lol(i,n)lol(j,n){
      v[co[0].s[i][j]][co[1].s[i][j]].push_back(make_pair(i,j));
    }
    lol(i,2)lol(j,2)if(v[i][j].size()>=n*n/4){
      for(int k=0;k<n*n/4;k++){
	cout<<v[i][j][k].first<<" "<<v[i][j][k].second<<endl;
      }
      return 0;
    }
    return 0;
}
