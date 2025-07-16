#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 205;

int arr [MAX_N];

int main () {
  int n;
  cin >> n;

  n *= 2;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  int ans = 0;
  for (int i = 0; i < n; i += 2) {
    ans += arr[i];
  }

  cout << ans << endl;
}
