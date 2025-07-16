#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<string> s(N);
  int g=0;
  int ans=0;
  string tans;
  for(int i=0;i<N;i++){
    cin>>s.at(i);
  }
  int M;
  cin>>M;
  vector<string> t(M);
  for(int i=0;i<M;i++){
    cin>>t.at(i);
  }
  for(int i=0;i<N;i++){
    tans=s.at(i);
    g=0;
    for(int j=0;j<N;j++){
      if(tans==s.at(j)){
        g++;
      }
    }
    for(int j=0;j<M;j++){
      if(tans==t.at(j)){
        g--;
      }
    }
    if(i==0){
      ans=g;
    }
    if(i!=0){
      if(ans<g){
        ans=g;
      }
    }
  }
  if(ans<=0){
    ans=0;
  }
  cout<<ans<<endl;
}
