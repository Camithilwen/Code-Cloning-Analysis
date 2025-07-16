#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int vec[n+2];
  vec[0]=0,vec[n+1]=0;
  for(int i=1;i<=n;i++){
    cin>>vec[i];
  }
  int sum=0;
  for(int i=0;i<n+1;i++){
    sum+=abs(vec[i]-vec[i+1]);
  }
  for(int i=1;i<=n;i++){
    if(vec[i-1]<=vec[i]&&vec[i]<=vec[i+1]){
      cout<<sum<<endl;
      continue;
    }
    if(vec[i-1]>=vec[i]&&vec[i]>=vec[i+1]){
      cout<<sum<<endl;
      continue;
    }
    if(vec[i-1]==vec[i]||vec[i]==vec[i+1]){
      cout<<sum<<endl;
      continue;
    }
    cout<<sum-abs(vec[i-1]-vec[i])-abs(vec[i]-vec[i+1])+abs(vec[i-1]-vec[i+1])<<endl;
  }
}