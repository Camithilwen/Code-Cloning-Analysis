#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,x;
  cin>>N>>x;
  vector<int> A(N);
  for(int &i:A)cin>>i;
  sort(A.begin(),A.end());
  int ans=0;
  for(int i=0;i<N;i++){
    x-=A[i];
    if(x<0)break;
    ans++;
  }
  if(ans==N && x!=0)cout<<N-1<<endl;
  else cout<<ans<<endl;
}