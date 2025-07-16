#include <bits/stdc++.h>

using namespace std;



int main() {

  char arr[10];
  scanf("%s", arr);
  int rCount = 0, ans = 0;
  for (int i = 0; i < 3; ++i) {
    if (arr[i] == 'R') {
      rCount++;
    } else {
      ans = max(ans, rCount);
      rCount = 0;
    }
  }
  ans = max(ans, rCount);
  printf("%d\n", ans);
  

  return 0;
}