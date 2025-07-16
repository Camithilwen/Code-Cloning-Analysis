# include <bits/stdc++.h>
using namespace std;
namespace Base{
	# define mr make_pair
	typedef long long ll;
	typedef double db;
	const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
	const ll  infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
	template<typename T> void read(T &x){
    	x = 0; int fh = 1; double num = 1.0; char ch = getchar();
		while (!isdigit(ch)){ if (ch == '-') fh = -1; ch = getchar(); }
		while (isdigit(ch)){ x = x * 10 + ch - '0'; ch = getchar(); }
	    if (ch == '.'){
	    	ch = getchar();
	    	while (isdigit(ch)){num /= 10; x = x + num * (ch - '0'); ch = getchar();}
		}
		x = x * fh;
	}
	template<typename T> void chmax(T &x, T y){x = x < y ? y : x;}
	template<typename T> void chmin(T &x, T y){x = x > y ? y : x;}
}
using namespace Base;

const int N = 2010;
int f[N][N * 3], P, ans, n;
int main(){
	read(n); read(P);
	f[0][0] = 1;
	for (int i = 0; i <= n; i++)
		for (int j = 1; j <= 3 * n; j++){
			if (j > 0) f[i][j] = (f[i][j] + f[i][j - 1]) % P;
			if (j > 1 && i > 0) f[i][j] = (f[i][j] + 1ll * f[i - 1][j - 2] * (3 * n - j + 1)) % P;
			if (j > 2 && i > 0) f[i][j] = (f[i][j] + 1ll * f[i - 1][j - 3] * (3 * n - j + 2) % P * (3 * n - j + 1)) % P;
		}
	for (int i = 0; i <= n; i++)
		ans = (ans + f[i][3 * n]) % P;
	printf("%d\n", ans);
	return 0;
}

