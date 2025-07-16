#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int a,b;
  cin>>a>>b;
  
  if(a-b>0) cout<<a+a-1<<endl;
  else if(b-a>0) cout<<b+b-1<<endl;
  else cout<<a+b<<endl;
  
  return 0;
}