#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

ll par[2][200010],size[2][200010];

void init(int num,int n){
  fr(i,n){
    par[num][i]=i;
    size[num][i]=1;
  }
}

int find(int num,int x){
  if(par[num][x]==x) return x;
  else return par[num][x]=find(num,par[num][x]);
}
 
void unit(int num,int x,int y){
  x=find(num,x);
  y=find(num,y);
  if(x==y) return;
  if(size[num][x]<size[num][y]){
    par[num][x]=y;
    size[num][y]+=size[num][x];
  }
  else{
    par[num][y]=x;
    size[num][x]+=size[num][y];
  }
}
 
bool same(int num,int x,int y){
  return find(num,x)==find(num,y);
}

void prt(vector<ll>& s){
  for(auto it=s.begin();it!=s.end();it++) cout<<(*it)<<" ";
  cout<<endl;
}

int main(){
  ll n,k[2],p,q;
  P pq[200010];
  map<P,ll> tmp;
  cin>>n>>k[0]>>k[1];
  fr(i,2) init(i,n);
  fr(j,2){fr(i,k[j]){cin>>p>>q;unit(j,--p,--q);}}
  fr(i,n) tmp[mp(find(0,i),find(1,i))]++;
  fr(i,n) cout<<tmp[mp(find(0,i),find(1,i))]<<" ";
  cout<<endl;
}