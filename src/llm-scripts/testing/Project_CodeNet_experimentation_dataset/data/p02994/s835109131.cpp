#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1e9;
const int mod = 1000000007;

int main(){
  int N,L;
  cin>>N>>L;
  int MIN=INF,sum=0;
  for(int i=1;i<=N;i++){
    sum+=L+i-1;
  }
  int ans=0;
  for(int i=1;i<=N;i++){
    int x=sum-(L+i-1);
    if(abs(sum-x)<MIN){MIN=abs(sum-x);ans=x;}
  }
  cout<<ans<<endl;
  return 0;                       
}