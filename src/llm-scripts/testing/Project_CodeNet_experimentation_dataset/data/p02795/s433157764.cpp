#include <bits/stdc++.h>
#define P pair<long long, long long>

using namespace std;
const int INF=1e5;

int main(){
  int h, w, n;
  cin >> h >> w >> n;
  int mx = max(h, w);
  cout << (n-1)/mx + 1 << endl;
}

