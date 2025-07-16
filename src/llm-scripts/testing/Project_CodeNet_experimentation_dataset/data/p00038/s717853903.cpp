#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1e9+7;
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define tr(c, i) for(auto i = (c).begin(); i != (c).end(); i++)
#define rtr(c, i) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define repab(i,a,b) for(auto i=a;i<(b);i++)
#define rep(i,b) for(auto i=0;i<(b);i++)
#define pb push_back
#define sz(c) int((c).size())

enum {
  FOUR_CARD,
  FULL_HOURSE,
  STRAIGHT,
  THREE_CARD,
  TWO_PAIR,
  ONE_PAIR,
  NULL_HAND,
} hands;

int check(map<int, int> m)
{
  int maxnr = 0;
  int minnr = INF;
  int maxv = 0;
  int minv = INF;
  int maxnr_count = 0;
  tr (m, i) {
    if (maxnr < i->second) {
      maxnr_count=1;
      maxnr = i->second;
    } else if (maxnr == i->second) {
      maxnr_count++;
    }
    minnr = min(minnr, i->second);
    maxv = max(maxv, i->first);
    minv = min(minv, i->first);
  }
  if (maxnr == 4)
    return FOUR_CARD;
  if (maxnr == 3 && minnr == 2)
    return FULL_HOURSE;
  if (minnr == 1 && maxnr == 1) {
    if ((maxv - minv == 4) || (m[10] && m[11] && m[12] && m[13] && m[1]))
      return STRAIGHT;
  }
  if (maxnr == 3)
    return THREE_CARD;
  if (maxnr == 2) {
    if (maxnr_count == 2)
      return TWO_PAIR;
    else
      return ONE_PAIR;
  }

  return NULL_HAND;
}
void phand(map<int, int> m)
{
  vector<string> hand_name = {
    "four card",
    "full house",
    "straight",
    "three card",
    "two pair",
    "one pair",
    "null",
  };
  cout << hand_name[check(m)] << endl;
}

int main(int argc, char **argv)
{
  vi v;
  map<int, int> m;
  char c;
  int x, minval;

  for (;;) {
    v.clear();
    m.clear();
    rep (i, 4) {
      cin >> x;
      cin >> c;
      v.pb(x);
    }
    cin >> x;
    v.pb(x);
    if (cin.eof())
      break;

    rep (i, 5) {
      m[v[i]]++;
    }
    phand(m);
  }
  return 0;
}