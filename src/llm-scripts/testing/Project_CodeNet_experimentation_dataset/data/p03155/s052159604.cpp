#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N, H, W; cin >> N >> H >> W;
  cout << (N-H+1) * (N-W+1) << endl;
}
