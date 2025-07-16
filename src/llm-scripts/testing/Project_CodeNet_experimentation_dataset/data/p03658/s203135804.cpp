#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);
	int l[50];
	for (int i = 0; i < N; i++) {
		scanf("%d", &l[i]);
	}
	sort(l, l + N, greater<int>());
	int ans = 0;
	for (int i = 0; i < K; i++) {
		ans += l[i];
	}

	printf("%d\n", ans);
	return 0;
}
