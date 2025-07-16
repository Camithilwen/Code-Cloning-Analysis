#include <bits/stdc++.h>

using namespace std;

int n;
char x[5];

int main() {
	scanf("%s", x);
	int ans = 0, cur = 0;
	for (int i = 0; x[i]; i++)
		if (x[i] == 'R')
			ans = max(ans, ++cur);
		else
			cur = 0;
	printf("%d\n", ans);
}
