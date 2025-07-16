#include <bits/stdc++.h>
using namespace std;

char s[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;
	int n = strlen(s);
	for (int i = 0; i < n - 8; i++) cout << s[i];
	return 0;
}
