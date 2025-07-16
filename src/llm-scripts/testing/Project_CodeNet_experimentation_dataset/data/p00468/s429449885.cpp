#include <iostream>
#include <set>

using namespace std;

class Solver {
  public:
    int n, m;
    int a[10000], b[10000];
    int solve() {
      set<int> friends, friends_friends;
      for (int i = 0; i < m; ++i) {
        if (a[i] == 1) {
          friends.insert(b[i]);
        }
      }
      for (set<int>::iterator iter = friends.begin(); iter != friends.end(); ++iter) {
        for (int i = 0; i < m; ++i) {
          if (a[i] == *iter && b[i] != 1 && friends.count(b[i]) == 0) {
            friends_friends.insert(b[i]);
          } else if (b[i] == *iter && a[i] != 1 && friends.count(a[i]) == 0) {
            friends_friends.insert(a[i]);
          }
        }
      }
      return friends.size() + friends_friends.size();
    }
};

int main() {
  Solver s;
  while (true) {
    cin >> s.n >> s.m;
    if (s.n == 0) {
      return 0;
    }
    for (int i = 0; i < s.m; ++i) {
      cin >> s.a[i] >> s.b[i];
    }
    cout << s.solve() << endl;
  }
}