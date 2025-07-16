#include <iostream>

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)

using namespace std;

int    nextInt()    { int d;      cin >> d;   return d;   }
string nextString() { string str; cin >> str; return str; }

int main() {
  while(true) {
    int N = nextInt();
    int Q = nextInt();
    if (N + Q == 0) break;
    
    int D[101] = {0};
    REP(i, N) {
      int M = nextInt();
      REP(j, M) {
        int d = nextInt();
        D[d]++;
      }
    }
    
    int max_d = -1;
    int max_idx;
    REP(i, 101) {
      if (D[i] > max_d) {
        max_d = D[i];
        max_idx = i;
      }
    }
    if (max_d < Q) {
      cout << 0 << endl;
    } else {
      cout << max_idx << endl;
    }
  }
  return 0;
}