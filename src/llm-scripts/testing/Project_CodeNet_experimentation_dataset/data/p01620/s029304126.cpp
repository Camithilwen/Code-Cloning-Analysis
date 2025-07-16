#include<iostream>
#include<string>
using namespace std;
 
int main(){
 
  int n, k[100], x, i, j;
  string sta="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", s;
 
  while(cin>>n, n){
    for(i=0;i<n;i++) cin>>k[i];
    cin>>s;
 
    for(i=0;i<s.size();i++){
      for(j=0;j<56;j++){
    if(s[i]==sta[j]){
      x=j-k[i%n];
      if(x<0){
        x+=52;
        break;
      }else break;
    }
      }
      cout<<sta[x];
    }
    cout<<endl;
  }
  return 0;
}