#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { cout << #a << " = " << a << endl; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

enum Face : int { Top, Front, Right, Left, Back, Bottom };
struct cube {
  int f[6];
  unordered_map<int, string> mp;
  cube(){}
  /*
            1(Top)
    4(Left) 2(Front) 3(Right) 5(Back)
            6(Bottom)
  */
  cube(vector<int> const& vs){ for(int i=0; i<6; i++) f[i] = vs[i]; }
  cube(vector<string> const& vs) { for(int i=0; i<6; i++) mp[i+1] = vs[i]; }
  void roll_z() { roll(1, 2, 4, 3); }
  void roll_y() { roll(0, 2, 5, 3); }
  void roll_x() { roll(0, 1, 5, 4); }
  void roll(int i, int j, int k, int l) {
    int t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
  }

  void roll(int k) {
    if(k == 0) roll_y();
    if(k == 1) roll_x();
    if(k == 2) for(int i=0; i<3; i++) roll_y();
    if(k == 3) for(int i=0; i<3; i++) roll_x();
  }

  bool roll_top_front(int top, int front) {
    for(int k = 0; k < 6; (k & 1 ? roll_y() : roll_x()), k++)
      for(int i = 0; i < 4; roll_z(), ++i)
        if(top == f[Top] && front == f[Front]) return true;
    return false;
  }

  bool operator== (cube const& rhs) const {
    for(int i=0; i<6; i++)
      if(f[i] != rhs.f[i]) return false;
    return true;
  }

  bool isomorphic(cube rhs) const {
    for(int k = 0; k < 6; (k & 1 ? rhs.roll_y() : rhs.roll_x()), k++)
      for(int i = 0; i < 4; rhs.roll_z(), ++i)
        if(operator==(rhs)) return true;
    return false;
  }

};

int main() {

  int N; cin >> N;
  vector<cube> cs(N); rep(i, N) rep(j, 6) cin >> cs[i].f[j];
  cout << ([&]() {
    rep(i, N) REP(j, i+1, N)
      if(cs[i].isomorphic(cs[j])) return false;
    return true;
  }() ? "Yes\n" : "No\n");
  
  return 0;
}