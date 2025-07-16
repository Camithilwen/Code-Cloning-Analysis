#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int H, W, N;
  cin >> H >> W >> N;

  int max_len = max(H, W);
  if(N % max_len == 0) cout << (N / max_len) << endl;
  else cout << (N / max_len) + 1 << endl;

  return 0;
}
