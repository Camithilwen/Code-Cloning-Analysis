#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll; //10^19 < 9223372036854775807
typedef unsigned long long ull; //10^20 < 18446744073709551615


int main(){
  int n;cin>>n;
  vector<int> p(n);
  rep(i,n) cin>>p.at(i);
  int ans=0;
  int min=p.at(0);
  for(int i=0;i<n;i++){
	if(p.at(i)<=min){
      ans+=1;
      min=p.at(i);
    }
  }
  cout<<ans;

}