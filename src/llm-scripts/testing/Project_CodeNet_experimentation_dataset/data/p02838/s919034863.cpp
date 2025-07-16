# include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin>>N;
  long long A[N];
  long long O[65];
  for(long long i=0;i<65;i++){
    O[i]=0;
  }
  
  for(long long i=0;i<N;i++){
    cin>>A[i];
    int count=0;
    long long temp=A[i];
    while(temp!=0){
      O[count]+= temp%2;
      temp/=2;
      count++;
    }
    //cout<<i<<" "<<A[i]<<" "<<count<<" "<<O[count]<<endl;
  }
  long long ans=0;
  long long t=1;
  for(long long i=0;i<63;i++){
    ans=(ans+((t*O[i])%1000000007)*(N-O[i]))%1000000007;
    t=(t*2)%1000000007;
    //cout<<i<<" "<<O[i]<<" "<<ans<<endl;
  }
  
  cout<<ans<<endl;
  return 0;
}


