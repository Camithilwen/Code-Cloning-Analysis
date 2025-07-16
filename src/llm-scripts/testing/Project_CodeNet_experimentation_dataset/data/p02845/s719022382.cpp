#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=1000000007;
int main(){
int64_t N;
  cin>>N;
  map<int64_t,int64_t>M;
  M[-1]=3;
  for(int64_t i=0;i<N;i++)
    M[i]=0;
  int64_t ans=1;
  for(int64_t i=0;i<N;i++){
  int64_t a;
    cin>>a;
    M.at(a)++;
    if(M.at(a-1)<M.at(a)){
    ans=0; break;
    }else{
    ans=((1+M.at(a-1)-M.at(a))*ans)%mod;
    }
       }cout<<ans<<endl;
   return 0;
}
