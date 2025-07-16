#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B;
  string S,ans="No";
  cin>>A>>B>>S;
  int SS=S.size();
  if((A+B+1)!=SS){
    cout<<ans<<endl;
    return 0;
  }
  rep(i,SS){
    if(i!=A&&S[i]=='-'){
      cout<<ans<<endl;
      return 0;
    }
  }
  if(S[A]=='-')ans="Yes";
  cout<<ans<<endl;
  return 0;
}