#include <iostream>
#include <set>

using namespace std;

int main() {
  long long N, L[2]{};
  cin >> N;
  set<int> S;
  while (cin >> N) {
    if (!S.insert(N).second) {
      S.erase(N);
      if (N > L[0]) L[1] = L[0], L[0] = N;
      else if (N > L[1]) L[1] = N;
    }
  }
  cout << L[0] * L[1] << endl;
}
