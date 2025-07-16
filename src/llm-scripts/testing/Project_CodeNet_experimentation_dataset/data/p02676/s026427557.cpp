#include<bits/stdc++.h>
using namespace std;
int main(void){
  int k;string s;cin>>k>>s;
  if(s.size()>k) {for(int i=0; i<k; ++i) cout<<s[i]; cout<<"..."<<endl;}
  else cout<<s<<endl;
  return 0;
}