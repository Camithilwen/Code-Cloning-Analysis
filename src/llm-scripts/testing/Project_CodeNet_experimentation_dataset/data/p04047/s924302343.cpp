#include <iostream>
#include <algorithm>

signed main() {
  int n;
  std::cin >> n;
  n = 2*n;

  int l[n];
  for(int i = 0; i < n; i++)
    std::cin >> l[i];

  std::sort(l, l+n);

  int ans = 0;
  for(int i = n-2; i >= 0; i -= 2)
    ans += l[i];

  std::cout << ans << std::endl;
  
  return 0;
}
