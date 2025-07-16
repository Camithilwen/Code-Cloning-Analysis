#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

struct Item {
  string name;
  double value;
  Item() {;}
  Item(string name, double p, double a, double b, double c, double d, double e, double f, double s, double m) : name(name) {
    value = (m * s * f - p) / (a + b + c + (d + e) * m);
  }
  bool operator<(const Item &rhs) const {
    if (fabs(value - rhs.value) > EPS) { return value > rhs.value; }
    return name < rhs.name;
  }
};

int n;
Item item[100];

int main() {
  while (scanf("%d", &n), n) {
    REP(i, n) {
      string name;
      double p, a, b, c, d, e, f, s, m;
      cin >> name >> p >> a >> b >> c >> d >> e >> f >> s >> m;
      item[i] = Item(name, p, a, b, c, d, e, f, s, m);
    }
    sort(item, item + n);
    REP(i, n) {
      cout << item[i].name << endl;
    }
    puts("#");
  }
}