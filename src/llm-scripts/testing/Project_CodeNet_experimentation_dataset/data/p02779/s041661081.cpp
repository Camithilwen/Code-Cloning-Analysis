#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  map<int,int> a;
  for(int i=0;i<n;i++){
    int p;
    cin>>p;
    a[p]++;
  }
  bool ok=true;
  for(auto x:a){
    if(x.second>=2)ok=false;
  }
  if(ok){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}