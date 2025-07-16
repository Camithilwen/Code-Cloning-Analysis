#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,L;cin>>N>>L;
  int left=L;
  int right=L+N-1;
  int all=0;
  for(int i=1;i<=N;i++) all+=L+i-1;
  if(left>=0) cout<<all-L<<endl;
  else if(right<=0) cout<<all-L-N+1<<endl;
  else cout<<all<<endl;
}