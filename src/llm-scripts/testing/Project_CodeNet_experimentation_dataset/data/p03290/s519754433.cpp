#include"bits/stdc++.h"
using namespace std;

int main() {
	int D, G;
	cin >> D >> G;
	vector<int> p(D), c(D);
	for (int i = 0; i < D; i++)
	{
		cin >> p.at(i) >> c.at(i);
	}

	int min_cnt = 1<<30;
	for (int bit = 0; bit < (1<<D); bit++)
	{
		int pnt = 0;
		int cnt = 0;
		for (int i = 0; i < D; i++)
		{
			if ((bit >> i) & 1)
			{
				pnt += p.at(i) * 100 * (i + 1) + c.at(i);
				cnt += p.at(i);
			}
		}
		if (pnt >= G) { min_cnt = min(cnt, min_cnt); continue; }
		else
		{
			for (int i = D-1; i >= 0; i--) {
				if ((bit >> i) & 1) continue;
				for (int j = 0; j < p.at(i)-1; j++)
				{
					if (pnt >= G) { min_cnt = min(cnt, min_cnt); continue; }
					pnt += 100 * (i + 1);
					cnt++;
				}
			}
			if (pnt >= G) min_cnt = min(cnt, min_cnt);
		}
	}
	cout << min_cnt << endl;
}