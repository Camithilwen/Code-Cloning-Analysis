#include <algorithm>  // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>     // bitset
#include <cctype>     // isupper, islower, isdigit, toupper, tolower
#include <cstdint>    // int64_t, int*_t
#include <cstdio>     // printf
#include <deque>      // deque
#include <iomanip>    // fixed, setprecision
#include <iostream>   // cout, endl, cin
#include <map>        // map
#include <queue>      // queue, priority_queue
#include <set>        // set
#include <stack>      // stack
#include <string>     // string, to_string, stoi
#include <tuple>      // tuple, make_tuple
#include <unordered_map>  // unordered_map
#include <unordered_set>  // unordered_set
#include <utility>        // pair, make_pair
#include <vector>         // vector
using namespace std;

int main() {
  int64_t N, M, p, acc = 0, wac = 0;
  string s;
  cin >> N >> M;
  map<int, int> wa{};
  vector<bool> ac(N, false);
  for (int i = 0; i < M; i++) {
    cin >> p >> s;
    p--;
    if (s == "AC" && !ac[p]) ac[p] = true;
    if (s == "WA" && !ac[p]) wa[p]++;
  }

  for (int i = 0; i < N; i++) {
    if (ac[i]) {
      acc++;
      wac += wa[i];
    }
  }
  cout << acc << " " << wac << endl;
}
