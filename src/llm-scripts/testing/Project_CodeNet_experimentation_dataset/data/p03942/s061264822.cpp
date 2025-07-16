#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

char S[1000010], T[1000010];
int N;
void solve(){
	scanf("%d%s%s", &N, S+1, T+1);
	if(!strcmp(S+1, T+1)){
		printf("0");
		return;
	}
	int que[1000010], *fr = que, *re = que, ans = 0;
	for(int i=N, j=N;i>=1;i--)if(T[i] != T[i-1]){
		j = min(i, j);
		while(j > 0 && S[j] != T[i])--j;
		if(j == 0){
			printf("-1");
			return;
		}
		while(re < fr && *re - (fr-re) >= i)re++;
		if(i != j){
			*fr++ = j;
			ans = max(ans, (int)(fr - re));
		}
	}
	printf("%d", ans + 1);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}