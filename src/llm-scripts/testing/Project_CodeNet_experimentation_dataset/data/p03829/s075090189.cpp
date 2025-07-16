#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,A,B,n;
  cin>>N>>A>>B>>n;
  vector<int> C(N);
  C[0]=n;
  int ans=0;
  for(int i=1;i<N;i++){
    cin>>C[i];
    ans+=min((C[i]-C[i-1])*A,B);
  }
  cout<<ans<<endl;
}