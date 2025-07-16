#include <algorithm>
#include <iostream>
#include <vector>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> ng_d;
  int dd;
  vector<int> d;
  for (int i = 0; i < k; ++i) {
    cin >> dd;
    ng_d.push_back(dd);
  }
  for (int i = 0; i < 10; ++i) {
    bool ng = false;
    for (int j = 0; j < ng_d.size(); ++j) {
      if (ng_d[j] == i) {
        ng = true;
        break;
      }
    }
    if (!ng) {
      d.push_back(i);
    }
  }
  sort(d.begin(), d.end());

  int ans = d[0];
  bool ok = false;

  for (int i1 = 0; i1 < d.size(); ++i1) {
    int tmp1 = d[i1];
    if (tmp1 >= n) {
      ans = tmp1;
      goto end;
    }
  }

  for (int i1 = 0; i1 < d.size(); ++i1) {
    int tmp1 = d[i1];

    for (int i2 = 0; i2 < d.size(); ++i2) {
      int tmp2 = tmp1 * 10 + d[i2];
      if (tmp2 >= n) {
        ans = tmp2;
        goto end;
      }
    }
  }
  for (int i1 = 0; i1 < d.size(); ++i1) {
    int tmp1 = d[i1];

    for (int i2 = 0; i2 < d.size(); ++i2) {
      int tmp2 = tmp1 * 10 + d[i2];

      for (int i3 = 0; i3 < d.size(); ++i3) {
        int tmp3 = tmp2 * 10 + d[i3];
        if (tmp3 >= n) {
          ans = tmp3;
          goto end;
        }
      }
    }
  }
  for (int i1 = 0; i1 < d.size(); ++i1) {
    int tmp1 = d[i1];

    for (int i2 = 0; i2 < d.size(); ++i2) {
      int tmp2 = tmp1 * 10 + d[i2];

      for (int i3 = 0; i3 < d.size(); ++i3) {
        int tmp3 = tmp2 * 10 + d[i3];

        for (int i4 = 0; i4 < d.size(); ++i4) {
          int tmp4 = tmp3 * 10 + d[i4];

          if (tmp4 >= n) {
            ans = tmp4;
            goto end;
          }
        }
      }
    }
  }
  for (int i1 = 0; i1 < d.size(); ++i1) {
    int tmp1 = d[i1];

    for (int i2 = 0; i2 < d.size(); ++i2) {
      int tmp2 = tmp1 * 10 + d[i2];

      for (int i3 = 0; i3 < d.size(); ++i3) {
        int tmp3 = tmp2 * 10 + d[i3];

        for (int i4 = 0; i4 < d.size(); ++i4) {
          int tmp4 = tmp3 * 10 + d[i4];

          for (int i5 = 0; i5 < d.size(); ++i5) {
            int tmp5 = tmp4 * 10 + d[i5];
            if (tmp5 >= n) {
              ans = tmp5;
              goto end;
            }
          }
        }
      }
    }
  }

end:
  cout << ans << endl;
  return 0;
}
