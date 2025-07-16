#include<bits/stdc++.h>
#define	INF	0x3f3f3f3f
#define	LL	long long
#define	MAXN	310
#define	mod	998244353
using namespace std;
int n, f[2][MAXN * MAXN / 2], sum, a[MAXN], ans;

template <typename T> void chkmin(T &x, T y){x = min(x, y);}
template <typename T> void chkmax(T &x, T y){x = max(x, y);}
template <typename T> void read(T &x){
	x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}

int mul(const int &x, const int &y){return 1ll * x * y % mod;}
int inc(const int &x, const int &y){return (x + y >= mod) ? (x + y - mod) : (x + y);}
void update(int &x, const int &y){x = (x + y >= mod) ? (x + y - mod) : (x + y);}
int dec(const int &x, const int &y){return (x - y < 0) ? (x - y + mod) : (x - y);}

int qpow(int a, int b){
	int ret = 1;
	while (b) {
		if (b & 1) ret = mul(ret, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ret;
}

int main(){
	read(n);
	for (int i = 1; i <= n; ++i)
		read(a[i]), sum += a[i];
	int cur = 0, old = 1;
	f[cur][0] = 1;
	for (int i = 1; i <= n; ++i){
		swap(cur, old);
		memset(f[cur], 0, sizeof(f[cur]));
		for (int j = 0; j <= sum / 2; ++j){
			if (!f[old][j]) continue;
			int tmp = f[old][j];
			if (j + a[i] <= sum / 2) update(f[cur][j + a[i]], mul(tmp, 2));
			update(f[cur][j], tmp);
		}
		/*for (int j = 0; j <= sum / 2; ++j)
			printf("%d ", f[cur][j]);
		puts("");*/
	}
	for (int i = 0; i <= sum / 2; ++i)
		update(ans, f[cur][i]);
	//printf("%d\n\n", ans);
	ans = mul(ans, 3);
	ans = dec(qpow(3, n), ans);
	if (!(sum & 1)){
		memset(f, 0, sizeof(f));
		int cur = 0, old = 1;
		f[cur][0] = 1;
		for (int i = 1; i <= n; ++i){
			swap(cur, old);
			memset(f[cur], 0, sizeof(f[cur]));
			for (int j = 0; j <= sum / 2; ++j){
				if (!f[old][j]) continue;
				int tmp = f[old][j];
				if (j + a[i] <= sum / 2) update(f[cur][j + a[i]], tmp);
				update(f[cur][j], tmp);
			}
		}
		ans = inc(ans, mul(f[cur][sum / 2], 3));
	}
	printf("%d\n", ans);
	return 0;
}