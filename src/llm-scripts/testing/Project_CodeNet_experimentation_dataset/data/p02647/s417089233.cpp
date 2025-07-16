#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int N, K;
vector<int> A;

void simulate() {
  int RUI[N + 1];
  memset(RUI, 0, sizeof(RUI));

  for (int i = 0; i < N; ++i) {
    int a = A[i];

    int left = max(0, i - a);
    int right = min(N - 1, i + a);

    RUI[left]++;
    RUI[right + 1]--;
  }

  int sum = 0;
  for (int i = 0; i < N; ++i) {
    sum += RUI[i];
    A[i] = sum;
  }
}

int main() {
  cin >> N >> K;

  int a;
  for (int i = 0; i < N; ++i) {
    cin >> a;
    A.push_back(a);
  }

  for (int i = 0; i < min(100, K); ++i) {
    simulate();
  }

  for (int i = 0; i < N; ++i) {
    cout << A[i];

    if (i != N - 1) {
      cout << " ";
    }
  }

  cout << endl;

  return 0;
}
