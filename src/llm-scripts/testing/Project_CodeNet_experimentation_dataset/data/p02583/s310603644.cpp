#include<iostream>
#include<stdio.h>
using namespace std;
#include<algorithm>
#include<set>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)

const int mod=1000000007;


int main(){
  int N;
cin>>N;
vector<int>A(N);
rep(i,N)cin>>A[i];
sort(A.begin(),A.end());
int ans=0;
rep(i,N){
  rep(j,i){
    rep(k,j){
      if(A[i]!=A[j]&&A[j]!=A[k]&&A[i]<A[j]+A[k])ans++;
    }
  }
}
cout<<ans<<endl;
return 0;
}