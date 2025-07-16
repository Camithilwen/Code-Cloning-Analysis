#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,j,ans;
  string s;
  cin>>n>>s;
  vector<vector<int>> z(2,vector<int>(n+1));
  for(i=1;i<=n;i++){
    for(j=0;j<2;j++) z.at(j).at(i)+=z.at(j).at(i-1);
    if(s.at(i-1)=='E') z.at(0).at(i)++;
    else if(s.at(i-1)=='W') z.at(1).at(i)++;
  }
  ans=n;
  for(i=1;i<=n;i++) ans=min(ans,z.at(1).at(i-1)+z.at(0).at(n)-z.at(0).at(i));
  cout<<ans<<endl;
}