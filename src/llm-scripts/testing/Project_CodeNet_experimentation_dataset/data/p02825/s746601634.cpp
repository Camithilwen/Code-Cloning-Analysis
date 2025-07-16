#include<bits/stdc++.h>
using namespace std;

const int N = 1003;
int n;
char ans[N][N];
char m4[4][5] = {
	"aacd",
	"bbcd",
	"cdaa",
	"cdbb"
};
char m5[5][6] = {
	"aabbc",
	"hii.c",
	"h..jd",
	"g..jd",
	"gffee"
};
char m6[6][7] = {
	"aacd..",
	"bbcd..",
	"..aacd",
	"..bbcd",
	"ab..aa",
	"ab..bb"
};
char m7[7][8] = {
	"aabbcc.",
	"dd.dd.a",
	"..d..da",
	"..d..db",
	"dd.dd.b",
	"..d..dc",
	"..d..dc",
};

char get(int x, int y, int type) {
	switch (type) {
		case 0 : return m4[x][y];
		case 1 : return m5[x][y];
		case 2 : return m6[x][y];
		case 3 : return m7[x][y];
		default : return '.';
	}
}
int main() {
	memset(ans, '.', sizeof(ans));
	scanf("%d", &n);
	if(n == 2) {printf("-1\n"); return 0;}
	else if(n == 3) {printf("aa.\n..a\n..a"); return 0;}
	for(int i = 0; i < 4 + n % 4; i++)
		for(int j = 0; j < 4 + n % 4; j++)
			ans[n - n % 4 - 4 + i][n - n % 4 - 4 + j] = get(i, j, n % 4);
	for(int k = 0; k * 4 < n / 4 * 4 - 4; k++) 
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				ans[4 * k + i][4 * k + j] = get(i, j, 0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			printf("%c", ans[i][j]);
		printf("\n");
	}
	return 0;
}