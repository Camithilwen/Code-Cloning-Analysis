#include <bits/stdc++.h>
using namespace std;

int ts[200010];

int main(){
	int n, t;
	scanf("%d%d", &n, &t);
	for(int i = 0; i < n; i++)
		scanf("%d", &ts[i]);
	long ans = t;
	for(int i = 0; i + 1 < n; i++) {
		int time = ts[i+1] - ts[i];
		ans += (time > t) ? t : time;
	}
	printf("%ld\n", ans);
}
