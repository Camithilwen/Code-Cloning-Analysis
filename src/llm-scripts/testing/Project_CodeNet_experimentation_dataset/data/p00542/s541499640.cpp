
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {

	int sum = 0;
	int small = 114514;

	for (int i = 0; i < 4; i++) {
		int t;
		scanf("%d", &t);
		sum += t;
		small = min(small, t);
	}
	sum -= small;

	int t,u;
	scanf("%d", &t);
	scanf("%d", &u);

	printf("%d\n", sum + max(t, u));

	return 0;
}