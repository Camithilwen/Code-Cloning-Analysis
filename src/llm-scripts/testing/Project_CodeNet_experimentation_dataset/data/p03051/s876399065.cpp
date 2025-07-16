#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
std::vector<int> dpa(1234567,0),dpb(1234567,1),memo(1234567,0);
int pw(int n,int k){
  int res=1;
  while(k){
    if(k&1)res*=n;res%=MOD;
    n*=n;n%=MOD;
    k>>=1;
  }
  return res;
}
//main
signed main(){
  int N;cin>>N;
  std::vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i];
  int now=0,zco=0;
  for(int i=0;i<N;i++){
    now^=v[i];
    if(now==0)zco++;
    else{
      dpb[now]+=dpa[now]*(zco-memo[now]);dpb[now]%=MOD;
      dpa[now]+=dpb[now];dpa[now]%=MOD;
      memo[now]=zco;
    }
  }
  if(now)cout<<dpb[now]<<endl;
  else{
    int ans=0;
    for(int i=0;i<1234567;i++)ans+=dpa[i];
    cout<<(ans+pw(2,zco-1))%MOD<<endl;
  }
}
