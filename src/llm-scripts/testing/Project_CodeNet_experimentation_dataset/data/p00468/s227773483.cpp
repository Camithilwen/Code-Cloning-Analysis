#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  int n,m,ans=0;
  cin >> n >> m;
  while(n!=0||m!=0){
    ans = 0;
    n++;
    vector<int>a(m,0),b(m,0),hito(n,0),one(n,0);
    rep(i,m){
      cin>>a[i]>>b[i];
      if(a[i]==1){
	hito[b[i]]++;
	one[b[i]]++;
      }
      if(b[i]==1){
	hito[a[i]]++;
	one[a[i]]++;
      }
    }
    rep(i,n){
      if(i==0||i==1)continue;
      rep(j,m){
	if(one[i]!=0){
	  if(i==a[j])hito[b[j]]++;
	  if(i==b[j])hito[a[j]]++;
	}
      }
    }
    rep(i,n){
      if(i==0||i==1)continue;
      if(hito[i]!=0){
	ans++;
      }
    }
    cout<<ans<<endl;
    cin >> n >> m;
  }
  return (0);
}