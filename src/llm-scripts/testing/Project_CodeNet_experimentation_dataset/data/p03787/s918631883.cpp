#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
template<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
//end

vector<int> g[101010];
int col[101010],cnt;
bool dfs(int v,int c){
   col[v]=c; cnt++; bool res=1;
   for(int t:g[v]){
      if(col[t]!=-1){
         if(col[t]+c!=1)res=0;
      }
      else if(!dfs(t,c^1))res=0;
   } return res;
}

int main(){
   int n,m; cin>>n>>m;
   rep(i,0,n)col[i]=-1;
   rep(i,0,m){
      int x,y; cin>>x>>y; x--; y--;
      g[x].push_back(y); g[y].push_back(x);
   }
   ll a=0,b=0,c=0;
   rep(i,0,n)if(col[i]==-1){
      cnt=0; bool f=dfs(i,0);
      if(cnt==1)a++;
      else if(f)b++; else c++;
   }
   cout<<(a*a+a*(n-a)*2)+(b+c)*(b+c)+b*b<<endl;
   return 0;
}
