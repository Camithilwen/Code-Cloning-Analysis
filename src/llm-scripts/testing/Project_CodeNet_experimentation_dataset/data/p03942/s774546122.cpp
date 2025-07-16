/********************************************************************************
	
	Code by a weak man named CYJian, and he hopes the code can get more points.

	Algorithm: 

 ********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//{{{ FAST IO AND SOME FUNCTIONS
const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;

#define ge (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
#define ri read_int()
#define rl read_ll()
#define FILE(s) freopen(s"in", "r", stdin), freopen(s"out", "w", stdout)

template<typename T>
inline void read(T &x) {
	char ch, t = 0; x = 0;
	while(!isdigit(ch = ge)) t |= ch == '-';
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = ge;
	x = t ? -x : x;
}
inline int read_int() { int x; return read(x), x; }
inline ll read_ll() { ll x; return read(x), x; }

template<typename T> inline void chkmin(T&a, T b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T&a, T b) { a = a > b ? a : b; }
//}}}

const int MAXN = 1000010;

int n;
char S[MAXN];
char T[MAXN];

struct Node {
	int p, h;

	Node() {}
	Node(int p, int h):p(p), h(h) {}
};

queue<Node>q;

int main() {
#ifdef LOCAL
	FILE("");
#endif

	scanf("%d%s%s", &n, S + 1, T + 1);
	int pT = n, pS = n, res = 0, Add = 0, las = -1;
	while(pT) {
		while(pS && S[pS] != T[pT]) --pS;
		if(!pS) return puts("-1"), 0;
		while(!q.empty() && q.front().p - Add > pT) chkmax(res, q.front().h + Add), q.pop();
		if(las != pS && pS < pT) ++Add, q.push(Node(pS + Add, 1 - Add)), las = pS;
		--pT, pS -= pT < pS;
	} while(!q.empty()) chkmax(res, q.front().h + Add), q.pop();
	cout << res << endl;
	return 0;
}