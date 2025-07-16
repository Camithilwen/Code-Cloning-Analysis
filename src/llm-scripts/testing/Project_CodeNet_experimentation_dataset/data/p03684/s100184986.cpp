#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define DB double
#define ST string
#define BS bitset
#define VE vector
#define VL vector<LL>
#define VP vector<pair<LL,LL>>
#define VVL vector<vector<LL>>
#define PQ priority_queue<LL>
#define PQS priority_queue<LL, vector<LL>, greater<LL>>
#define PB push_back
#define POB pop_back
#define PF push_front
#define POF pop_front
#define MP make_pair
#define TS to_string
#define TU to_ullong
#define FOR(i,a,n) for(i=a;i<n;i++)
#define rep(i,n) FOR(i,0,n)
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define SORT(a) sort(ALL(a))
#define REV(a) reverse(ALL(a))
#define UB(a,n) *upper_bound(ALL(a),n)
#define LB(a,n) *lower_bound(ALL(a),n)
#define INF 1145141919810364364
#define PI 3.14159265358979
//#define MOD 1000000007
#define MOD 998244353
#define ERR 0.00000000000001
#define NUM 200010

void Yn(LL a){if(a)printf("Yes\n");else printf("No\n");}
void YN(LL a){if(a)printf("YES\n");else printf("NO\n");}
LL pwmn(LL a,LL n){LL ans=1;while(ans<a)ans*=n;return ans;}
LL GCD(LL a,LL b){LL c=1,tmp=max(a,b);b=min(a,b);a=tmp;while(c!=0){c=a%b;a=b;b=c;}return a;}
LL LCM(LL a,LL b){return a*b/GCD(a,b);}
LL mod(LL a,LL m){if(a<0)return a%m+m;else return a%m;}
LL DIV(LL a,LL d){LL m=MOD,x=1,y=0,k;while(m){k=d/m;d-=k*m;swap(m,d);x-=k*y;swap(x,y);}return mod(a*mod(x,MOD),MOD);}
LL FAC(LL a){LL i,ans=1;FOR(i,1,a+1){ans*=i;if(MOD>0&&ans>MOD)ans%=MOD;}return ans;}
LL POW(LL a,LL n){LL ans=1;while(n>0){if(n&1)ans=ans*a%MOD;a=a*a%MOD;n>>=1;}return ans;}
LL fact[NUM],finv[NUM],inv[NUM];
void comi(){LL i;fact[0]=fact[1]=1;finv[0]=finv[1]=1;inv[1]=1;FOR(i,2,NUM){fact[i]=fact[i-1]*i%MOD;inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;finv[i]=finv[i-1]*inv[i]%MOD;}}
LL com(LL n,LL k){if(n<k||n<0||k<0)return 0;return fact[n]*(finv[k]*finv[n-k]%MOD)%MOD;}
bool cmps(pair<LL,LL> a,pair<LL,LL> b){if(a.second!=b.second)return a.second<b.second;return a.first<b.first;}

struct UF{
private:
  VL par;
public:
  UF(LL n){par.resize(n,-1);}
  LL root(LL x){if(par[x]<0)return x;else return par[x]=root(par[x]);}
  LL size(LL x){return -par[root(x)];}
  bool same(LL x,LL y){return root(x)==root(y);}
  void unite(LL x,LL y){x=root(x);y=root(y);if(x!=y){if(size(x)<size(y))swap(x,y);par[x]+=par[y];par[y]=x;}}
};
typedef struct{LL s,e,c,n;}Edge;
bool cmpc(Edge a,Edge b){return a.c<b.c;}
struct Kruscal{
private:UF *uf;VE<Edge> ed;
public:
  VE<Edge> edge;
  Kruscal(LL N){uf=new UF(N);}
  void add(LL s,LL e,LL c,LL n=0){Edge f;f.s=s,f.e=e,f.c=c,f.n=n;ed.PB(f);}
  void run(){sort(ALL(ed),cmpc);for(Edge a:ed){if(uf->same(a.s,a.e))continue;else{edge.PB(a);uf->unite(a.s,a.e);}}}
};

typedef struct{LL x,y,n;}Node;
bool cmpx(Node a,Node b){return a.x<b.x;}
bool cmpy(Node a,Node b){return a.y<b.y;}

int main(){
  LL i,N,ans=0;
  cin>>N;
  VE<Node> v(N);
  Kruscal k(2*N-2);
  rep(i,N){
    cin>>v[i].x>>v[i].y;
    v[i].n=i;
  }
  sort(ALL(v),cmpx);
  rep(i,N-1)k.add(v[i].n,v[i+1].n,v[i+1].x-v[i].x);
  sort(ALL(v),cmpy);
  rep(i,N-1)k.add(v[i].n,v[i+1].n,v[i+1].y-v[i].y);
  k.run();
  for(Edge a:k.edge)ans+=a.c;
  cout<<ans<<endl;
}
