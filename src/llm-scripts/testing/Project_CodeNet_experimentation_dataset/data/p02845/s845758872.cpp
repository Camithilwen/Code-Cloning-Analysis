#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)n;i++)
using namespace std;

int main(){
  int N,a;cin>>N;
  vector<int> A(N+2,0);
  A[0]=3;
  long long c=1;
  REP(i,N){
    scanf("%d",&a);
    c*=(A[a]-A[a+1]++);
    c%=1000000007;
  }
  cout<<c<<endl; 
}