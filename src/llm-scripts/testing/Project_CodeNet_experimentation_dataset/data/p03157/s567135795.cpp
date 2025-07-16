#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool rangeCheck(ll y, ll x, ll h, ll w) {
  if (y < 0 || x < 0 || y >= h || x >= w) {
    return false;
  } else {
    return true;
  }
}

void outputDone(ll h, ll w, vector<vector<ll>> a) {
  for (ll i = 0; i < h; i++) {
    for (ll j = 0; j < w; j++) {
      printf("%3d", a[i][j]);
    }
    cout << endl;
  }
  return;
}

int main() {
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (ll i = 0; i < h; i++) {
    cin >> s[i];
  }

  ll ans = 0;
  vector<vector<ll>> done(h, vector<ll>(w, -1));
  stack<pair<ll, ll>> st;
  ll dirY[] = {1, 0, -1, 0};
  ll dirX[] = {0, 1, 0, -1};
  ll cnt = 0;
  for (ll i = 0; i < h; i++) {
    for (ll j = 0; j < w; j++) {
      if (s[i][j] == '.' || done[i][j] != -1) {
        continue;
      }
      ll blackCnt = 0, whiteCnt = 0;
      bool flag;
      pair<ll, ll> xy;
      xy.first = i;
      xy.second = j;
      st.push(xy);
      while (!st.empty()) {
        xy = st.top();
        st.pop();
        //printf("y=%d x=%d\n",xy.first,xy.second);
        if (done[xy.first][xy.second] != -1) {
          continue;
        }
        if (s[xy.first][xy.second] == '#') {
          flag = false;
        } else {
          flag = true;
        }
        flag ? whiteCnt++ : blackCnt++;
        done[xy.first][xy.second] = cnt;
        for (ll k = 0; k < 4; k++) {
          ll ny = xy.first + dirY[k];
          ll nx = xy.second + dirX[k];
          bool flag2;

          if (!rangeCheck(ny, nx, h, w)) {
            continue;
          }
          if (done[ny][nx] != -1) {
            continue;
          }
          if (s[ny][nx] == '#') {
            flag2 = false;
          } else {
            flag2 = true;
          }
          if (flag == flag2) {
            continue;
          }
          pair<ll, ll> temp;
          temp.first = ny;
          temp.second = nx;
          st.push(temp);
        }
      }
      cnt++;
      ans += blackCnt * whiteCnt;
    }
  }
  // outputDone(h,w,done);
  cout << ans << endl;
  return 0;
}