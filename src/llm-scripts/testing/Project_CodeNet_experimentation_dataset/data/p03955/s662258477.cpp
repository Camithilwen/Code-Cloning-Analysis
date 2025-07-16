#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 100005;

int n, a[3][MAXN], c[MAXN];
bool b[MAXN], r[2], s[2];

inline void Ast(bool x)
{
	if (!x)
		puts("No"), exit(0);
}

inline void Modify(int x)
{
	for (; x <= n; x += x & -x)
		b[x] ^= 1;
}

inline bool Query(int x)
{
	bool r = 0;
	for (; x; x -= x & -x)
		r ^= b[x];
	return r;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 0; i < 3; i ++)
		for (int j = 1; j <= n; j ++)
			a[i][j] = Read();
	for (int i = 1; i <= n; i ++)
		if (a[0][i] > a[1][i])
		{
			Ast(a[2][i] % 3 == 1);
			Ast(a[1][i] == a[2][i] + 1);
			Ast(a[0][i] == a[1][i] + 1);
			c[i] = a[2][i] / 3;
			Ast((c[i] ^ i) & 1);
			c[i] ++;
			r[i & 1] ^= 1;
		}
		else
		{	
			Ast(a[0][i] % 3 == 1);
			Ast(a[1][i] == a[0][i] + 1);
			Ast(a[2][i] == a[1][i] + 1);
			c[i] = a[0][i] / 3;
			Ast((c[i] ^ i) & 1);
			c[i] ++;
		}
	for (int i = n - 1 + (n & 1); i > 0; i -= 2)
		s[1] ^= Query(c[i]), Modify(c[i]);
	mset(b, 0);
	for (int i = n - (n & 1); i > 0; i -= 2)
		s[0] ^= Query(c[i]), Modify(c[i]);
	Ast(s[0] == r[1] && s[1] == r[0]);
	return puts("Yes"), 0;
}
