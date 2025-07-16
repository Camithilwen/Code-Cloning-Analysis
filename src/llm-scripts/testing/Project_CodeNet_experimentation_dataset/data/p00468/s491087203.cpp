#include<bits/stdc++.h>
using namespace std;

int main() {

  int n, m;
  while( cin >> n, n ) {
    int  student[n+1]; // 2:friend 1:friends_frined 0:others
    for(int i=1; i<=n; i++) student[i] = 0;
    cin >> m;
    int a[m+1], b[m+1];
    for(int i=0; i<m; i++) {
      cin >> a[i] >> b[i];
      if( a[i] == 1 ) student[b[i]] = 2;
    }

    for(int i=0; i<m; i++) {
      if( student[a[i]] == 2 && student[b[i]] != 2 ) {
	student[b[i]] = 1;
      }
      else if( student[b[i]] == 2 && student[a[i]] != 2 ) {
	student[a[i]] = 1;
      }
    }

    int ans = 0;
    for(int i=2; i<=n; i++) {
      if( student[i] > 0 ) ans++;
    }

    cout << ans << endl;
  }
}