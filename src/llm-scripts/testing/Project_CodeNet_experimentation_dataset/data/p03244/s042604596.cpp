#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,v,m,i;
  map<int,int> m0,m1;
  vector<pair<int,int>> v0,v1;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>v;
    if(i%2==0){
      if(m0.count(v)) m0.at(v)++;
      else m0[v]=1;
    }
    else if(i%2==1){
      if(m1.count(v)) m1.at(v)++;
      else m1[v]=1;
    }
  }
  for(auto z:m0) v0.push_back(make_pair(z.second,z.first));
  sort(v0.begin(),v0.end());
  reverse(v0.begin(),v0.end());
  for(auto z:m1) v1.push_back(make_pair(z.second,z.first));
  sort(v1.begin(),v1.end());
  reverse(v1.begin(),v1.end());
  if(v0.at(0).second!=v1.at(0).second) cout<<n-v0.at(0).first-v1.at(0).first<<endl;
  else if(v0.at(0).first+v1.at(0).first==n) cout<<n/2<<endl;
  else if(v0.size()>1&&v0.size()>1){
    m=max(v0.at(0).first+v1.at(1).first,v0.at(1).first+v1.at(0).first);
    cout<<n-m<<endl;
  }
  else if(v0.size()>1) cout<<n/2-v0.at(1).first<<endl;
  else if(v1.size()>1) cout<<n/2-v1.at(1).first<<endl;
}