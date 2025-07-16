/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc089_a.cpp
 * time   : Thu Apr 30 18:03:36 2020
 * quest  : A - Grouping 2
 *********************************************/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cout << ((n < 3) ? 0 : (n / 3)) << "\n";
  return 0;
}
