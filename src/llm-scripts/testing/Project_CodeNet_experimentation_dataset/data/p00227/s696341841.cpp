#include<bits/stdc++.h>
using namespace std;
main(){
  while(1){
    long long n,m;
    long long sum=0;
    cin>>n>>m;
    if(n==0&&m==0) break;
    long long p[1005];
    for(int i=0;i<n;i++){
      cin>>p[i];
      sum+=p[i];
    }
    sort(p,p+n,greater<long long>());
    for(int i=1;i<=n;i++){
      if(i%m==0){
	sum-=p[i-1];
      }
    }
    cout<<sum<<endl;
  }
}