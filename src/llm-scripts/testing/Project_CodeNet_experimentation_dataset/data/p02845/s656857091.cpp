#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int MOD=1000000007;
  int N;cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  int a=0,b=0,c=0;
  long ans=1;
  for(int i=0;i<N;i++){
    int m=0;
    if(A[i]==a)m++;
    if(A[i]==b)m++;
    if(A[i]==c)m++;
    ans=(ans*m)%MOD;
    if(A[i]==a)a++;
    else if(A[i]==b)b++;
    else if(A[i]==c)c++;
  }
  cout<<ans<<endl;
  
}