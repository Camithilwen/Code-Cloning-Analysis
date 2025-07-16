#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	int a, b;
	cin >> a >> b;
	int ans;
	ans = (b - 1) /(a - 1);
  if((b-1)%(a-1)!=0) ans++;
	cout << ans << "\n";

	return 0;
}