#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
ll n,t,x,y,m,q,a,b;
vector<ll>v[100001];
ll vis[100001]={0},ans=0;
pair<ll,ll> dfs(ll x,ll lvl){
   vis[x]=1;
   ll mx=0;
   ll d2=1e9;
   if(x==a)d2=0;
   for(int i=0;i<v[x].size();i++){
     if(vis[v[x][i]]==0){
       pair<ll,ll> p=dfs(v[x][i],lvl+1);
       d2=min(d2,p.second);
       mx=max(mx,1+p.first);
     }
   }
   if(d2<lvl) ans=max(ans,mx+lvl);
   return {mx,d2+1};
}
int main(){
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cin>>n>>a>>b;
      for(int i=0;i<n-1;i++){
      	cin>>x>>y;
      	v[x].push_back(y);
      	v[y].push_back(x);
      }
      if(a==b)cout<<0;
      else{
      	dfs(b,0);
      	cout<<ans-1;
      }
}