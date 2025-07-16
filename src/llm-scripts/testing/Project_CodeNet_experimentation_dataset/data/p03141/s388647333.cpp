#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin>>N;
  vector<long> a(N);
  vector<long> b(N);
  for(int i=0;i<N;i++) cin>>a[i]>>b[i];
  vector<vector<long>> c(N,vector<long>(2));
  for(int i=0;i<N;i++) c[i][0]=a[i]+b[i],c[i][1]=i;
  sort(c.begin(),c.end());
  reverse(c.begin(),c.end());
  long A=0,B=0;
  for(int i=0;i<N;i++){
    if(i%2) B+=b[c[i][1]];
    else A+=a[c[i][1]];
  }
  cout<<A-B<<endl;
}
