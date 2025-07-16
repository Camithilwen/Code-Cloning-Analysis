#include <bits/stdc++.h>
using namespace std;

int main(){
  int K,N;
  cin>>N>>K;
  double p[N];
  vector<double>t(N+1,0);
  for(int i=0;i<N;i++){
    cin>>p[i];
    t[i+1]=t[i]+p[i]*(0.5)+0.5;
    //cout<<i<<" "<<t[i]<<endl;
  }
  double maxp=0;
  for(int i=0;i<N-K+1;i++){
    maxp=max(maxp,t[i+K]-t[i]);
  }
  cout<<setprecision(18)<<maxp<<endl;
  return 0;
}

  