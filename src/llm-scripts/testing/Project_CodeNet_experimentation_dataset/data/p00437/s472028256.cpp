#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int p[500];

int sakurako(int a, int b, int c){
	bool f1, f2, f3;
	f1 = (p[a] == 1 ? true : false);
	f2 = (p[b] == 1 ? true : false);
	f3 = (p[c] == 1 ? true : false);
	
	if (f1 && f2 && !f3) return c;
	if (f1 && !f2 && f3) return b;
	if (!f1 && f2 && f3) return a;
	return -1;
}

int main(void)
{
	int a, b, c, n;
	int ni[1200], nj[1200], nk[1200], nr[1200];
	
	while(cin >> a >> b >> c){
		if (a == 0) break;
		cin >> n;
		
		fill(p, p + 500, 2);
		
		for (int i = 0; i < n; i++){
			scanf("%d %d %d %d", &ni[i], &nj[i], &nk[i], &nr[i]);
			if (nr[i] == 1){
				p[ni[i]] = 1;
				p[nj[i]] = 1;
				p[nk[i]] = 1;
			}
		}
		
		for (int i = 0; i < n; i++){
			if (nr[i] == 0){
				int re = sakurako(ni[i], nj[i], nk[i]);
				if (re == -1) continue;
				p[re] = 0;
			}
		}
		
		for (int i = 1; i <= a + b + c; i++){
			printf("%d\n", p[i]);
		}
	}
	
	return 0;
}