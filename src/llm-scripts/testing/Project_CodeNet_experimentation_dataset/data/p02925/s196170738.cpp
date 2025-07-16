#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0,p=0;
  cin >> n;
  vector<vector<long>> a(n,vector<long>(n-1));
  vector<vector<bool>> b(n,vector<bool>(n));
  vector<long> c(n);
  queue<long> x;
  queue<long> y;
  for(long i=0;i<n;i++) for(long j=0;j<n-1;j++) cin >> a[i][j];

  for(long i=0;i<n;i++) {
    b[i][a[i][0]-1]=true;
    if(b[a[i][0]-1][i]) {
      x.push(i);
      y.push(a[i][0]-1);
    }
  }

  while(p<n*(n-1)/2) {
    ans++;
    long z=x.size();
    if(z==0) break;
    for(long i=0;i<z;i++) {
      c[x.front()]++;
      c[y.front()]++;
      if(c[x.front()]!=n-1) {
        b[x.front()][a[x.front()][c[x.front()]]-1]=true;
        if(b[a[x.front()][c[x.front()]]-1][x.front()]) {
          x.push(x.front());
          y.push(a[x.front()][c[x.front()]]-1);
        }
      }
      if(c[y.front()]!=n-1) {
        b[y.front()][a[y.front()][c[y.front()]]-1]=true;
        if(b[a[y.front()][c[y.front()]]-1][y.front()]) {
          x.push(y.front());
          y.push(a[y.front()][c[y.front()]]-1);
        }
      }
      x.pop();
      y.pop();
    }
    p+=z;
  }
  
  if(p==n*(n-1)/2) cout << ans << endl;
  else cout << -1 << endl;
}