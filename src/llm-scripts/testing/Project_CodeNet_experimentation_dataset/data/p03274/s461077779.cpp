#include <bits/stdc++.h>
using namespace std;
static const long long INF=1000000000000000000;

int main(){
  long long N;
  long long K;
  cin>>N>>K;
  long long X[N];

  for(long long i=0;i<N;i++){
    cin>>X[i];
  }
  long long ans=INF;
  for(long long i=0;i<N-K+1;i++){
    ans=min(ans,abs(X[i])+abs(X[i]-X[i+K-1]));
    ans=min(ans,abs(X[i+K-1])+abs(X[i]-X[i+K-1])); 
  }
  cout<<ans<<endl;
  return 0;
}
