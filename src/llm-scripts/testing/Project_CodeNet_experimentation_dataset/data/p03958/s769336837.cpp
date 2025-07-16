#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int k,t;
  cin>>k>>t;
  if(t==1){
    cout<<k-1<<endl;
    return 0;
  }
  int vec[t];
  for(int i=0;i<t;i++){
    cin>>vec[i];
  }
  sort(vec,vec+t);
  if(vec[t-1]<=(k+1)/2){
    cout<<0<<endl;
    return 0;
  }
  int ans=(vec[t-1]-(k+1)/2)*2;
  if(k%2==0){
    ans--;
  }
  cout<<ans<<endl;
}