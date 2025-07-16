#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  const int MAX=1e5+10;
  int n,q;
  cin>>n>>q;
  string str;
  cin>>str;
  str+=' ';
  vector<int> a(MAX,0),s(MAX,0);
  for(int i=0;i<n;i++) {
    if(str[i]=='A'&&str[i+1]=='C') a[i+1]=1;
  }
  for(int i=0;i<MAX;i++) s[i+1]=s[i]+a[i];
  int l,r;
  for(int i=0;i<q;i++) {
    cin>>l>>r;
    cout<<s[r]-s[l]<<endl;
  }
}
