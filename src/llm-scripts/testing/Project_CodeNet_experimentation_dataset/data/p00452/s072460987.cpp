#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(void)
{
	int n, m;

	while (cin >> n >> m, n || m){
		vector <int> p(n + 1);
		for (int i = 0; i < n; i++){
			scanf("%d", &p[i]);
		}
		p[n] = 0;
		n++;

		vector <int> sum(n * n);
		int cnt = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				sum[cnt] = p[i] + p[j];
				// cout << sum[cnt] << " " << p[i] << " " << p[j] << endl;
				cnt++;
			}
		}

		sort(sum.begin(), sum.end());
		int ret = 0;
		for (int i = 0; i < n * n; i++){
			int diff = m - sum[i];
			if (diff < 0) continue;
			int up = *(upper_bound(sum.begin(), sum.end(), diff)-1);
			ret = max(ret, sum[i] + up);
		}

		cout << ret << endl;
	}

	return 0;
}