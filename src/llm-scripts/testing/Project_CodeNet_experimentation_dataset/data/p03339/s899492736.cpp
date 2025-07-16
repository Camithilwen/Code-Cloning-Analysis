#include <bits/stdc++.h>
using namespace std;


int main(){
int n,mn=1000000;
  string s;
  cin>>n>>s;
  vector<int> v(n+2);
  vector<int> u(n+2);
  v[0]=0;u[0]=0;
  for(int i=0;i<n;i++){
  if(s[i]=='W'){v[i+1]=v[i]+1;}
  else v[i+1]=v[i];
  }
  reverse(s.begin(),s.end());
  for(int j=0;j<n;j++){
  if(s[j]=='E'){u[j+1]=u[j]+1;}
  else u[j+1]=u[j];
  }
  reverse(u.begin(),u.end());
  u.push_back(0);
  for(int k=0;k<=n;k++){
  mn=min(v[k]+u[k+1],mn);
  }
  cout<<mn;
  return 0;
}

