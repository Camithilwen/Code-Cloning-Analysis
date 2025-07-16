#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
  	LLI n, t, tmp, next, ans;
  	cin >> n >> t >> tmp;
  	ans = t;
  	for(int i = 1; i < n; i++)
    {
      cin >> next;
      if( next - tmp >= t )
        ans += t;
      else
        ans += next - tmp;
      tmp = next;
    }
  	cout << ans;
	return 0;
}