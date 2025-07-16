#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	map<int, int> m;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int A;
		scanf("%d", &A);
		if (m[A] == 1) {
			m[A] = 0;
			ans--;
		} else {
			m[A] = 1;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
