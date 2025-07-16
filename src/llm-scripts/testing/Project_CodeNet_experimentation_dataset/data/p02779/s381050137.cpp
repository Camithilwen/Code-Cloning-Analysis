#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  vector<int> a(n);
  for(auto& i:a) cin>>i;
  unordered_map<int,int> m;
  for(auto& i:a){ ++m[i]; if(m[i]>1){ cout<<"NO"; return 0;}}
  cout<<"YES";
  return 0;
}