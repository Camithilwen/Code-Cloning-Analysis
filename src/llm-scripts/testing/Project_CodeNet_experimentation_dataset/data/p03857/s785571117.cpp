#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) std::memset(arg,n,sizeof(arg))
#define mp std::make_pair
#define pb push_back
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::pair<int,pi> pipi;
typedef std::vector<int> vi;
typedef std::set<int> si;
typedef std::string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
const int NMAX=200010;
int N,K,L;
int p[100010],q[100010],r[100010],s[100010];
//UnionFindTreeのクラス。
/***************************/
class uft{
public:
  int par[NMAX];//親
  int rank[NMAX];//木の深さ
  int size[NMAX];//木の大きさ
  uft(int n);//コンストラクタ
  int find(int x);
  void unite(int x,int y);
  bool same(int x,int y);
  int usize(int x);
};
uft::uft(int n){//コンストラクタ uft uf(N)でサイズNのunionfindtreeを宣言 
  for(int i=0;i<n;i++){
    par[i]=i;
    rank[i]=0;
    size[i]=1;
  }
}
int uft::find(int x){//xの根を返す
  if(par[x]==x) return x;//根の親は自分自身
  else return par[x]=find(par[x]);//再起で親を辿る
}
void uft::unite(int x,int y){//x,yを併合
  x=find(x);
  y=find(y);
  if(x==y) return ;//根が同じなら併合する必要なし

  if(rank[x]<rank[y]){//木の深い方に浅い方をつける
    par[x]=y;
    size[y]+=size[x];
  }
  else{
    par[y]=x;
    size[x]+=size[y];
    if(rank[x]==rank[y]) rank[x]++;//同じ深さなら深さを増やす
  }
}
bool uft::same(int x,int y){//x,yが同じグループにいるかどうかを返す
  return find(x)==find(y);//根が同じかどうかを判断する
}
int uft::usize(int x){//xの属する木のサイズを返す
  return size[find(x)];
}

int main(){
  cin>>N>>K>>L;
  rep(i,K){
    cin>>p[i]>>q[i];
    p[i]--;q[i]--;
  }
  rep(i,L){
    cin>>r[i]>>s[i];
    r[i]--;s[i]--;
  }
  uft ur(N),ut(N);
  rep(i,K){
    ur.unite(p[i],q[i]);
  }
  rep(i,L){
    ut.unite(r[i],s[i]);
  }
  pipi p[200010];
  rep(i,N){
    p[i]=mp(ur.find(i),mp(ut.find(i),i));
  }
  std::sort(p,p+N);
  int res[200010];
  int cnt=1;
  rep(i,N-1){
    if(p[i].first==p[i+1].first&&p[i].second.first==p[i+1].second.first) cnt++;
    else{
      rep(j,cnt){
	res[p[i-j].second.second]=cnt;
      }
      cnt=1;
    }
  }
  rep(j,cnt){
    res[p[N-1-j].second.second]=cnt;
  }
  rep(i,N){
    std::cout<<res[i]<<" ";
  }
  std::cout<<"\n";
  
  return 0;
}
