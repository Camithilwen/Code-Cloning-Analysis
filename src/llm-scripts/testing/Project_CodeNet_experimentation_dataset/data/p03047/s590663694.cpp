#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
const int N = 1e5 + 7;
string x[3] = { "RGB","GBR","BRG" };
int y[3][N];
int main() {
	int n, k;
	while (cin >> n >> k) {
		cout << n - k + 1 << '\n';
	}
	return 0;
}

