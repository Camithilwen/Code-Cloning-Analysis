#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
int k[1000000];
int p(int A,int B){
  if(!B)return 1;
  if(B%2)return p(A,B-1)*A%mod;
  int C=p(A,B/2);
  return C*C%mod;
}
int c(int A,int B){
  if(A<B)return 0;
  return k[A]*p(k[A-B]*k[B]%mod,mod-2)%mod;
}
signed main(){
  k[0]=1;
  for(int i=1;i<=1000000;i++)k[i]=k[i-1]*i%mod;
  int N,M;
  cin>>N>>M;
  map<int,int> A;
  for(int i=2;i<=M/i;i++)
    for(;M%i==0;M/=i)A[i]++;
  if(M!=1)A[M]++;
  int ans=1;
  for(pair<int,int> p:A)ans=ans*c(N+p.second-1,N-1)%mod;
  cout<<ans<<endl;
}