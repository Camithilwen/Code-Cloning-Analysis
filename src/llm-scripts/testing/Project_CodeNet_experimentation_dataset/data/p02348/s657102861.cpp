#include <bits/stdc++.h>
using namespace std;

int n, q;

const long long inf = (1ll << 31) - 1;
const int max_n = (1 << 17);

long long seg[max_n * 2 - 1];
long long lazy[max_n * 2 - 1];

void init()
{
  int _n = n;

  n = 1;
  while (n < _n) n *= 2;

  fill(seg, seg + 2 * n - 1, inf);
  fill(lazy, lazy + 2 * n - 1, inf + 1);
}

void update(int a, int b, int x, int k = 0, int l = 0, int r = n)
{
  if (a <= l && r <= b){
    lazy[k] = x;
    return;
  }
  if (r <= a || b <= l){
    return;
  }

  if (lazy[k] != inf + 1) {
    lazy[k * 2 + 1] = lazy[k * 2 + 2] = lazy[k];
  }
  lazy[k] = inf + 1;
  update(a, b, x, k * 2 + 1, l, (l + r) / 2);
  update(a, b, x, k * 2 + 2, (l + r) / 2, r);
}

void find(int a, int b, int k = 0, int l = 0, int r = n)
{
  if (a <= l && r <= b){
    if (lazy[k] != inf + 1){
      seg[k] = lazy[k];
    }
    lazy[k] = inf + 1;
    return;
  }
  else if (r <= a || b <= l){
    return;
  }
  else {
    if (lazy[k] != inf + 1){
      lazy[k * 2 + 1] = lazy[k * 2 + 2] = lazy[k];
      lazy[k] = inf + 1;
    }
    find(a, b, k * 2 + 1, l, (l + r) / 2);
    find(a, b, k * 2 + 2, (l + r) / 2, r);
  }
}

int main()
{
  cin >> n >> q;
  init();
  for (int i = 0; i < q; i++){
    int f;
    cin >> f;

    if (f == 0){
      int s, t, x;

      cin >> s >> t >> x;
      update(s, t + 1, x);
      /*
      for (int i = 0; i < n * 2 - 1; i++){
        cout << lazy[i] << " ";
      }
      puts("");
      */
    } else {
      int i;

      cin >> i;
      find(i, i + 1);

      /*
      for (int i = 0; i < n * 2 - 1; i++){
        cout << seg[i] << " ";
      }
      puts("");
      */
      cout << seg[i + n - 1] << endl;
    }
  }
}