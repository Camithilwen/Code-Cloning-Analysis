#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
    cin>>N;
  map<int64_t,int64_t>M;
  for(int i=0;i<N;i++){
  int64_t a; cin>>a;a*=-1;
    if(M.count(a))
      M.at(a)++;
    else
      M[a]=1;
   }int64_t ans=0;
  for(auto p:M){
  auto k=p.first;
    auto v=p.second;
    k*=-1;int64_t a=1;
    for(int i=0; ;i++){
    if(k<a)break;
      else
        a*=2;
    }int64_t b=a-k; b*=-1;
    if(-k==b)
      ans+=v/2;
    else{
    if(M.count(b)){
    int64_t c=min(v,M.at(b)); ans+=c;
      M.at(b)-=c;
    }
    }
   }cout<<ans<<endl;
  return 0;
}