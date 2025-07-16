#include <iostream>
#include <algorithm>
using namespace std;

int a, b;
int x[4],y[2];

int ans = 0;

int main() {

  for(int i = 0; i < 4; i++){
    cin >> a;
    x[i] = a;
  }

  for(int i = 0; i < 2; i++){
    cin >> b;
    y[i] = b;
  }

  sort(x, x+4);
  sort(y, y+2);
  reverse(x, x+4);
  reverse(y, y+2);

  for(int i = 0; i < 3; i++){
    ans += x[i];
  }

  ans += y[0];

  cout << ans << endl;
}