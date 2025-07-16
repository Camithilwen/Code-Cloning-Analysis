#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n;
  cin>>n;
  vector<vector<int>> x(n);
  vector<vector<int>> y(n);
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    for(int j=0;j<a;j++){
      int b,c;
      cin>>b>>c;
      x.at(i).push_back(b);
      y.at(i).push_back(c);
    }
  }
  int count=0;
  bool check=true;
  for(int tmp=0;tmp<1<<15;tmp++) {
    if (tmp>=(1<<n)) continue;
    bitset<15> s(tmp);
    for(int i=0;i<n;i++) {
      if (s[i]==0) continue;
      int a=x.at(i).size();
      for(int j=0;j<a;j++) {
        if (s[x.at(i).at(j)-1]!=y.at(i).at(j)) {
          check=false;
          break;
        }
      }
    }
    int count1=s.count();
    if(check)count=max(count1,count);
    check=true;
  }
  cout<<count<<endl;
  return 0;
}