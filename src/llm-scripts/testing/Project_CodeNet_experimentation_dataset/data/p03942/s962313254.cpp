#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define N 1000006

using namespace std;

int n, ans;
char s[N], t[N];

int main(){
	scanf("%d%s%s", &n, s + 1, t + 1);
	if(strcmp(s + 1, t + 1) == 0){
		puts("0");
		return 0;
	}
	int pos = n;
	queue < int > Q;
	for(int i = n; i; --i){
		if(t[i] == t[i - 1]) continue;
		pos = min(pos, i);
		while(s[pos] != t[i] && pos) pos--;
		if(!pos){
			puts("-1");
			return 0;
		}
		while(!Q.empty()){
			int u = Q.front(), sz = Q.size();
			if(u - sz + 1 > i) Q.pop();
			else break;
		}
		Q.push(pos);
		int sz = Q.size();
		if(i != pos) ans = max(ans, sz);
	}
	cout << ans + 1 << endl;
	return 0;
}
