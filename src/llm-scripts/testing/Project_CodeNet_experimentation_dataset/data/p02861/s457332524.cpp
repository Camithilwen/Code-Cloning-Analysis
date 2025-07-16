#include<bits/stdc++.h>
typedef long double ld;
using namespace std;
int main(void){
  int n; cin>>n;
  vector<pair<ld,ld>> ab(n);
  for(auto& i:ab) cin>>i.first>>i.second;
  ld res=0;
  for(int i=0; i<n; ++i) for(int j=i+1; j<n; ++j){
    ld x=ab[i].first-ab[j].first;
    ld y=ab[i].second-ab[j].second;
    res+=sqrtl(x*x+y*y)*2;
  }
  printf("%.10llf",res/n);
  return 0;
}
