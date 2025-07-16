#include <bits/stdc++.h>
 
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,m;

	cin >> n >> m;
	int l1 = 1;
	int r1 = m+1;
	int l2 = m+2;
	int r2 = 2*m+1;
	for(int i=0;i<m;i++)
	{
		if(l1 < r1)
		{
			cout << l1 << ' ' << r1 << '\n';
			l1++;
			r1--;
		}
		else if(l2 < r2)
		{
			cout << l2 << ' ' << r2 << '\n';
			l2++;
			r2--;
		}
	}
	return 0;
}
