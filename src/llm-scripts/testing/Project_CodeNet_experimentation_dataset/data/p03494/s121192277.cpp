#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int N;
  cin >> N;
  vector <int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int ans = 0;
  bool stop = false;
  while (!stop) {
    for (int i = 0; i < N; i++) {
      if (A[i]%2==0) {
        A[i] = A[i]/2;
      } else {
        stop = true;
        break;
      }
    }
    if (!stop) ans++;
  }
  cout << ans << endl;
  return 0;
}
