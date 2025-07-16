#include <bits/stdc++.h>
using namespace std;

int main() {
  double H, W, N;
  cin >> H >> W >> N;

  if(H >= W) cout << ceil(N/H) << endl;
  else cout << ceil(N/W) << endl;
}