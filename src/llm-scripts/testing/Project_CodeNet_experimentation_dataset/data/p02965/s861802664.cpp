#include <bits/stdc++.h>
const int INF=1e9;
//const int MOD=1e9+7;
const int MOD=998244353;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
std::vector<int> Factorial(5234567),Finverse(5234567);
int pw(int n,int k){
  if(k<0)return pw(n,k+MOD-1);
  int res=1;
  while(k){
    if(k&1)res*=n;res%=MOD;
    n*=n;n%=MOD;
    k>>=1;
  }
  return res;
}
void Cinit(){
  Factorial[0]=1;
  for(int i=1;i<5234567;i++)Factorial[i]=Factorial[i-1]*i%MOD;
  for(int i=0;i<5234567;i++)Finverse[i]=pw(Factorial[i],MOD-2);
}
int nCk(int n,int k){
  if(n<k)return 1;if(k<0)return 0;
  int res=Factorial[n];
  res*=Finverse[k];res%=MOD;
  res*=Finverse[n-k];res%=MOD;
  return res;
}
//main
signed main(){
  Cinit();
  int N,M;cin>>N>>M;
  int ans=nCk(3*M+(N-1),N-1);//cout<<ans<<endl;
  int mi=N*nCk(M-1+N-1,N-1)%MOD;
  ans-=mi;
  ans+=MOD;ans%=MOD;
  //cout<<ans<<endl;
  for(int i=M+1;i<=min(N,3*M);i++){
    if((i&1)!=((3*M)&1))continue;
    int p=(3*M-i)/2;
    int q=nCk(p+N-1,N-1);
    int s=nCk(N,i);
    int a=q*s%MOD;
    ans-=a;
    ans+=MOD;ans%=MOD;
  }
  cout<<ans<<endl;
}
