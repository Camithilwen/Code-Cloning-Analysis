#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,m,x=0,ans=0;
  cin >> n >> m;
  map<long,long> aaa;
  aaa[0]=1;
  for(long i=0;i<n;i++) {
    long a;
    cin >> a;
    x+=a;
    x=x%m;
    aaa[x]++;
    ans+=aaa[x]-1;
  }
  cout << ans << endl;
}