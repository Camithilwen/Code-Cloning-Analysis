#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,n,ans=0;
  cin>>N>>n;
  if(n){
    puts("-1");
    return 0;
  }
  for(int i=1;i<N;i++){
    int a;
    cin>>a;
    if(n>=a)ans+=a;
    else if(n+1==a)ans++;
    else{
      puts("-1");
      return 0;
    }
    n=a;
  }
  cout<<ans<<endl;
}