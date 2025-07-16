#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int f[12001];
int fi[12001];
int n, k;
int m(int a,int b){
	return (a * b)% mod;
}
int fp(int x,int y) {
	int res=1;
	while(y){
		if(y&1) res = res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int iv(int x){
	return fp(x, mod - 2);
}
int c(int x, int y){
	// chon x tu y
	return m(f[y],m(fi[x],fi[y - x]));
}
int ck(int x,int y){
	// chia x keo cho y em
	if(x < 0) return 0;
	return c(y - 1 ,x + y - 1);
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	f[0] = 1;
	for(int i = 1 ; i <= 10000 ; i ++) f[i] = m(f[i - 1], i);
	fi[10000] = iv(f[10000]);
	for(int i = 9999 ; i >= 0 ; i --) fi[i] = m(fi[i + 1], (i + 1));
	
//	int u,v;
//	while(cin >> u >> v)
//		cout << ck(u,v) << endl;
	cin >> k >> n;
	for(int i = 2 ; i <= k + k ; i ++){
		int p = 0;
		for(int j = 1 ; j <= k ; j ++){
			int _j = i - j;
			if(_j > 0 && _j != j && _j <= k) p ++;
		}
		p/= 2;
//		cout << "#i = " << i << endl;
		if(i % 2 == 1){
			int ans = 0;
			for(int q = 0; q <= p ; q ++){
//				cout << "#q = " << q << endl;
//				cout << "pair = " << c(q,p) << endl;
//				cout << "n - q = " << n - q << endl;
//				cout << "q + k - 2p = " << q + k - 2*p << endl;
//				cout << "ck = " << ck(n - q, q + k - 2*p) << endl;
				ans = (ans + m(m(c(q, p),fp(2,q)),ck(n - q, q + k - 2*p)))%mod;
			}
			cout << ans << endl;
		} else{
			int ans = 0;
			for(int q = 0; q <= p ; q ++)
				ans = (ans + m(m(c(q, p),fp(2,q)), ck(n - q - 1, q + k - 2*p - 1)))%mod;
			for(int q = 0; q <= p ; q ++)
				ans = (ans + m(m(c(q, p),fp(2,q)), ck(n - q , q + k - 2*p - 1)))%mod;
			cout << ans << endl;
		}
	}
}
