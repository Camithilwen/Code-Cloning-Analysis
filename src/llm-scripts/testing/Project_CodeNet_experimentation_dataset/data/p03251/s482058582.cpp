#include <bits/stdc++.h>
using namespace std;
void chmax(int& a, int b) {
  if (a < b) a = b;
}

void chmin(int& a, int b) {
  if (a > b) a = b;
}
  
int main () {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    chmax(X, x);
  }
  for (int i = 0; i < M; i++) {
    int y;
    cin >> y;
    chmin(Y, y);
  }
  
  if (X < Y) {
    cout << "No War" << endl;
  } else {
    cout << "War" << endl;
  }
}