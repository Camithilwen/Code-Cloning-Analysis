#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
  int n, m, i, j;
  while(cin >> n >> m) {
    int vote[n] = {};
    int cost[n] = {};
    int req;
    
    for(i = 0; i < n; i++) {
      cin >> cost[i];
    }
    for(i = 0; i < m; i++) {
      cin >> req;
      for(j = 0; j < n; j++) {
	if(req >= cost[j]) {
	  vote[j]++;
	  break;
	}
      }
    }
    int ans = 0;
    for(i = 0; i < n; i++) {
      if(vote[ans] < vote[i]) {
	ans = i;
      }
    }
    cout << ans + 1 << endl;
  }
}

      
    
  