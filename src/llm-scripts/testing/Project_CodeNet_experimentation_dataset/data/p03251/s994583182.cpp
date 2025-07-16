#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> xs(n + 1), ys(m + 1);
  cin >> xs[0] >> ys[0];
  for (int i = 1; i <= n; ++i)
    cin >> xs[i];
  for (int i = 1; i <= m; ++i)
    cin >> ys[i];
  if (*max_element(xs.begin(), xs.end()) < *min_element(ys.begin(), ys.end()))
    cout << "No War" << endl;
  else
    cout << "War" << endl;
}
