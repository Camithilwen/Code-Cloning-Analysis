#include <bits/stdc++.h>
using namespace std;

int const M = 1e9 + 7;
vector<int> memo(5500000, -1);
string K; int D;

int count(size_t i, int total, bool upto) {
	if (i == K.size()) return total == 0;

	// 14 bits for index, 7 bits for total, 1 bit for upto
	int key = (i << 9) + (total << 1) + upto;
	if (memo[key] >= 0) return memo[key];

	int sum = 0, leading = K[i] - '0';
	for (int digit = 0; digit <= (upto ? leading : 9); ++digit) {
		if (digit == leading)
			sum += count(i+1, (total+digit) % D, upto);
		else
			sum += count(i+1, (total+digit) % D, false);
		sum %= M;
	}

	return memo[key] = sum;
}

int main() {
	ios_base::sync_with_stdio(false);

	getline(cin, K);
	cin >> D;

	int answer = count(0, 0, true) - 1;
	if (answer < 0) answer += M;
	cout << answer << endl;
}
