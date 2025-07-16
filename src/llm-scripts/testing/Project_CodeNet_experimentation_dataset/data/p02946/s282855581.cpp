#include<bits/stdc++.h>
using namespace std;
int main(){
  int D,K;
  cin>>K>>D;
  //vector<int>ans;
  for(int k=K;k>1;k--){
    cout<<D-k+1<<" ";
  }
  cout<<D<<" ";
  for(int k=1;k<K;k++){
    cout<<D+k<<" ";
  }

}