#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,q,l,r,i;
  string s;
  vector<int> a;
  cin>>n>>q>>s;
  for(i=0;i<n-1;i++) if(s.at(i)=='A'&&s.at(i+1)=='C') a.push_back(i+1);
  for(i=0;i<q;i++){
    cin>>l>>r;
    cout<<distance(lower_bound(a.begin(),a.end(),l),lower_bound(a.begin(),a.end(),r))<<endl;
  }
}