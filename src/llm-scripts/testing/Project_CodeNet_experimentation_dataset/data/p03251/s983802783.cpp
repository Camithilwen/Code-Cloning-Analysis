#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n, m;
  cin >> n >> m;
  int x[n+1], y[m+1];
  cin >> x[0] >> y[0];
  for(int i=0; i<n; i++) cin >> x[i+1];
  for(int i=0; i<m; i++) cin >> y[i+1];
  sort(x, x+n+1);
  sort(y, y+m+1);
  string ans;
  if(x[n]>=y[0]) ans = "War";
  else ans = "No War";
  cout << ans << endl;
  return 0;
}
