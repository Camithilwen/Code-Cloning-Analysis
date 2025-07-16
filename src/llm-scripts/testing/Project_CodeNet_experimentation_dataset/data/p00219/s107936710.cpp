#include<bits/stdc++.h>
using namespace std;
int main(){
  while(true){
    int n; cin>>n;
    if(!n) break;
    int a[10]={};
    for(int i=0;i<n;++i){
      int c;
      cin>>c;
      ++a[c];
    }
    for(int i=0;i<10;++i){
      for(int j=0;j<a[i];++j) cout<<"*";
      if(!a[i]) cout<<"-";
      cout<<"\n";
    }
  }
  return 0;
}

