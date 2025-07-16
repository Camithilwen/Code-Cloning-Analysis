#include<bits/stdc++.h>

#define ll long long
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)

using namespace std;

typedef pair<int, int> pii;
typedef double db;
const int N = 5020;
int D, d[N], len; //d[]数组存储D的每一位数字。
ll ans, f[N][2][2]; 
//f[i][j][k]表示从低位到高位填了i位，保证合法，并且第n-i位对第n-i+1的进位贡献为j，第i位对第i+1位的进位贡献为k的方案数。 
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar();}
	while(ch >='0' && ch <='9') { x = (x<<3)+(x<<1)+(ch^48); ch = getchar();}
	return x*f;
}
ll find(int len) {
	int lim = len/2; ll res = 0;
	memset(f, 0, sizeof(f));
	f[0][0][0] = 1; 
	rep(i, 0, lim-1) rep(j, 0, 1) rep(k, 0, 1) {
		if(f[i][j][k] != 0) rep(l, 0, 9) {
			int raw = l + d[i+1] + k, num = raw%10; 
			int _k = raw/10, _j = j*10 + l - num - d[len-i];
			if(_j < 0 || _j > 1) continue;
			if(i == 0 && (l == 0 || num == 0)) continue;
			f[i+1][_j][_k] += f[i][j][k]; 
		}
	}
	if(len % 2) {
		rep(j, 0, 1) rep(k, 0, 1) {
			if(f[lim][j][k] != 0) rep(i, 0, 9) {
				int num = i + d[(len+1)/2] + k;
				if(num%10 == i && num/10 == j) res += f[lim][j][k];
			}
		}
	}
	else rep(j, 0, 1) res += f[lim][j][j];
	return res;
}
void init(){
	D = read();
	while(D) d[++len] = D%10, D /= 10; //对D的各个位数的数字分解 
	rep(i, len, 2*len) ans += find(i); //枚举n的长度，可证明n的长度不超过D的长度的二倍 
	printf("%lld\n", ans);
}
int main(){
//	freopen("input.in","r",stdin);
//	freopen("output.out","w",stdout);
	init(); 
	return 0;
}
