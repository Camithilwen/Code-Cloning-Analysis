#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=1000000007;
int64_t f(int64_t x,int64_t y){
if(y==0)
  return 1;
  else if(y%2==0)
    return (f(x,y/2)*f(x,y/2))%mod;
  else
    return (x*((f(x,y/2)*f(x,y/2))%mod))%mod;
}
int64_t comb(int64_t n,int64_t k){
int64_t a=1;
  for(int64_t i=1;i<=k;i++){
  a=(a*(n+1-i))%mod;
    a=(a*f(i,mod-2))%mod;
  }return a;

}
int main(){
int64_t N,M,K;
  cin>>N>>M>>K;
  int64_t ans=0;
  for(int64_t i=1;i<M;i++)
    ans=(ans+i*(M-i))%mod;
  ans=(((ans*N)%mod)*N)%mod;
  int64_t ans1=0;
  for(int64_t i=1;i<N;i++)
    ans1=(ans1+i*(N-i))%mod;
  ans1=(((ans1*M)%mod)*M)%mod;
  ans=(ans+ans1)%mod;
  ans=(ans*comb(N*M-2,K-2))%mod;
  cout<<ans<<endl;
    return 0;
}