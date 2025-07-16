#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;
signed main(){
  int N,ans=1;
  cin>>N;
  vector<int> A(3,-1);
  while(N--){
    int a;
    cin>>a;
    vector<int> B(0);
    for(int i=0;i<3;i++)
      if(A[i]+1==a)
        B.push_back(i);
    if(B.size()==0){
      puts("0");
      return 0;
    }
    ans=ans*((int)B.size())%mod;
    A[B[0]]++;
  }
  cout<<ans<<endl;
}