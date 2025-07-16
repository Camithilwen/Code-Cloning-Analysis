#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int H, W;
	scanf("%d %d", &H, &W);
	string s[50];
	for (int i = 0; i < H; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			bool paintable = false;
			if (s[i][j] != '#') continue;
			if (j != W - 1 && s[i][j + 1] == '#') paintable = true;
			if (j != 0     && s[i][j - 1] == '#') paintable = true;
			if (i != H - 1 && s[i + 1][j] == '#') paintable = true;
			if (i != 0     && s[i - 1][j] == '#') paintable = true;
			// cout << i << " " << j << " " << paintable << "\n";
			if (!paintable) {
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}
