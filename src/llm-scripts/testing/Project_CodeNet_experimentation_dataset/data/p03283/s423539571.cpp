#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m, q;
  cin >> n >> m >> q;
  int d[509][509];
  memset(d, 0, sizeof(d));
  for(int i=0;i<m;i++){
    int l, r;
    cin >> l >> r;
    d[l][r] += 1;
  }
  for(int i=1;i<=n-1;i++){
    d[i][i+1] += d[i][i] + d[i+1][i+1];
  }
  for(int i=2;i<n;i++){
    for(int j=0;j+i<=n;j++){
      d[j][j+i] += d[j][j+i-1]+d[j+1][j+i]-d[j+1][j+i-1];
    }
  }
  for(int i=0;i<q;i++){
    int l, r;
    cin >> l>> r;
    cout << d[l][r] << endl;
  }
}

