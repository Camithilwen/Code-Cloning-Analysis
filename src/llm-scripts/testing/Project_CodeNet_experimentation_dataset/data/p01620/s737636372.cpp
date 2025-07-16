#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define BIG 1000000010
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
typedef long long int ll;


int main(){
  int n;
  int k[100];
  int num;
  string s;
  string ans;
  int alp[52];
  rep(i,52){
    if(i<26) alp[i]=i+65;
    else alp[i]=i+71;
  }
  while(1){
    cin>>n;
    if(n==0) break;
    rep(i,n){
      cin>>k[i];
    }
    cin>>s;
    ans="0";
    rep(i,s.size() ){
      rep(j,52){
	if(alp[j]==s[i]) num=j;
      }
      int a=(num-k[i%n]+520)%52;
      //cout<<a<<endl;
      ans+=alp[a];
      //cout<<ans<<endl;
    }
    repi(i,1,ans.size()){
      cout<<ans[i];
    }
    cout<<endl;
  }

  return 0;
}











