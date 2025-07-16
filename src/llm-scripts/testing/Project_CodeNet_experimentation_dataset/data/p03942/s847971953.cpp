#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
void read(int&a) {
	a = 0; char k = getchar(); int f = 1;
	for(;!isdigit(k); k = getchar()) if (k == '-') f = -1;
	for(; isdigit(k); k = getchar()) a = a * 10 + k - '0';
	a *= f;
}
const int N = 1e6 + 5;
int n, a[N], b[N], flag = true;
char s[N];
queue<int> Q;
int main()
{
	scanf("%d", &n);
	scanf("%s", s); for(int i = 0; i < n; ++i) a[i] = s[i] - 'a' + 1;
	scanf("%s", s); for(int i = 0; i < n; ++i) b[i] = s[i] - 'a' + 1, flag &= b[i] == a[i];
	int s = n - 1, t = n - 1;
	if(flag) {
		printf("0\n");
		return 0;
	}
	int ans = 1;
	while(t >= 0) {
		while(t > 0 && b[t] == b[t - 1]) t -= 1;
		while(s >= 0 && (s > t || a[s] != b[t])) s -= 1;
		if(s < 0) {
			printf("-1\n");
			return 0;
		}
		while(Q.size() && Q.front() - Q.size() >= t) Q.pop();
		if(s != t) Q.push(s);
		ans = max(ans, (signed)Q.size() + 1);
		--t;
	}
	printf("%d\n", ans);
	return 0;
}






































