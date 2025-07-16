#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  unordered_set<int> s;
  for(int i = 0; i < k; i++) {
    int d;
    cin >> d;
    s.insert(d);
  }
  while(true) {
    int temp = n;
    bool ok = true;
    while(temp) {
      int digit = temp % 10;
      if(s.count(digit)) {
        ok = false;
        break;
      }
      temp /= 10;
    }
    if(ok) break;
    n++;
  }
  cout << n;
}