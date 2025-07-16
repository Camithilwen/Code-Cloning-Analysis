#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

  int N,M;
  cin>>N;
  vector<string>S(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>S[i];
  }
  cin>>M;
  vector<string>T(M);
  for(int i=0;i<=M-1;i++){
  
    cin>>T[i];
  }
  int countplus=0;
  int countminus=0;
  int ans=0;
  for(int i=0;i<=N-1;i++){
  
    countplus=0;
    for(int j=0;j<=N-1;j++){
    
      if(S[i]==S[j])countplus++;   
    }
    countminus=0;
    for(int j=0;j<=M-1;j++){
    
      if(S[i]==T[j])countminus++;
    }
    ans=max(ans,countplus-countminus);
  }
  cout<<ans;
  return 0;
}