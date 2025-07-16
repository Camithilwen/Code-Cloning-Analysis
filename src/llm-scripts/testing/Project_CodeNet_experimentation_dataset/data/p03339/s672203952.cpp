#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  string S; cin>>S;
  vector<int>E(N);
  vector<int>W(N);
  for(int i=0;i<N;i++){
    if(S.at(i)=='E')E[i]++;
    else W[i]++;
    if(i!=0){E[i]+=E[i-1];W[i]+=W[i-1];}
  }
  vector<int>ans(N);
  for(int i=0;i<N;i++){
    if(i!=0)ans[i]+=W[i-1];
    ans[i]+=E[N-1]-E[i];
  }
  sort(ans.begin(),ans.end());
  cout<<ans[0]<<endl;
}