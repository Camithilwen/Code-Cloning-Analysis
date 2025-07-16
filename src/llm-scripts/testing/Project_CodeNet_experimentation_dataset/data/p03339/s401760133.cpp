#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;

int main(){
  int n;
  string s;
  cin>>n>>s;
  
  vector<int> A(n),B(n);
  rep(i,n){
    if(i==0){
      if(s[0]=='W') A[0]=1;
      else A[0]=0;
    }
    else if(s[i]=='W') A[i]=A[i-1]+1;
    else A[i]=A[i-1];
  }
  for(int i=n-1;i>=0;i--){
    if(i==n-1){
      if(s[n-1]=='E') B[n-1]=1;
      else B[n-1]=0;
    }
    else if(s[i]=='E') B[i]=B[i+1]+1;
    else B[i]=B[i+1];
  }
  int mi=INF;
  rep(i,n){
    mi=min(mi,A[i]+B[i]);
  }
  cout<<mi-1<<endl;

  return 0;
}