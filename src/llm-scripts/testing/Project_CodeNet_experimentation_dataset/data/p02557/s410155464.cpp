#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
	reverse(b + 1, b + 1 + n);
	int l = n, r = 1;
	for(int i = 1;i <= n;i++){
		if(a[i] == b[i]) l = min(l, i), r = max(r, i);
	}
	for(int i = 1;i <= n && l <= r;i++){
		if(a[i] != a[l] && b[i] != a[l]) swap(b[i], b[l++]);
	}
	if(l <= r) return printf("No"), 0;
	puts("Yes");
	for(int i = 1;i <= n;i++) printf("%d ", b[i]);
}