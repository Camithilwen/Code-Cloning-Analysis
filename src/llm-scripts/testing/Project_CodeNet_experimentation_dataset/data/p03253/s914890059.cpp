#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=1000000007;
int64_t f(int64_t x,int64_t y){
if(y==0)
  return 1;
  else if(y%2==0)
    return (f(x,y/2)*f(x,y/2))%mod;
  else
    return (f(x,y/2)*((x*f(x,y/2))%mod))%mod;
}
int64_t comb(int64_t x,int64_t y){
int64_t ans=1;
  for(int64_t i=y;1<=i;i--){
  ans=(f(i,mod-2)*((ans*(x-y+i))%mod))%mod;
  }return ans;

}
int main(){
int64_t N,M;
  cin>>N>>M;
  int64_t m=M;
  vector<int64_t>A={};
  for(int64_t i=2;i*i<=m;i++){
  if(M%i==0){
    int64_t a=0;
    while(M%i==0){
    M/=i; a++;
    }A.push_back(a);
  
  }
  }if(M!=1)
    A.push_back(1);
  int L=A.size();
  int64_t ans=1;
  for(int i=0;i<L;i++){
    int64_t a=A.at(i);
    ans=(ans*comb(N-1+a,a))%mod;
  }cout<<ans<<endl;        
     return 0;
}
