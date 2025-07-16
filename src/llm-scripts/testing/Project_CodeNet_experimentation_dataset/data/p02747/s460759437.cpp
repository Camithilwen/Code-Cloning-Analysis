#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  string s;
  cin >> s;
  bool ok = false;
  if (s == "hi") ok = true;
  if (s == "hihi") ok = true;
  if (s == "hihihi") ok = true;
  if (s == "hihihihi") ok = true;
  if (s == "hihihihihi") ok = true;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}