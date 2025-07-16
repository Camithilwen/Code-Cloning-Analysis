#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int a[3],k;
	cin>>a[0]>>a[1]>>a[2]>>k;
	sort(a,a+3);
for (int i = 0; i < k; ++i)
{
	a[2]*=2;
}
	cout<<a[0]+a[1]+a[2];

   return 0;
}
