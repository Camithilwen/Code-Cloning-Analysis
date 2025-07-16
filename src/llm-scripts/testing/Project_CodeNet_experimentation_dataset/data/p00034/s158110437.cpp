#include <iostream>

using namespace std;

void solve()
{
	int l[10];
	while(cin >> l[0])
	{
		for(int i = 1; i <= 9; ++i)
		{
			scanf(",%d", &l[i]);
		}
		int v[2];
		scanf(",%d,%d", &v[0], &v[1]);
		int sum = 0;
		for(int i = 0; i < 10; ++i)
		{
			sum += l[i];
		}
		double time = (double)sum / (v[0] + v[1]);
		double dist = time * (double)v[0];
		int pos = 0;
		int d = 0;
		while(true)
		{
			d += l[pos];
			if(d >= dist)
			{
				cout << pos + 1 << endl;
				break;
			}
			++pos;
		}
	}
}

int main()
{
	solve();
	return(0);
}