#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << -1 << endl;
    return 0;
  }
  if (n % 3 == 0) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i % 3 == 0 && j % 3 < 2) {
          cout << 'a';
        } else if (i % 3 < 2 && j % 3 == 2) {
          cout << 'b';
        } else if (i % 3 == 2 && j % 3 > 0) {
          cout << 'c';
        } else if (i % 3 > 0 && j % 3 == 0) {
          cout << 'd';
        } else {
          cout << '.';
        }
      }
      cout << endl;
    }
    return 0;
  }
  if (n % 4 == 0) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i / 2 % 2 == j / 2 % 2) {
          if (i % 2 == 0) {
            cout << 'a';
          } else {
            cout << 'b';
          }
        } else {
          if (j % 2 == 0) {
            cout << 'c';
          } else {
            cout << 'd';
          }
        }
      }
      cout << endl;
    }
    return 0;
  }
  if (n % 2 == 0) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i / 2 + j / 2 == n / 2 - 1) {
          cout << '.';
        } else if ((i / 2 % 2 == j / 2 % 2) == (i / 2 + j / 2 < n / 2 - 1)) {
          if (i % 2 == 0) {
            cout << 'a';
          } else {
            cout << 'b';
          }
        } else {
          if (j % 2 == 0) {
            cout << 'c';
          } else {
            cout << 'd';
          }
        }
      }
      cout << endl;
    }
    return 0;
  }
  if (n % 4 == 1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i >= n - 3 && j >= n - 3) {
          int ni = n - 1 - i, nj = n - 1 - j;
          if (ni % 3 == 0 && nj % 3 < 2) {
            cout << 'a';
          } else if (ni % 3 < 2 && nj % 3 == 2) {
            cout << 'b';
          } else if (ni % 3 == 2 && nj % 3 > 0) {
            cout << 'c';
          } else if (ni % 3 > 0 && nj % 3 == 0) {
            cout << 'd';
          } else {
            cout << '.';
          }
        } else if (n - 5 <= i && i < n - 3 && n - 5 <= j && j < n - 3) {
          cout << '.';
        } else if (i >= n - 3 && j >= n - 5) {
          cout << (char) ('e' + ((n - j) / 2 + i) % 3);
        } else if (i >= n - 5 && j >= n - 3) {
          cout << (char) ('e' + ((n - i) / 2 + j) % 3);
        } else {
          if (i / 4 - j / 4) {
            cout << '.';
          } else if (i / 2 % 2 == j / 2 % 2) {
            if (i % 2 == 0) {
              cout << 'a';
            } else {
              cout << 'b';
            }
          } else {
            if (j % 2 == 0) {
              cout << 'c';
            } else {
              cout << 'd';
            }
          }
        }
      }
      cout << endl;
    }
    return 0;
  }
  if (n % 4 == 3) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i >= n - 3 && j >= n - 3) {
          int ni = n - 1 - i, nj = n - 1 - j;
          if (ni % 3 == 0 && nj % 3 > 0) {
            cout << 'a';
          } else if (ni % 3 > 0 && nj % 3 == 0) {
            cout << 'b';
          } else {
            cout << '.';
          }
        } else if (n - 7 <= i && i < n - 3 && n - 7 <= j && j < n - 3) {
          cout << '.';
        } else if (i >= n - 3 && j >= n - 7) {
          cout << (char) ('e' + ((n - j) / 2 + i) % 3);
        } else if (i >= n - 7 && j >= n - 3) {
          cout << (char) ('e' + ((n - i) / 2 + j) % 3);
        } else {
          if (i / 4 - j / 4) {
            cout << '.';
          } else if (i / 2 % 2 == j / 2 % 2) {
            if (i % 2 == 0) {
              cout << 'a';
            } else {
              cout << 'b';
            }
          } else {
            if (j % 2 == 0) {
              cout << 'c';
            } else {
              cout << 'd';
            }
          }
        }
      }
      cout << endl;
    }
    return 0;
  }
}
