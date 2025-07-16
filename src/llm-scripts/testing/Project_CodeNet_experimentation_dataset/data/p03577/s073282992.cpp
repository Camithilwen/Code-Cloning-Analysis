#include <bits/stdc++.h>
using namespace std;

const int N = 110;

char str[N];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> str;
	int len = strlen(str);
	str[len - 8] = 0;
	cout << str << "\n";
	
	return 0;
}
