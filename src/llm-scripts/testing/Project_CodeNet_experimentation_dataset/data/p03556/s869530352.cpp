#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N;
  cin>>N;
  int ans=1;
  while(ans*ans<=N)ans+=1;
  ans-=1;
  cout<<ans*ans<<endl;
  return 0;
}