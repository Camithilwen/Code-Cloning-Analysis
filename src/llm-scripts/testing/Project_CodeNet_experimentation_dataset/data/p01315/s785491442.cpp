#include <bits/stdc++.h>
using namespace std;

struct data {
  string l;
  int p, a, b, c, d, e, f, s, m;
};

int n;
vector<data> v;

bool ch(data l, data r);
void solve();
double calc(data now);

int main() {
  while(1) {
    cin >> n;
    if(n == 0) break;
    for(int i = 0; i < n; ++i) {
      data now;
      cin >> now.l >> now.p >> now.a >> now.b >> now.c >>
          now.d >> now.e >> now.f >> now.s >> now.m;
      v.push_back(now);
    }
    solve();
    for(int i = 0; i < n; ++i) cout << v[i].l << endl;
    cout << "#" << endl;
    v.erase(v.begin(), v.end());
  }
  return 0;
}

bool ch(data l, data r) {
  double nowl = calc(l), nowr = calc(r);
  if(nowl != nowr) return nowl > nowr;
  return l.l < r.l;
}

void solve() { sort(v.begin(), v.end(), ch); }

double calc(data now) {
  double sumt =
      now.a + now.b + now.c + (now.d + now.e) * now.m;
  return (now.s * now.f * now.m - now.p) / sumt;
}
