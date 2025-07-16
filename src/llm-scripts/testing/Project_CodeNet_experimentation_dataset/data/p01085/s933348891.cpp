#include <bits/stdc++.h>
using namespace std;

#define PI 4*atan(1)
#define INF 1e8

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
  int m, n_min, n_max;
  while(cin >> m >> n_min >> n_max, m||n_min||n_max){
    vector<int> P(m);
    for(int i = 0; i < m; i++){
      cin >> P[i];
    }
    int diff = 0, ans;
    for(int i = n_min; i <= n_max; i++){
      if(diff <= P[i-1] - P[i]){
        diff = P[i-1] - P[i];
        ans = i;
      }
    }
    cout << ans << endl;
  }
}