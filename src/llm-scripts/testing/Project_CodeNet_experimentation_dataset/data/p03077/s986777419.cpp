#include<bits/stdc++.h>
using namespace std;
long long mi(long long A,long long B,long long C,long long D,long long E){
  return min(min(min(min(A,B),C),D),E);
}
int main(){
  long long N,A,B,C,D,E;cin>>N>>A>>B>>C>>D>>E;
  if(mi(A,B,C,D,E)==A){cout<<(N+A-1)/A+4;return 0;}
  if(mi(A,B,C,D,E)==B){cout<<(N+B-1)/B+4;return 0;}
  if(mi(A,B,C,D,E)==C){cout<<(N+C-1)/C+4;return 0;}
  if(mi(A,B,C,D,E)==D){cout<<(N+D-1)/D+4;return 0;}
  if(mi(A,B,C,D,E)==E){cout<<(N+E-1)/E+4;return 0;}
}