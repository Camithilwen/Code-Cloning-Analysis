#include <bits/stdc++.h>

#define For(i, j, k) for(int i = j; i <= k; i++)
#define Forr(i, j, k) for(int i = j; i >= k; i--)

using namespace std;

const int N = 1e6 + 10;

char S[N], T[N];
int n;
int delt[N];

int main(){
	scanf("%d%s%s", &n, S + 1, T + 1);

	bool flag = true;
	For(i, 1, n) if(S[i] ^ T[i]){
		flag = false;
		break;
	}
	if(flag){
		puts("0");
		return 0;
	}

	int ans = 0, cnt = 0, d = 0;
	int j = n;
	Forr(i, n, 1){
		cnt -= delt[i + d], delt[i + d] = 0;
		ans = max(ans, cnt + 1);
		
		//printf("%d %d %d\n", i, d, cnt);

		if(T[i] == T[i - 1]) continue;

		if(j > i) j = i;
		while(j && S[j] != T[i]) --j;
		if(!j){
			puts("-1");
			return 0;
		}

		++cnt, ++d;
		delt[j - 1 + d]++;
	}

	printf("%d\n", ans);
	return 0;
}