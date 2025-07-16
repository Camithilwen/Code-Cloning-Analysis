#include <iostream>
#include <cassert>
#include <queue>

#define INF 922337203685477580
typedef long long ll;

using namespace std;

int partition(int *A, int p, int r) {
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (A[j] <= x) {
      i++;
      int a = A[i];
      A[i] = A[j];
      A[j] = a;
    }
  }
  int a = A[r];
  A[r] = A[i + 1];
  A[i + 1] = a;

  return i + 1;
}
int main() {
  int n;
  cin >> n;

  int A[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  int pos = partition(A, 0, n - 1);
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    if (i == pos) {
      cout << "[" << A[i] << "]";
    } else {
      cout << A[i];
    }
  }
  cout << endl;
  return 0;
}