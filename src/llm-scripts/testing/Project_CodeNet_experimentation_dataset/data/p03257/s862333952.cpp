#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

#define int long long

int gcd(int x, int y) {
	return (!y) ? x : gcd(y, x % y);
}

int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}

int n, A[N][N], pr[N], cnt;
bitset <100005> isp;

void prework(int tot) {
	for(int i = 1; i < 100005; ++ i) isp[i] = 1;
	isp[1] = 0;
	for(int i = 1; cnt < tot; ++ i) {
		if(isp[i]) pr[++ cnt] = i;
		for(int j = 1; j <= cnt && pr[j] * i <= 100000; ++ j) {
			isp[i * pr[j]] = 0;
			if(i % pr[j] == 0) {
				break;
			}
		}
	}
}

main() {
	isp = 0;
	cin >> n;
	n += 2;
	prework(n * 2 + 2);
	//for(int i =1; i <= cnt; ++ i) cerr << pr[i] << " ";
	//puts("");
	for(int i = 0; i <= n + 1; ++ i) {
		for(int j = 0; j <= n + 1; ++ j) {
			A[i][j] = 1;
		}
	}
	int now = 0;
	for(int i = 1; i <= n; i += 2) {
		int nx = i, ny = 1;
		int G = pr[++ now];
		while(nx <= n && ny <= n) {
			A[nx][ny] *= G;
			++ nx, ++ ny;
		}
	}
	for(int i = 3; i <= n; i += 2) {
		int nx = 1, ny = i;
		int G = pr[++ now];
		while(nx <= n && ny <= n) {
			A[nx][ny] *= G;
			++ nx, ++ ny;
		}
	}
	
	for(int i = n; i >= 1; i -= 2) {
		int nx = n, ny = i;
		int G = pr[++ now];
		while(nx && ny <= n) {
			A[nx][ny] *= G;
			-- nx, ++ ny;
		}
	}
	
	for(int i = n - ((n & 1) ^ 1); i >= 1; i -= 2) {
		int nx = i, ny = 1;
		if(i == n) continue;
		int G = pr[++ now];
		while(nx && ny <= n) {
			A[nx][ny] *= G;
			-- nx, ++ ny;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			if((i + j) & 1) {
				//cerr << i <<" " << j << endl;
				//cerr << A[i][j - 1] <<" " << A[i - 1][j] <<" " << A[i + 1][j] <<" " << A[i][j + 1] << endl;
				A[i][j] = lcm(lcm(A[i][j - 1], A[i - 1][j]), lcm(A[i + 1][j], A[i][j + 1])) + 1;
			}
		}
	}
	for(int i = 2; i <= n - 1; ++ i) {
		for(int j = 2; j <= n - 1; ++ j) {
			printf("%lld", A[i][j]);
			if(j != n - 1) putchar(' ');
			//assert(max(A[i][j], A[i - 1][j]) % min(A[i][j], A[i - 1][j]) == 0);
			//assert(max(A[i][j], A[i][j - 1]) % min(A[i][j], A[i][j - 1]) == 0);
		}
		puts("");
	}
}