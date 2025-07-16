#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

vector<int> pa, pb;

int find_roota(int x) {
  if (pa[x] != x) pa[x] = find_roota(pa[x]);
  return pa[x];
}

void unitea(int x, int y) {
  int nx = find_roota(x);
  int ny = find_roota(y);
  if (nx == ny) return;
  else if (nx > ny) pa[nx] = ny;
  else pa[ny] = nx;
}

int find_rootb(int x) {
  if (pb[x] != x) pb[x] = find_rootb(pb[x]);
  return pb[x];
}

void uniteb(int x, int y) {
  int nx = find_rootb(x);
  int ny = find_rootb(y);
  if (nx == ny) return;
  else if (nx > ny) pb[nx] = ny;
  else pb[ny] = nx;
}

int main() {
  int n, k, l;
  cin >> n >> k >> l;

  pa = vector<int>(n);
  pb = vector<int>(n);
  for (int i = 0; i < n; i ++) pa[i] = pb[i]= i;
  for (int i = 0; i < k; i ++) {
    int x, y;
    cin >> x >> y;
    x --, y --;
    unitea(pa[x], pa[y]);
  }
  for (int i = 0; i < l; i ++) {
    int x, y;
    cin >> x >> y;
    x --, y --;
    uniteb(pb[x], pb[y]);
  }
  for (int i = 0; i < n; i ++) {
    find_roota(i);
    find_rootb(i);
  }
  
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i ++) mp[make_pair(pa[i], pb[i])] ++;

  for (int i = 0; i < n; i ++) {
    if (i) cout << " ";
    cout << mp[make_pair(pa[i], pb[i])];
  }
  cout << endl;
}