#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define mod 1000000007

template <typename T> inline void read (T &t){t = 0;char c = getchar();int f = 1;while (c < '0' || c > '9'){if (c == '-') f = -f;c = getchar();}while (c >= '0' && c <= '9'){t = (t << 3) + (t << 1) + c - '0';c = getchar();} t *= f;}
template <typename T,typename ... Args> inline void read (T &t,Args&... args){read (t);read (args...);}
template <typename T> inline void write (T x){if (x < 0){x = -x;putchar ('-');}if (x > 9) write (x / 10);putchar (x % 10 + '0');}

int N,X,Y,Z,dp[41][1 << 17];

int mul (int a,int b){return 1ll * a * b % mod;}
int dec (int a,int b){return a >= b ? a - b : a + mod - b;}
int add (int a,int b){return a + b >= mod ? a + b - mod : a + b;}
void Add (int &a,int b){a = add (a,b);}
int qkpow (int a,int b){
	int res = 1;for (;b;b >>= 1,a = mul (a,a)) if (b & 1) res = mul (res,a);
	return res;
}

signed main(){
	read (N,X,Y,Z),dp[0][0] = 1;
	int ans = 1,up = (1 << X + Y + Z) - 1,st = (1 << X + Y + Z - 1) | (1 << Y + Z - 1) | (1 << Z - 1);
	for (Int i = 1;i <= N;++ i){
		ans = 1ll * ans * 10 % mod;
		for (Int S = 0;S <= up;++ S)
			if (dp[i - 1][S] && (S & st) != st)//(S&st)!=st：如果前面还没有出现过合法解 
				for (Int c = 1;c <= 10;++ c)
					Add (dp[i][((S << c) | (1 << c - 1)) & up],dp[i - 1][S]); 
	}
	for (Int S = 0;S < (1 << X + Y + Z);++ S) if ((S & st) != st) ans = dec (ans,dp[N][S]);
	write (ans),putchar ('\n');
	return 0;
}
