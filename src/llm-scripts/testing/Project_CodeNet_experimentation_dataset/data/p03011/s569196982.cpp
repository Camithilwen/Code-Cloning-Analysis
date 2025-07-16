#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v;
  int x;
  cin >> x;
  v.push_back(x);
  cin >> x;
  v.push_back(x);
  cin >> x;
  v.push_back(x);
  sort(v.begin(), v.end());
  cout<<v[0] +v[1];
	return 0;
}
