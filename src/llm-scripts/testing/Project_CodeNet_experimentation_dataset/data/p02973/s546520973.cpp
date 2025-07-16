/*
https://atcoder.jp/contests/abc134/tasks/abc134_e
N個同時に最小部分列を作る


部分列では常に増加
dp[][]がある
a[i]を見た時, どこを更新するべきか?
30 40 50 60
新たに20が来た
30 40 50 60
20
新たに45が気来た
30 40 50 60
45
vs 
30 40 45
50 60
どちらも嬉しさは変わらない 前者の方がいい


最後尾に対して数列を持っておくと,
最後尾のうちxより小さい最大のものをxに更新
条件を満たすものがなければ追加
だから全部-1にしておいて, 

20
10
-1
-1

[30が来たら]
30
10
-1
-1

[15が来たら]
20
15
-1
-1
[10が来たら]
20
10
10
-1

dp[j]<A[i]を満たす最小のjを更新


*/
#include<bits/stdc++.h>
using namespace std;
long bs(long x,const vector<long>& v){
  long l=-1,r=v.size();
  while(r-l!=1){
    long z=(l+r)/2;
    if(v[z]<x)r=z;
    else l=z;
  }
  return r;
}
int main(){
  long N;cin>>N;vector<long>A(N),dp(N,-1);
  for(long i=0;i<N;i++)cin>>A[i];
  for(long i=0;i<N;i++){
    long z=bs(A[i],dp);
    dp[z]=A[i];
  }
  long ans=0;
  for(long i=0;i<N;i++)ans+=(dp[i]!=-1);
  cout<<ans<<endl;
  
}
    
  


