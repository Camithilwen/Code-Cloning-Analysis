#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N;
  long x;
  cin >> N >> x;
  
  vector<long> a(N);
  for (int i=0; i<N; i++) {
    cin >> a.at(i);
  }
  
  sort(a.begin(), a.end());
  
  int cnt=0;
  for (int i=0; i<N; i++) {
    cnt++;
    x -= a.at(i);
    if (x<=0) {
      break;
    }
  }
  if (x!=0) cnt--;
  
  cout << cnt << endl;
  return 0;
}