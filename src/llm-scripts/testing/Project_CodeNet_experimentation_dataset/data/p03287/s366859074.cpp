#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N,M;cin>>N>>M;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  vector<int64_t>B(N+1);B.at(0)=0;
  for(int i=1;i<=N;i++)
    B.at(i)=(B.at(i-1)+A.at(i-1))%M;
  map<int64_t,int64_t>m;
  for(int i=0;i<=N;i++)
    if(m.count(B.at(i)))
       m.at(B.at(i))++;
       else
       m[B.at(i)]=1;
       int64_t ans=0;
       for(auto p:m){
       auto v=p.second;
         ans+=(v*(v-1))/2;
       }cout<<ans<<endl;
  return 0;
}
