#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 2000000
#define MOD 1000000007



int main(){
  int N,M;
  cin>>N>>M;
  vector<int> A(M);
  for(int i=0;i<M;i++){
    cin>>A.at(i);
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  int match[9]={2,5,5,4,5,6,3,7,6};
  vector<int> dp(N+1,-10000000);
  dp.at(0)=0;
  for(int i=1;i<=N;i++){
    for(int j=0;j<M;j++){
      if(i-match[A.at(j)-1]<0){
        continue;
      }
      dp.at(i)=max(dp.at(i),dp.at(i-match[A.at(j)-1])+1);
    }
  }
  int i=N;
  while(i>0){
    for(int j=0;j<M;j++){
      if(i-match[A.at(j)-1]<0){
        continue;
      }
      if(dp.at(i-match[A.at(j)-1])==dp.at(i)-1){
        cout<<A.at(j);
        i=i-match[A.at(j)-1];
        break;
      }
    }
  }
  cout<<endl;
}
