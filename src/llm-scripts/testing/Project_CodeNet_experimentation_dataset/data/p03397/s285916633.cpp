#include <bits/stdc++.h>
using namespace std;
inline char Get(){
	static char ch; ch = getchar();
	while (ch != '\n' && ch != '0' && ch != '1' && ch != '?') ch = getchar();
	if (ch == '\n') return '*';
	return ch;
}
const int P = 1e9 + 7;
inline void upd(int &x,int v){ x = (x+v>=P)?(x+v-P):(x+v); }
int f[9],g[9],nxt[9][2];
inline int getnxt(int s,int v){
	int cnt1 = s / 3,cnt0 = s % 3;
	if (v == 1){ if (!cnt0) cnt1 = min(2,cnt1+1); else --cnt0; }
	else{ if (cnt0 == 2) cnt0 = 0; ++cnt0; }
	return cnt1 * 3 + cnt0;
}

inline void DP(char c){
	int i;
	for (i = 0; i < 9; ++i) g[i] = f[i],f[i] = 0;
	for (i = 0; i < 9; ++i) if (g[i]){
		if (c != '1') upd(f[nxt[i][0]],g[i]);
		if (c != '0') upd(f[nxt[i][1]],g[i]);
	}
}

int main(){
	int i,j;
	for (i = 0; i < 9; ++i) for (j = 0; j < 2; ++j) nxt[i][j] = getnxt(i,j);
	f[0] = 1;
	char c; while ((c=Get())!='*') DP(c);
	int ans = 0;
	for (i = 0; i < 9; ++i) if (i / 3 >= i % 3) upd(ans,f[i]);
	cout << ans << '\n';
	return 0;
}