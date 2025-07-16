#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  int r;
  cin>>r;
  
  if(r<1200) cout<<"ABC"<<endl;
  else if(r<2800) cout<<"ARC"<<endl;
  else cout<<"AGC"<<endl;

  return 0;
}