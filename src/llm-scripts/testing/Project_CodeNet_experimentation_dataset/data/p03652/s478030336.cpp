#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
void tostr(ll x,string& res){while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//template end



int main(){
   int n,m; scanf("%d%d",&n,&m);
   int a[310][310];
   rep(i,0,n)rep(j,0,m){
      scanf("%d",&a[i][j]);
      a[i][j]--;
   }
   int ans=n;
   int cnt[310],idx[310]; bool used[310];
   rep(i,0,n)cnt[a[i][0]]++;
   rep(i,0,m-1){
      int ma=0,idx2=-1;
      rep(j,0,m)if(chmax(ma,cnt[j]))idx2=j;
      chmin(ans,ma); used[idx2]=1;
      rep(j,0,m)cnt[j]=0;
      rep(j,0,n){
         while(idx[j]<m&&used[a[j][idx[j]]])idx[j]++;
         cnt[a[j][idx[j]]]++;
      }
   } printf("%d\n",ans);
   return 0;
}