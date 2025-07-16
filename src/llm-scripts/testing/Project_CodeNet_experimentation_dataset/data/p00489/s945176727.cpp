#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)

int main() {

	int N;
	vector<int> s(123),t;

	scanf("%d", &N);

	REP(i, N *(N - 1) / 2) {
		int A, B, C, D;
		scanf("%d %d %d %d", &A, &B, &C, &D);
		s[A-1] += (C > D) ? 3 : 0;
		s[B-1] += (C < D) ? 3 : 0;
		if (C == D) {
			s[A-1]++;
			s[B-1]++;
		}
	}

	t = s;
	sort(t.begin(), t.begin() + N);

	REP(i, N) {
		printf("%d\n", N - distance(t.begin(), upper_bound(t.begin(), t.begin() + N, s[i])) + 1);
	}

	return 0;
}