#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(1010);
  for(int i=1;i<=N;i++){
    int n=i;
    for(int j=2;j<=n/j;j++)
      for(;n%j==0;n/=j)
        A[j]++;
    if(n!=1)
      A[n]++;
  }
  int ans=1;
  for(int i:A)
    ans=ans*(i+1)%1000000007;
  cout<<ans<<endl;
}