#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,M,V,P;
  cin>>N>>M>>V>>P;
  vector<int> A(N);
  for(int &i:A)cin>>i;
  sort(A.rbegin(),A.rend());
  int ok=0,ng=N;
  while(ng-ok>1){
    int n=(ok+ng)/2,m=0;
    for(int i=0;i<N;i++){
      if(i<P-1)m+=M;
      else if(i>=n)m+=M;
      else if(A[n]+M-A[i]>=0)m+=A[n]+M-A[i];
      else{
        ng=n;
        goto home;
      }
    }
    if(m>=M*V || n<P-1)ok=n;
    else ng=n;
    home:;
  }
  cout<<ok+1<<endl;
}