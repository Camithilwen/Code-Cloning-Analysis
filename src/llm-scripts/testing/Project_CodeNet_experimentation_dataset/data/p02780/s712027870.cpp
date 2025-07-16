#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,K; cin>>N>>K;
  vector<int>A(N);
  vector<long double>sum(N+K);
  for(int i=0;i<N;i++){
    cin>>A[i];
    sum[i]+=A[i]+1;
    sum[i+K]-=A[i]+1;
  }
  for(int i=1;i<N+K;i++)sum[i]+=sum[i-1];
  sort(sum.begin(),sum.end());
  cout<<fixed<<setprecision(10)<<sum[N+K-1]/2<<endl;
}