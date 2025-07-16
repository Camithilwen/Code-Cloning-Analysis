#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N,x;
  cin>>N>>x;
  long long A[N];
  for(long long i=0;i<N;i++){
    cin>>A[i];
  }
  long long ans=0;
  if(A[0]>x){
    ans+=A[0]-x;
    A[0]=x;
  }
  long long temp=0;
  for(long long i=1;i<N;i++){
    if(A[i-1]+A[i]>x){
      temp=A[i-1]+A[i]-x;
      ans+=temp;
      A[i]-=temp;
    }
  }
  cout<<setprecision(18)<<ans<<endl;
  return 0;
}
