#include <iostream>
#include <cstring>
#include <cstdio>

#define Maxn 4010
#define Maxm 4010

using namespace std;

int read() {
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while('0' <= c && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

int N,M,Q;
int mp[Maxn][Maxm],sum1[Maxn][Maxm],sum2[Maxn][Maxm];

int main() {
	N = read(); M = read(); Q = read();
	char ch;
	for(int i = 1;i <= N; i++)
		for(int j = 1;j <= M; j++) {
			int x = i * 2 - 1,y = j * 2 - 1;
			ch = getchar();
			while(ch != '0' && ch != '1') ch = getchar();
			if(ch == '1') mp[x][y] = 1;
		}
	for(int i = 1;i <= N; i++)
		for(int j = 1;j <= M; j++) {
			int x = i * 2 - 1,y = j * 2 - 1;
			if(mp[x][y]) {
				if(mp[x - 2][y]) mp[x - 1][y] = 2;
				if(mp[x + 2][y]) mp[x + 1][y] = 2;
				if(mp[x][y + 2]) mp[x][y + 1] = 2;
				if(mp[x][y - 2]) mp[x][y - 1] = 2;
			}
		}
	for(int i = 1;i < N * 2; i++)
		for(int j = 1;j < M * 2; j++) {
			if(mp[i][j] == 1) sum1[i][j] = sum1[i - 1][j] + sum1[i][j - 1] - sum1[i - 1][j - 1] + 1;
			else sum1[i][j] = sum1[i - 1][j] + sum1[i][j - 1] - sum1[i - 1][j - 1];
			if(mp[i][j] == 2) sum2[i][j] = sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1] + 1;
			else sum2[i][j] = sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1];
		}
	int i_1,j_1,i_2,j_2,x_1,y_1,x_2,y_2;
	for(int k = 1;k <= Q; k++) {
		i_1 = read(); j_1 = read(); i_2 = read(); j_2 = read();
		x_1 = i_1 * 2 - 1; y_1 = j_1 * 2 - 1;
		x_2 = i_2 * 2 - 1; y_2 = j_2 * 2 - 1;
		int ans1 = sum1[x_2][y_2] + sum1[x_1 - 1][y_1 - 1] - sum1[x_2][y_1 - 1] - sum1[x_1 - 1][y_2];
		int ans2 = sum2[x_2][y_2] + sum2[x_1 - 1][y_1 - 1] - sum2[x_2][y_1 - 1] - sum2[x_1 - 1][y_2];
		printf("%d\n",ans1 - ans2);
	}
	return 0;
}