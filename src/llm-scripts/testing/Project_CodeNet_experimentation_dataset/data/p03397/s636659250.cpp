#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<map>
#include<bitset>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1e9+7;
const ll  longinf = 1LL<<60;
const int mod=1e9+7;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

ll dp[300001][3][3];
ll all[300001];
int m,s[300003];
string t;

ll rec(int n,int a,int b){
  if(dp[n][a][b]!=-1)return dp[n][a][b];
  ll ret=0;
  if(a!=0&&b!=0)ret+=all[n+2];
  if(a!=0&&b!=1){
    if(n==m-3)ret+=rec(n+2,s[n+2],0);
    else {
      if(s[n+2]!=0)ret+=rec(n+2,1,s[n+3]);
      if(s[n+2]!=1)ret+=rec(n+2,1,0)*max(s[n+3],1);
      }
    }
  if(a!=1&&b!=0)
      ret=(ret+rec(n+2,s[n+2],s[n+3]))%mod;
    if(a!=1&&b!=1)
      ret=(ret+rec(n+2,0,s[n+3])*max(s[n+2],1))%mod;
  return dp[n][a][b]=ret%mod;
  }

int main(){
  cin>>t;
   m=t.size();
  rep(i,m){
    if(t[i]=='0')s[i]=0;
    if(t[i]=='1')s[i]=1;
    if(t[i]=='?')s[i]=2;
    }
  s[m]=0;
  rep(i,m+1)rep(j,3)rep(k,3){
    dp[i][j][k]=-1;
    }
  dp[m-1][0][0]=0;
  dp[m-1][2][0]=1;
  dp[m-1][1][0]=1;
  
  all[m]=1;
  rep(i,m){
    if(s[m-i-1]==2)all[m-i-1]=2*all[m-i]%mod;
    else all[m-i-1]=all[m-i];
    }
  cout<<rec(0,s[0],s[1])<<endl;
  return 0;
  }