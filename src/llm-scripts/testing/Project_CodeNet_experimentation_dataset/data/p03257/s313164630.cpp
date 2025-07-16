#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define pii pair<int , int>
#define mp make_pair
#define fi first
#define se second

const int MAXN = 2e5 + 10;
int pc;
int pr[MAXN] , f[MAXN];
LL A[MAXN] , B[MAXN];

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
    T f = 1; x = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
    for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    x *= f;
}

inline void G(int n) {
		for (int i = 2; i <= n; ++i) {
				if (!f[i]) f[i] = pr[++pc] = i;
				for (int j = 1; j <= pc && i * pr[j] <= n; ++j) {
						f[i * pr[j]] = pr[j];
						if (i % pr[j] == 0) break;
				}
		}
}
int main() {
		
		int n;
		scanf("%d" , &n); G(10000);
		for (int i = 1; i <= n; ++i) A[i] = pr[i & 1 ? i / 2 + 1 : n + n - i / 2 + 1];
		for (int i = 1; i <= n; ++i) B[i] = pr[(i & 1 ? n - i / 2 : n + i / 2) + (n & 1)];
		A[0] = A[n + 1] = B[0] = B[n + 1] = 1;
		for (int i = 1; i <= n; ++i , printf("\n")) 
		for (int j = 1; j <= n; ++j)
				if ((i + j) & 1) printf("%lld " , (LL) A[(i + j) / 2] * A[(i + j) / 2 + 1] * B[(n + i - j + (n & 1)) / 2] * B[(n + i - j + (n & 1)) / 2 + 1] + 1);
				else printf("%lld " , A[(i + j) / 2] * B[(n + i - j + (n & 1)) / 2]); 
	  return 0;
}