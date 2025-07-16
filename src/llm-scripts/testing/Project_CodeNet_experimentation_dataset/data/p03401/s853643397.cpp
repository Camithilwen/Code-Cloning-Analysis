#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,l=0;
  cin>>n;
  vector<int> a(n+2);
  for(i=1;i<=n;i++) cin>>a.at(i);
  for(i=0;i<n+1;i++) l+=abs(a.at(i+1)-a.at(i));
  for(i=1;i<n+1;i++){
    if((a.at(i+1)-a.at(i))*(a.at(i)-a.at(i-1))>=0) cout<<l<<endl;
    else cout<<l-2*min(abs(a.at(i+1)-a.at(i)),abs(a.at(i)-a.at(i-1)))<<endl;
  }
}