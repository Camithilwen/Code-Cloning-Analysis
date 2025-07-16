#include <bits/stdc++.h>
int n, a[205];
int main()
{
 	scanf("%d", &n);
  	for(int i=1; i<=2*n; i++) scanf("%d", a+i);
  	std::sort(a+1, a+2*n+1);
  	int ans = 0;
  	for(int i=1; i<=2*n; i+=2) ans += a[i];
  	printf("%d\n", ans);
}