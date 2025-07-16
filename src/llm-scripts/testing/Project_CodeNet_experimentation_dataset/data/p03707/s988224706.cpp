#include <bits/stdc++.h>
#define MOD 1000000007

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int m = ri();
	int q = ri();
	std::string s[n];
	for (int i = 0; i < n; i++) std::cin >> s[i];
	
	std::vector<std::vector<int> > k(n + 1, std::vector<int>(m + 1));
	std::vector<std::vector<int> > yok(n, std::vector<int>(m + 1));
	std::vector<std::vector<int> > tat(n + 1, std::vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '1') {
				k[i + 1][j + 1]++;
				if (i + 1 < n && s[i + 1][j] == '1') yok[i + 1][j + 1]++;
				if (j + 1 < m && s[i][j + 1] == '1') tat[i + 1][j + 1]++;
			}
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			k[i + 1][j] += k[i][j];
			if (j < m) tat[i + 1][j] += tat[i][j];
			if (i + 1 < n) yok[i + 1][j] += yok[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			k[i][j + 1] += k[i][j];
			if (i < n) yok[i][j + 1] += yok[i][j];
			if (j + 1 < m) tat[i][j + 1] += tat[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			std::cerr << yok[i][j] << " ";
		}
		std::cerr << std::endl;
	}
	for (int i = 0; i < q; i++) {
		int x1 = ri() - 1, y1 = ri() - 1, x2 = ri() - 1, y2 = ri() - 1;
		int res = k[x2 + 1][y2 + 1] - k[x2 + 1][y1] - k[x1][y2 + 1] + k[x1][y1];
		res -= yok[x2][y2 + 1] - yok[x1][y2 + 1] - yok[x2][y1] + yok[x1][y1];
		res -= tat[x2 + 1][y2] - tat[x1][y2] - tat[x2 + 1][y1] + tat[x1][y1];
		std::cout << res << std::endl;
	}
	
	return 0;
}

