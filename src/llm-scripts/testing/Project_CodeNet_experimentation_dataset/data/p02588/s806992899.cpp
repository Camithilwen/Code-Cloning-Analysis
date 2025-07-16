#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define st first
#define nd second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
template <class T> T read(T &a) {
    a=0;char x=getchar();bool f=0;
    for(;x<'0'||x>'9';x=getchar())f|=x=='-';
	for(;x>='0'&&x<='9';x=getchar())a=(a<<3)+(a<<1)+x-'0';
    if(f)a=-a;
    return a;
}
using namespace std;

typedef pair<int, int> tp;

map<tp, LL> mp;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		double a;
		scanf("%lf", &a);
		a *= 1e9;
		LL b = llround(a);
		tp k;
		k.st = k.nd = 0;
		while (b % 5 == 0) {
			b /= 5;
			k.st++;
		} 
		while (b % 2 == 0) {
			b /= 2;
			k.nd++;
		}
		mp[k]++;
	}
	map<tp, LL>::iterator i, j;
	int ci, cj;
	LL ans = 0;
	for (i = mp.begin(), ci = 0; i != mp.end(); ++i, ++ci) {
		for (j = mp.begin(), cj = 0; j != mp.end(); ++j, ++cj) {
			tp a = i->first, b = j->first;
			if (a.st + b.st >= 18 && a.nd + b.nd >= 18) {
				if (ci < cj) ans += i->second * j->second;
				if (ci == cj) ans += i->second * (i->second - 1) / 2;
			}
		}
	}
	cout << ans << endl;
    return 0;
}
