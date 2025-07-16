#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;
signed main(){
  int N;
  cin>>N;
  vector<int> A(64,0);
  for(int j=0;j<N;j++){
    int B;
    cin>>B;
    bitset<64> C(B);
    for(int i=0;i<64;i++)
      if(C.test(i))
        A[i]++;
  }
  int ans=0;
  for(int i=0,j=1;i<64;i++,j=j*2%mod)
    ans=(ans+j*(A[i]*(N-A[i])%mod))%mod;
  cout<<ans<<endl;
}