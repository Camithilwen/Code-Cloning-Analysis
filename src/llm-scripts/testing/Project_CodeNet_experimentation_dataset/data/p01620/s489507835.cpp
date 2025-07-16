#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>

#define el endl
#define fd fixed
#define INF INT_MAX/2-1
#define pb push_back

using namespace std;

int main() {
  int n, tmp;
  string s, res, station = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  while (cin >> n, n) {
    int key[n];
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      key[i] = tmp;
    }
    cin >> s;
    res = "";
    for (int i = 0; i < s.length(); i++) {
      res += station[(station.find(s[i])-key[i%n]+52)%52];
    }
    cout << res << el;
  }
}