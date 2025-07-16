#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstdlib>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;

int query(int pos){
  cout << pos << '\n';
  cout << flush;
  string s;
  cin >> s;
  if(s == "Vacant")
    exit(0);
  else if(s == "Female")
    return 1;
  else
    return 2;
  return 0;
}

int v[1 + nmax];

void extract(int from, int to){
  if(from + 2 == to)
    v[from + 1] = query(from + 1);
  else {
    int mid = (from + to) / 2;
    if((mid - from) % 2 == 1)
      mid--;
    v[mid] = query(mid);
    if(v[from] != v[mid])
      extract(from, mid);
    else
      extract(mid, to);
  }
}

int main()
{
  int n;
  cin >> n;
  v[0] = query(0);
  v[n - 1] = query(n - 1);
  extract(0, n - 1);
  return 0;
}
