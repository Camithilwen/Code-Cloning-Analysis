#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const ll mod = 1000 * 1000 * 1000 + 7;

ll Pow(ll x, ll n) {
  ll result = 1;
  while (n > 0) {
    if (n % 2) {
      n--;
      result = result * x % mod;
    } else {
      n /= 2;
      x = x * x % mod;
    }
  }
  return result;
}

ll Inv(ll x) {
  return Pow(x, mod - 2);
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> rows(n);
  vector<bool> haveRow(n * m + 1);
  for (int i = 0; i < n; ++i) {
    cin >> rows[i];
    haveRow[rows[i]] = true;
  }

  vector<int> cols(m);
  vector<bool> haveCol(n * m + 1);
  for (int i = 0; i < m; ++i) {
    cin >> cols[i];
    haveCol[cols[i]] = true;
  }

  ll numRows = 0;
  ll numCols = 0;
  ll result = 1;

  //cerr << endl;

  for (int i = 0; i < n * m; ++i) {
    int cur = n * m - i;
    //cerr << "Processing " << cur << endl;
    //cerr << numRows << " " << numCols << " " << haveRow[cur] << " " << haveCol[cur] << endl;
    if (haveRow[cur] && haveCol[cur]) {
      numRows++;
      numCols++;
    } else if (!haveRow[cur] && !haveCol[cur]) {
      result = result * (numRows * numCols - i) % mod;
    } else if (haveRow[cur]) {
      result = result * numCols % mod;
      numRows++;
    } else {
      result = result * numRows % mod;
      numCols++;
    }
    //cerr << cur << " " << result << endl;
  }

  cout << result << endl;

  return 0;
}
