#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int N;
ll D,A[202020];
vector<pair<ll,pair<int,int>>> G;

const int MAX_V=202020;

int par[MAX_V]; //　親
int rnk[MAX_V]; // rank, 木の深さ

void init(){
  for(int i=0;i<MAX_V;i++){
    par[i]=i;
    rnk[i]=0;
  }
}

int find(int x){
  if (par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (rnk[x] < rnk[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}


void solve(int l, int r){
  if(r-l<=1) return;
  int mid=(l+r)/2;
  int miL=l;
  for(int i=l+1;i<mid;i++) if(A[i]-D*i<A[miL]-miL*D) miL=i;
  int miR=mid;
  for(int i=mid+1;i<r;i++) if(A[i]+D*i<A[miR]+miR*D) miR=i;
  for(int i=mid;i<r;i++) G.push_back({A[i]+A[miL]+D*(i-miL),{i,miL}});
  for(int i=l;i<mid;i++) G.push_back({A[i]+A[miR]+D*(miR-i),{i,miR}});
  solve(l,mid);
  solve(mid,r);
}

int main(){
  cin>>N>>D;
  rep(i,N) cin>>A[i];
  solve(0,N);
  
  sort(G.begin(),G.end());
  init();
  ll ans=0;
  for(auto& p:G){
    if(!same(p.second.first,p.second.second)){
      ans+=p.first;
      unite(p.second.first,p.second.second);
    }
  }
  cout<<ans<<endl;
  return 0;
}
