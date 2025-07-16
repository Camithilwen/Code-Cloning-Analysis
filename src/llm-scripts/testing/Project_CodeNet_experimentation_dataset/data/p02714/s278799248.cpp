#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  vector<int> r(n);
  vector<int> g(n);
  vector<int> b(n);
  for(int i=0;i<n;i++){
    if(i){
      r[i]=r[i-1];
      g[i]=g[i-1];
      b[i]=b[i-1];
    }
    if(s[i]=='R') r[i]++;
    else if(s[i]=='G') g[i]++;
    else b[i]++;
  }
  
  long long ans=0;
  
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n-1;j++){
      if(s[i]!=s[j]){
        if(s[i]=='R'){
          if(s[j]=='G'){
            ans+=b[n-1]-b[j];
            int l=j*2-i;
            if(l<n){
              if(s[l]=='B') ans--;
            }
          }
          else{
            ans+=g[n-1]-g[j];
            int l=j*2-i;
            if(l<n){
              if(s[l]=='G') ans--;
            }
          }
        }
        else if(s[i]=='G'){
          if(s[j]=='B'){
            ans+=r[n-1]-r[j];
            int l=j*2-i;
            if(l<n){
              if(s[l]=='R') ans--;
            }
          }
          if(s[j]=='R'){
            ans+=b[n-1]-b[j];
            int l=j*2-i;
            if(l<n){
              if(s[l]=='B') ans--;
            }
          }
        }
        else{//B
          if(s[j]=='G'){
            ans+=r[n-1]-r[j];
            int l=j*2-i;
            if(l<n){
              if(s[l]=='R') ans--;
            }
          }
          if(s[j]=='R'){
            ans+=g[n-1]-g[j];
            int l=j*2-i;
            if(l<n){
              if(s[l]=='G') ans--;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}