# include <bits/stdc++.h>
using namespace std;

char s[1000010];
char t[1000010];

int n;

queue<int> q;

int main() {
	scanf("%d", &n); scanf("%s", s); scanf("%s", t);
	if(strcmp(s, t) == 0) { puts("0"); return 0; }
	int k = n - 1;
	int ans = 0;
	int last = -1;
	for(int i = n - 1; i >= 0; --i) {
		k = min(k, i);
		while(k >= 0 && s[k] != t[i]) --k;
		if(k < 0) { puts("-1"); return 0; }
		if(k==last) continue; last=k;
		while(q.size() && i < q.front() - (int)q.size() + 1) q.pop();
		q.push(k);
		ans = max(ans, (int)q.size());
	}
	printf("%d\n",ans);
	return 0;
}

